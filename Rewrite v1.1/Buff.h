#pragma once
#include"header.h"
#include"Entity.h"

/*
	增益与减益
*/

class Buff
{
private:
	std::string name;						//名字
	bool stackable;							//是否可叠加
	bool isBuff;							//增益或者减益
	int level = 0;							//buff等级
	void(*effect)(Entity&self, Entity&aim);	//效果

	explicit Buff();
public:
	/* 增加新类型buff */			//不需要写等级
	Buff(const std::string & Name, const bool Stackable, const bool IsBuff, void(*Effect)(Entity &self, Entity &aim))
		:name(Name), stackable(Stackable), isBuff(IsBuff), effect(Effect)
	{
	}
	/* 单位获得buff */			//用于pushback时，需要写等级
	Buff(const std::string & Name, const bool Stackable, const bool IsBuff, int Level, void(*Effect)(Entity &self, Entity &aim))
		:name(Name), stackable(Stackable), isBuff(IsBuff), level(Level), effect(Effect)
	{
	}
	Buff(const Buff&copy)
		:name(copy.name), stackable(copy.stackable), isBuff(copy.isBuff), level(copy.level), effect(copy.effect)
	{
	}
	~Buff() = default;

	Buff&operator=(const Buff&copy);

	/*********************	返回成员数据	*********************/

	const std::string&Name()const { return name; }
	bool Stackable()const { return stackable; }
	bool IsBuff()const { return isBuff; }
	int Level()const { return level; }

	/*********************	其他特殊方法	*********************/

	/* 更新状态等级 */
	Buff&update(int Level);

	/* 触发状态效果 */
	//一般状态对自身起效，例如力量增加，只制定效果对象
	Buff&trigger(Entity&aim);
	//特殊状态对对手起效，例如荆棘反伤，同时指定效果源和效果对象
	Buff&trigger(Entity&self, Entity&aim);

	/* 同名Buff */
	bool operator==(const Buff&aim);
};
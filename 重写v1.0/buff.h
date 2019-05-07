#pragma once
#include"entity.h"

class Buff
{
private:
	string name;				//名字
	bool stackable;				//是否可叠加
	int level = 0;				//buff等级
	void(*effect)(Entity&self, Entity&aim);	//效果

	explicit Buff();
public:
	Buff(const string & Name, const bool Stackable, void(*Effect)(Entity &self, Entity &aim))
		:name(Name), stackable(Stackable), effect(Effect)
	{
	}
	Buff(const Buff&copy)
		:name(copy.name), stackable(copy.stackable), level(copy.level), effect(copy.effect)
	{
	}
	~Buff() = default;

	Buff&operator=(const Buff&copy);
};
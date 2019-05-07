#pragma once
#include"entity.h"

/* 道具 */
class Item
{
private:
	string name;		//名字
	bool stackable;		//是否可叠加
	void(*effect)(Entity&self, Entity&aim);	//效果
	bool(*condition)();	//使用条件
public:
	Item() = default;
	Item(const string&Name, const bool Stackable, bool(*Condition)(), void(*Effect)(Entity&self, Entity&aim))
		:name(Name), stackable(Stackable), effect(Effect),condition(Condition)
	{
	}
	Item(const Item&copy)
		:name(copy.name), stackable(copy.stackable), effect(copy.effect), condition(copy.condition)
	{
	}
	~Item() = default;

	Item&operator=(const Item&copy);

	/******************************************/

	/* 对比物品 */
	bool operator==(const Item&aim);

	/* 返回名字 */
	const string&Name()const;

	/* 返回是否可叠加 */
	bool Stackable()const;

	/* 使用道具 */		//道具可能有使用条件，故分与效果开写
	bool useTo(Entity&aim)const;
};
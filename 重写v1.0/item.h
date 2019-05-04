#pragma once
#include"header.h"

class item
{
private:
	string name;		//名字
	bool stackable;		//是否可叠加
	void(*effect)();	//效果
	bool(*condition)();	//使用条件

	explicit item();
public:
	item(const string&Name, const bool Stackable, bool(*Condition)(), void(*Effect)())
		:name(Name), stackable(Stackable), effect(Effect),condition(Condition)
	{
	}
	~item() = default;

	/* 返回名字 */
	const string&Name()const;

	/* 返回是否可叠加 */
	bool Stackable()const;

	/* 使用道具 */		//道具可能有使用条件，故分与效果开写
	bool use()const;
};
#pragma once
#include"header.h"

/* 技能类别 */
typedef enum skillType { Attack, Defence, Treat, Other }ST;

class Skill
{
private:
	string name;		//名
	ST type;			//类型
	union _value {
		int atk;			//伤害
		int def;			//格挡
		int treat;			//治疗值
	}value;
	int energy;			//消耗能量
	void(*effect)();	//效果


	bool(*condition)();		//使用条件		比如用过弱水三千后无法使用治疗类技能
	

	explicit Skill();
public:
	Skill(const char*Name, ST Type, int Val, int Energy, bool(*Condition)(), void(*Effect)());
	Skill(const Skill&copy);
	~Skill() = default;
	Skill&operator=(const Skill&copy);

	/******************************************/

	/* 返回技能名 */
	const string&Name()const;

	/* 返回技能类型 */
	const string&Type()const;

	/* 返回value */
	int Value()const;

	/* 返回消耗能量 */
	int Energy()const;

	/******************************************/

	/* 技能是否可用 */
	bool Usable()const;

	/* 使用技能 */
	bool use()const;
};
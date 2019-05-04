#pragma once
#include"header.h"

typedef enum skillType { Attack, Defence, Treat, Other }ST;

class skill
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
	void(*effect)();	//特殊效果

	explicit skill();
public:
	skill(const char*Name, ST Type, int Val, int Energy, void(*Effect)());
	~skill() = default;

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

	/* 使用技能 */
	bool use()const;
};

extern vector<skill>playerSkill;
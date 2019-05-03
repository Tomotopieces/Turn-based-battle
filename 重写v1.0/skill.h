#pragma once
#include"header.h"

typedef enum skillType ST;
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
	skill(string&Name, ST Type, int Val, int Energy, void(*Effect)());

	/******************************************/

	/* 显示技能名 */
	const string&Name()const;

	/* 显示技能类型 */
	const string&Type()const;

	/* 显示伤害 */
	int Atk()const;

	/* 显示格挡 */
	int Def()const;

	/* 显示治疗值 */
	int Trt()const;

	/* 显示消耗能量 */
	int Energy()const;

	/******************************************/

	/* 使用技能 */
	bool use()const;
};
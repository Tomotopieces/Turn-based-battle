#pragma once
#include"header.h"

class Entity
{
private:
	std::string name;		//名字啦

	int hp;					//固有生命值
	int currentHp = 0;		//当前生命值
	int mp;					//固有生命值
	int currentMp = 0;		//当前生命值
	int atk;				//固有攻击力
	int currentAtk = 0;		//当前攻击力
	int def;				//固有防御力
	int currentDef = 0;		//当前防御力
	int currentBlock = 0;	//格挡值

	int coin;				//金币
	int level;				//等级
	int exp;				//目前经验
	int maxExp = 20;		//升级所需经验值

	std::string img;		//角色图像

	explicit Entity();		//禁用默认构造
public:
	Entity(const std::string&Name, const int Hp, const int Mp, const int Atk, const int Def, const int Coin, const int Level, const int Exp, const std::string Img)
		:name(Name), hp(Hp), atk(Atk), def(Def), coin(Coin), level(Level), exp(Exp), img(Img)
	{}
	/* 创建相同面板不同名字的单位 */		//用于多存档与相似敌人
	Entity(const std::string&Name, const Entity&copy)
		:name(Name), hp(copy.hp), atk(copy.atk), def(copy.def), coin(copy.coin), level(copy.level), exp(copy.exp), img(copy.img)
	{}
	Entity(const Entity&copy)
		:name(copy.name), hp(copy.hp), atk(copy.atk), def(copy.def), coin(copy.coin), level(copy.level), exp(copy.exp), img(copy.img)
	{}
	~Entity() = default;

	Entity&operator=(const Entity&copy);

	/*********************	返回成员数据	*********************/

	const std::string&Name()const { return name; }

	int Hp()const { return hp; }
	int CurrentHp()const { return currentHp; }
	int Mp()const { return mp; }
	int CurrentMp()const { return currentMp; }
	int Atk()const { return atk; }
	int CurrentAtk()const { return currentAtk; }
	int Def()const { return def; }
	int CurrentDef()const { return currentDef; }
	int CurrentBlock()const { return currentBlock; }

	int Coin()const { return coin; }
	int Level()const { return level; }
	int Exp()const { return exp; }
	int MaxExp()const { return maxExp; }

	const std::string&Img()const { return img; }

	/*********************	更新成员数据	*********************/

	Entity&updateName(const std::string&newName) { name = newName; return*this; }

	Entity&updateHp(int newHp) { hp = newHp; return*this; }
	Entity&updateCurrentHp(int newCurrentHp) { currentHp = newCurrentHp; return*this; }
	Entity&updateMp(int newMp) { mp = newMp; return*this; }
	Entity&updateCurrentMp(int newCurrentMp) { currentMp = newCurrentMp; return*this; }
	Entity&updateAtk(int newAtk) { atk = newAtk; return*this; }
	Entity&updateCurrentAtk(int newCurrentAtk) { currentAtk = newCurrentAtk; return*this; }
	Entity&updateDef(int newDef) { def = newDef; return*this; }
	Entity&updateCurrentDef(int newCurrentDef) { currentDef = newCurrentDef; return*this; }
	Entity&updateCurrentBlock(int newCurrentBlock) { currentBlock = newCurrentBlock; return*this; }

	Entity&updateCoin(int newCoin) { coin = newCoin; return*this; }
	Entity&levelUp();
		//更新level时连带更新maxExp
	Entity&updateExp(int newExp) { exp = newExp; return*this; }

		//img不更新
};
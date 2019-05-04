#pragma once
#include"header.h"

enum buff { Normal, OnFire, Undefeatable, CantTreat, Wound };//似乎不能用写在cpp里然后在这里extern的做法

/* 单位 */
class entity
{
private:
	string name;		//名字啦

	int hp;				//固有生命值
	int currentHp = 0;		//当前生命值
	int mp;				//固有生命值
	int currentMp = 0;		//当前生命值
	int atk;			//固有攻击力
	int currentAtk = 0;		//当前攻击力
	int def;			//固有防御力
	int currentDef = 0;		//当前防御力
	int currentBlock = 0;		//格挡值
	struct Buff
	{
		buff name;
		int level;
	};
	vector<Buff>buffList;	//buff表

	int coin;			//金币
	int lvl;			//等级
	int exp;			//目前经验
	int maxExp = 20;	//升级所需经验值

	string img;			//角色图像

	explicit entity();	//禁用默认构造
public:
	entity(const string&Name, const int Hp, const int Mp, const int Atk, const int Def, const int Coin, const int Lvl, const int Exp, const string Img)
		:name(Name), hp(Hp), atk(Atk), def(Def), coin(Coin), lvl(Lvl), exp(Exp), img(Img)
	{}
	/* 创建相同面板不同名字的单位 */		//用于多存档与相似敌人
	entity(const string&Name, const entity&copy)
		:name(Name), hp(copy.hp), atk(copy.atk), def(copy.def), coin(copy.coin), lvl(copy.lvl), exp(copy.exp), img(copy.img)
	{}
	entity(const entity&copy)
		:name(copy.name), hp(copy.hp), atk(copy.atk), def(copy.def), coin(copy.coin), lvl(copy.lvl), exp(copy.exp), img(copy.img)
	{}
	~entity() = default;

	entity&operator=(const entity&copy);

	/******************************************/

	/* 返回名字 */
	const string&Name()const;

	/* 重命名 */
	entity&Rename(const string&Name);

	/* 战斗前数据初始化 */
	entity&Init();

	/******************************************/

	/* 更新固有生命值 */
	entity&updateHp(const int val);

	/* 更新当前生命值 */
	entity&updateCurrentHp(const int val);

	/* 返回固有生命值 */
	int Hp()const;

	/* 返回当前生命值 */
	int CurrentHp()const;

	/******************************************/

	/* 更新固有能量值 */
	entity&updateMp(const int val);

	/* 更新当前能量值 */
	entity&updateCurrentMp(const int val);

	/* 返回固有能量值 */
	int Mp()const;

	/* 返回当前能量值 */
	int CurrentMp()const;

	/******************************************/

	/* 更新固有攻击力 */
	entity&updateAtk(const int val);

	/* 更新当前攻击力 */		//一般是嗑药或者技能产生的buff
	entity&updateCurrentAtk(const int val);

	/* 返回固有攻击力 + 武器攻击力 */
	int Atk()const;

	/* 返回当前攻击力 */
	int CurrentAtk()const;

	/******************************************/

	/* 更新固有防御力 */
	entity&updateDef(const int val);

	/* 更新当前防御力 */
	entity&updateCurrentDef(const int val);

	/* 更新当前格挡值 */
	entity&updateCurrentBlock(const int val);

	/* 清空防御 */
	entity&ClrBlk();

	/* 返回固有防御力 */
	int Def()const;

	/* 返回当前防御力 */
	int CurrentDef()const;

	/* 返回格挡值 */
	int CurrentBlock()const;

	/******************************************/

	/* 获得buff */
	entity&GetBuff(buff name, int level);

	/* 回合结束时更新buff表 */
	entity&updateBuffListOnTurnEnd();

	/* 一次行动结束时更新buff表 */
	entity&updateBuffListOnActionEnd();

	/* 检索buff */
	bool findBuff(buff name)const;

	/******************************************/

	/* 更新金币数 */
	entity&updateCoin(const int inc);

	/* 显示金币数 */
	int Coin()const;

	/******************************************/

	/* 更新经验值 */
	entity&updateExp(const int val);

	/* 显示经验值 */
	int Exp()const;

	/******************************************/

	/* 更新等级 */
	entity&lvlUp();

	/* 返回等级 */
	int Lvl()const;

	/******************************************/

	/* 返回Max经验值 */
	int MaxExp()const;

	/******************************************/

	/* 返回图案 */
	const string&Img()const;
};

//起名规则（来自蛋友）
/*
	大家的变量/函数名是怎么起的？
	刚写到两个类的方法：在回合结束时更新buff列表/在行动结束时更新buff列表
	因为一回合会有多个行动，并且更新的buff也不一样，所以分开写，然后起名字就···
	updBuffList_endTurn()和updBuffList_endAction()
	目前还是个菜学生，没写过什么大项目，感觉这样的函数名十分繁琐···虽然VS的自动补齐很好用就是了···
	是真的太繁琐了还是说一般的变量/函数名都这么长？

多巴胺：
	我的话会用 updateBuffOnTurnEnd() updateBuffOnActionEnd()。
	名字长无所谓，又不是用记事本写代码，体现函数的作用最重要。可以不用描述数据结构，除非还有updateBuffMap之类的。也不要用不通用的缩写，老老实实写update

斯丁：
	搞java和python的想跟你说，命名要么都驼峰，要么都下划线。混用看上去不舒服。
	java里面的方法、变量名都有点长。
*/
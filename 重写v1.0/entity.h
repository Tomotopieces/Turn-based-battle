#pragma once
#include"header.h"

enum buff;

/* 单位 */
class entity
{
private:
	string name;		//名字啦

	int hp;				//固有生命值
	int hp_c = 0;		//当前生命值
	int mp;				//固有生命值
	int mp_c = 0;		//当前生命值
	int atk;			//固有攻击力
	int atk_c = 0;		//当前攻击力
	int def;			//固有防御力
	int def_c = 0;		//当前防御力
	int block = 0;		//格挡值
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

	/* 显示名字 */
	const string&Name()const;

	/* 重命名 */
	entity&Rename(const string&Name);

	/* 战斗前数据初始化 */
	entity&Init();

	/******************************************/

	/* 更新固有生命值 */
	entity&updHp(const int val);

	/* 更新当前生命值 */
	entity&updHp_c(const int val);

	/* 显示固有生命值 */
	int Hp()const;

	/* 显示当前生命值 */
	int Hp_c()const;

	/******************************************/

	/* 更新固有能量值 */
	entity&updMp(const int val);

	/* 更新当前能量值 */
	entity&updMp_c(const int val);

	/* 显示固有能量值 */
	int Mp()const;

	/* 显示当前能量值 */
	int Mp_c()const;

	/******************************************/

	/* 更新固有攻击力 */
	entity&updAtk(const int val);

	/* 更新当前攻击力 */		//一般是嗑药或者技能产生的buff
	entity&updAtk_c(const int val);

	/* 显示固有攻击力 + 武器攻击力 */
	int Atk()const;

	/* 显示当前攻击力 */
	int Atk_c()const;

	/******************************************/

	/* 更新固有防御力 */
	entity&updDef(const int val);

	/* 更新当前防御力 */
	entity&updDef_c(const int val);

	/* 更新当前格挡值 */
	entity&updBlk_c(const int val);

	/* 清空防御 */
	entity&ClrBlk();

	/* 显示固有防御力 */
	int Def()const;

	/* 显示当前防御力 */
	int Def_c()const;

	/* 显示格挡值 */
	int Blk_c()const;

	/******************************************/

	/* 获得buff */
	entity&GetBuff(buff name, int level);

	/* 回合结束时更新buff表 */
	entity&updBuffList_endTurn();

	/* 一次行动结束时更新buff表 */
	entity&updBuffList_endAction();

	/******************************************/

	/* 更新金币数 */
	entity&updCoin(const int inc);

	/* 显示金币数 */
	int Coin()const;

	/******************************************/

	/* 更新经验值 */
	entity&updExp(const int val);

	/* 显示经验值 */
	int Exp()const;

	/******************************************/

	/* 更新等级 */
	entity&lvlUp();

	/* 显示等级 */
	int Lvl()const;

	/******************************************/

	/* 显示Max经验值 */
	int MaxExp()const;

	/******************************************/

	/* 显示图案 */
	const string&Img()const;
};

extern entity proto;
extern entity player;
extern entity enemys[];
extern entity enemy;
#include "entity.h"



entity & entity::operator=(const entity & copy)
{
	if (&copy == this)
		return*this;
	name = copy.name;
	hp = copy.hp;
	atk = copy.atk;
	def = copy.def;
	coin = copy.coin;
	lvl = copy.lvl;
	exp = copy.exp;
	img = copy.img;
	return*this;
}

const string & entity::Name() const
{
	return name;
}

entity & entity::Rename(const string & Name)
{
	name = Name;
	return *this;
}

entity & entity::Init()
{
	currentHp = hp;
	currentAtk = atk/* + weapon.atk */;
	currentBlock = 0;
	return*this;
}

entity & entity::updateHp(const int val)
{
	hp = val;
	return *this;
}

entity & entity::updateCurrentHp(const int val)
{
	currentHp = val;
	return *this;
}

int entity::Hp() const
{
	return hp;
}

int entity::CurrentHp() const
{
	return currentHp;
}

entity & entity::updateMp(const int val)
{
	mp = val;
	return *this;
}

entity & entity::updateCurrentMp(const int val)
{
	currentMp = val;
	return *this;
}

int entity::Mp() const
{
	return mp;
}

int entity::CurrentMp() const
{
	return currentMp;
}

entity & entity::updateAtk(const int val)
{
	atk = val;
	return *this;
}

entity & entity::updateCurrentAtk(const int val)
{
	currentAtk = val;
	return *this;
}

int entity::Atk() const
{
	return atk;
}

int entity::CurrentAtk() const
{
	return currentAtk;
}

entity & entity::updateDef(const int val)
{
	def = val;
	return*this;
}

entity & entity::updateCurrentDef(const int val)
{
	currentDef = val;
	return*this;
}

entity & entity::updateCurrentBlock(const int val)
{
	currentBlock = val;
	return*this;
}

entity & entity::ClrBlk()
{
	currentBlock = 0;
	return*this;
}

int entity::Def() const
{
	return def;
}

int entity::CurrentDef() const
{
	return currentDef;
}

int entity::CurrentBlock() const
{
	return currentBlock;
}

entity & entity::GetBuff(buff name, int level)
{
	buffList.push_back({ name,level });
	return*this;
}

entity & entity::updateBuffList_endTurn()
{
	for (auto it = buffList.begin(); it != buffList.end(); ++it) {
		switch (it->name) {
			//着火
			case OnFire:
				it->level--;
				break;
			default:
				break;
		}
	}
	return*this;
}

entity & entity::updateBuffList_endAction()
{
	for (auto it = buffList.begin(); it != buffList.end(); ++it) {
		switch (it->name) {
			//伤口
			case Wound:
				//0.1概率伤口爆发
				if (rand() % 5)
					it->level++;
				else
					player.updateCurrentHp(player.CurrentHp() - it->level);
				buffList.erase(it);
				it--;
				break;
			default:
				break;
		}
	}
	return*this;
}

bool entity::findBuff(buff name) const
{
	for (auto it = buffList.begin(); it != buffList.end(); ++it) {
		if (name == it->name)
			return true;
	}
	return false;
}

entity & entity::updateCoin(const int inc)
{
	coin += inc;
	return*this;
}

int entity::Coin() const
{
	return coin;
}

entity & entity::updateExp(const int val)
{
	exp = val;
	return*this;
}

int entity::Exp() const
{
	return exp;
}

entity & entity::lvlUp()
{
	lvl++;
	return*this;
}

int entity::Lvl() const
{
	return lvl;
}

int entity::MaxExp() const
{
	int ME = 20;
	for (int i = 1; i < lvl; ++i) {
		ME += (i + 1) * 10;
	}
	return ME;
}

const string & entity::Img() const
{
	return img;
}

/******************************************/

//原型机
entity proto
{ "NULL",20,0,1,1,10,1,0,
"     ╱ ╲     ╱ ╲n     ╲   ╲ ╱ ╱ ╱n     ╱ ╲ ╱ ╲ ╱n   ╱╱    ╲ ╱ ╲n ╱╱        ╲   ╲n││         ╱ ╲ ╱n││       ╱n││     ╱n││   ╱n││ ╱n│╱n"
};
entity player = proto;

//敌人
entity enemys[]
{
	{ "魔王",50,0,3,2,50,99,100,
	"│╲                       ╱│n│ │                     │ │n│ │      __      __     │ │n│  ╲ __╱   ╲ __╱   ╲ __╱  │n ╲ ____              ____╱n      │      ║      │n       ╲     ║     ╱n        │    ╬    │n         ╲   __  ╱n          │ │ │ │n           ╲│ │╱n"
	},
	{ "小偷",20,0,1,1,5,1,10,
	"     ╱ ╲     ╱ ╲n     ╲   ╲ ╱ ╱ ╱n     ╱ ╲ ╱ ╲ ╱n   ╱╱    ╲ ╱ ╲n ╱╱        ╲   ╲n││         ╱ ╲ ╱n││       ╱n││     ╱n││   ╱n││ ╱n│╱n"
	},
	{"食堂泼辣酱",99,0,99,99,1000,999,1000,
	"          __ n    __  __╲ ╲ n    ╲ ╲ ╲ ╲│ │╱│ __ n __│╲│ │ │    ╱  ╲ ╲ n ╲ ╲╲_╲ ╲│ │ │  _╱ ╱ n   ╲  ╲│  ╱  │╱  ╱ n    │──── []────│ n    │ ┗━━   ━━┛ │ n    │  ╘═   ═╛  │ n    │╲         ╱│ n    │ │   __  │ │ n     ╲ ╲ ____╱ ╱ n       ╲│ __│╱ n"
	}
};
entity enemy = proto;
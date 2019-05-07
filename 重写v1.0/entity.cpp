#include "Entity.h"
#include"entityList.h"

Entity & Entity::operator=(const Entity & copy)
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

const string & Entity::Name() const
{
	return name;
}

Entity & Entity::Rename(const string & Name)
{
	name = Name;
	return *this;
}

Entity & Entity::Init()
{
	currentHp = hp;
	currentAtk = atk/* + weapon.atk */;
	currentBlock = 0;
	return*this;
}

Entity & Entity::updateHp(const int val)
{
	hp = val;
	return *this;
}

Entity & Entity::updateCurrentHp(const int val)
{
	currentHp = val;
	return *this;
}

int Entity::Hp() const
{
	return hp;
}

int Entity::CurrentHp() const
{
	return currentHp;
}

Entity & Entity::updateMp(const int val)
{
	mp = val;
	return *this;
}

Entity & Entity::updateCurrentMp(const int val)
{
	currentMp = val;
	return *this;
}

int Entity::Mp() const
{
	return mp;
}

int Entity::CurrentMp() const
{
	return currentMp;
}

Entity & Entity::updateAtk(const int val)
{
	atk = val;
	return *this;
}

Entity & Entity::updateCurrentAtk(const int val)
{
	currentAtk = val;
	return *this;
}

int Entity::Atk() const
{
	return atk;
}

int Entity::CurrentAtk() const
{
	return currentAtk;
}

Entity & Entity::updateDef(const int val)
{
	def = val;
	return*this;
}

Entity & Entity::updateCurrentDef(const int val)
{
	currentDef = val;
	return*this;
}

Entity & Entity::updateCurrentBlock(const int val)
{
	currentBlock = val;
	return*this;
}

Entity & Entity::clearBlock()
{
	currentBlock = 0;
	return*this;
}

int Entity::Def() const
{
	return def;
}

int Entity::CurrentDef() const
{
	return currentDef;
}

int Entity::CurrentBlock() const
{
	return currentBlock;
}

Entity & Entity::GetBuff(buff name, int level)
{
	if (0 == level) {
		if (findBuff(name)) {
			for (auto it = buffList.begin(); it != buffList.end(); ++it) {
				if (name == it->name) {
					buffList.erase(it);
					return*this;
				}
			}
		}
		else
			return*this;
	}
	buffList.push_back({ name,level });
	return*this;
}

Entity & Entity::updateBuffListOnTurnEnd()
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

Entity & Entity::updateBuffListOnActionEnd()
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

bool Entity::findBuff(buff name) const
{
	for (auto it = buffList.begin(); it != buffList.end(); ++it) {
		if (name == it->name)
			return true;
	}
	return false;
}

Entity & Entity::updateCoin(const int inc)
{
	coin += inc;
	return*this;
}

int Entity::Coin() const
{
	return coin;
}

Entity & Entity::updateExp(const int val)
{
	exp = val;
	return*this;
}

int Entity::Exp() const
{
	return exp;
}

Entity & Entity::lvlUp()
{
	lvl++;
	return*this;
}

int Entity::Lvl() const
{
	return lvl;
}

int Entity::MaxExp() const
{
	int ME = 20;
	for (int i = 1; i < lvl; ++i) {
		ME += (i + 1) * 10;
	}
	return ME;
}

const string & Entity::Img() const
{
	return img;
}
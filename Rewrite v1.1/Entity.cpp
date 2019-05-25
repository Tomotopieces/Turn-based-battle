#include "Entity.h"

Entity & Entity::operator=(const Entity & copy)
{
	if (this == &copy)
		return*this;
	name = copy.name;

	hp = copy.hp;
	mp = copy.mp;
	atk = copy.atk;
	def = copy.def;

	coin = copy.coin;
	level = copy.level;
	exp = copy.exp;
	maxExp = copy.maxExp;

	img = copy.img;

	return*this;
}

Entity & Entity::levelUp()
{
	++level;
	maxExp += level * 10;
}

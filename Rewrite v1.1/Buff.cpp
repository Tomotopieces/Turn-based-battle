#include "Buff.h"

Buff & Buff::operator=(const Buff & copy)
{
	if (&copy == this)
		return*this;
	name = copy.name;
	stackable = copy.stackable;
	isBuff = copy.isBuff;
	level = copy.level;
	effect = copy.effect;
	return*this;
}

Buff & Buff::update(int Level)
{
	if (0 == Level)
		level = 0;
	else if (stackable)
		level += Level;
	return*this;
}

Buff & Buff::trigger(Entity & aim)
{
	effect(aim, aim);
	return*this;
}

Buff & Buff::trigger(Entity & self, Entity & aim)
{
	effect(self, aim);
	return*this;
}
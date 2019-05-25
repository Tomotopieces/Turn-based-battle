#include "buff.h"

Buff & Buff::operator=(const Buff & copy)
{
	if (&copy == this)
		return*this;
	name = copy.name;
	stackable = copy.stackable;
	level = copy.level;
	effect = copy.effect;
	return*this;
}

const string & Buff::Name()
{
	return name;
}

bool Buff::Stackable()
{
	return stackable;
}

int Buff::Level()
{
	return level;
}

Buff & Buff::update(int Level)
{
	level = Level;
	return*this;
}

Buff & Buff::trigger(Entity & self, Entity & aim)
{
	effect(self, aim);
	return*this;
}

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

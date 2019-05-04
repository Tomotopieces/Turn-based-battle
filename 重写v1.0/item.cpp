#include "item.h"

Item & Item::operator=(const Item & copy)
{
	if (this == &copy)
		return*this;
	name = copy.name;
	stackable = copy.stackable;
	effect = copy.effect;
	condition = copy.condition;
	return*this;
}

bool Item::operator==(const Item & opponent)
{
	return name == opponent.name;
}

const string & Item::Name() const
{
	return name;
}

bool Item::Stackable() const
{
	return stackable;
}

bool Item::use() const
{
	if (!condition())
		return false;
	effect();
	return true;
}

#include "item.h"
#include"entityList.h"

Item & Item::operator=(const Item & copy)
{
	if (&copy == this)
		return*this;
	name = copy.name;
	stackable = copy.stackable;
	effect = copy.effect;
	condition = copy.condition;
	return*this;
}

bool Item::operator==(const Item & aim)
{
	return name == aim.name;
}

const string & Item::Name() const
{
	return name;
}

bool Item::Stackable() const
{
	return stackable;
}

bool Item::useTo(Entity&aim) const
{
	if (!condition())
		return false;
	effect(player, aim);
	return true;
}

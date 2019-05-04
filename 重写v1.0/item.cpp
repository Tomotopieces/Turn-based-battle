#include "item.h"

const string & item::Name() const
{
	return name;
}

bool item::Stackable() const
{
	return stackable;
}

bool item::use() const
{
	if (!condition())
		return false;
	use();
	return true;
}

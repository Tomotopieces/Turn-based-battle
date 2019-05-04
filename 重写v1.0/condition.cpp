#include"condition.h"
#include"entityList.h"

bool NOCONDITION()
{
	return true;
}

bool CANTREAT()
{
	if (player.findBuff(CantTreat))
		return false;
	else
		return true;
}
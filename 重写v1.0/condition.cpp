#include"condition.h"
#include"entityList.h"

bool NOCONDITION()
{
	return true;
}

bool CANTREAT()
{
	return !player.findBuff(CantTreat);
}

bool LEASTLEVEL(int n)
{
	return player.Lvl() >= n;
}
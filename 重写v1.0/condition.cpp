#include"condition.h"
#include"entityList.h"
#include"Slot.h"

bool NOCONDITION()
{
	return true;
}

bool CANTREAT()
{
	return !player.findBuff(CantTreat);
}

bool USINGSWORD()
{
	return Sword == slot.weaponSlot().WeaponType();
}

bool LEASTLEVEL(int n)
{
	return player.Lvl() >= n;
}
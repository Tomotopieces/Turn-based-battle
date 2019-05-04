#include "itemList.h"
#include"entity.h"

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

void LIFEPOTION()
{
	if (player.CurrentHp() + 3 < player.Hp())
		player.updateCurrentHp(player.CurrentHp() + 3);
	else
		player.updateCurrentHp(player.Hp());
}

void ENERGYPOTION()
{
	if (player.CurrentMp() + 5 < player.Mp())
		player.updateCurrentMp(player.CurrentMp() + 5);
	else
		player.updateCurrentMp(player.Mp());
}

void POWERPOTION()
{
	//×î´ó¹¥»÷Á¦999
	if (player.CurrentAtk() + 1 < 999)
		player.updateCurrentAtk(player.CurrentAtk() + 1);
	else
		player.updateCurrentAtk(999);
}

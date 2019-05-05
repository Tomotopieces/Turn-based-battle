#include "itemList.h"

void LIFEPOTION(Entity&self, Entity&aim)
{
	if (aim.CurrentHp() + 3 < aim.Hp())
		aim.updateCurrentHp(aim.CurrentHp() + 3);
	else
		aim.updateCurrentHp(aim.Hp());
}

void ENERGYPOTION(Entity&self, Entity&aim)
{
	if (aim.CurrentMp() + 5 < aim.Mp())
		aim.updateCurrentMp(aim.CurrentMp() + 5);
	else
		aim.updateCurrentMp(aim.Mp());
}

void POWERPOTION(Entity&self, Entity&aim)
{
	//×î´ó¹¥»÷Á¦999
	if (aim.CurrentAtk() + 1 < 999)
		aim.updateCurrentAtk(aim.CurrentAtk() + 1);
	else
		aim.updateCurrentAtk(999);
}

#include"skillList.h"
#include"entity.h"

void HIT()
{
	if (player.CurrentAtk() >= enemy.CurrentBlock())
		enemy.updateCurrentHp(enemy.CurrentHp() + enemy.CurrentBlock() - player.CurrentAtk());
}

void BLOCK()
{
	player.updateCurrentBlock(player.CurrentDef());
}

void FIREBALL()
{
	player.updateCurrentAtk(player.CurrentAtk() + FireBall.Value());
	HIT();
	player.updateCurrentAtk(player.CurrentAtk() - FireBall.Value());
}

void FIREWALL()
{
	player.updateCurrentDef(player.CurrentDef() + FireWall.Value());
	BLOCK();
	player.updateCurrentDef(player.CurrentDef() - FireWall.Value());
}
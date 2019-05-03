#include"skillList.h"
#include"entity.h"

void HIT()
{
	if (player.Atk_c() >= enemy.Blk_c())
		enemy.updHp_c(enemy.Hp_c() + enemy.Blk_c() - player.Atk_c());
}

void BLOCK()
{
	player.updBlk_c(player.Def_c());
}

void FIREBALL()
{
	player.updAtk_c(player.Atk_c() + FireBall.Value());
	HIT();
	player.updAtk_c(player.Atk_c() - FireBall.Value());
}

void FIREWALL()
{
	player.updDef_c(player.Def_c() + FireWall.Value());
	BLOCK();
	player.updDef_c(player.Def_c() - FireWall.Value());
}
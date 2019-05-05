#include"skillList.h"
#include"entityList.h"

void HIT(Entity&self, Entity&aim)
{
	if (self.CurrentAtk() >= aim.CurrentBlock())
		aim.updateCurrentHp(aim.CurrentHp() + aim.CurrentBlock() - self.CurrentAtk());
}

void BLOCK(Entity&self, Entity&aim)
{
	self.updateCurrentBlock(self.CurrentDef());
}

void FIREBALL(Entity&self, Entity&aim)
{
	self.updateCurrentAtk(self.CurrentAtk() + FireBall.Value());
	HIT(self, aim);
	self.updateCurrentAtk(self.CurrentAtk() - FireBall.Value());
}

void FIREWALL(Entity&self, Entity&aim)
{
	self.updateCurrentDef(self.CurrentDef() + FireWall.Value());
	BLOCK(self, aim);
	self.updateCurrentDef(self.CurrentDef() - FireWall.Value());
}

/******************************************/
//Î´Íê³É

void FIRESLASH(Entity&self, Entity&aim)
{
}

void FLAMEFANCING(Entity&self, Entity&aim)
{
}

void HEARTFIRE(Entity&self, Entity&aim)
{
}

void IMMORTALFIRE(Entity&self, Entity&aim)
{
}

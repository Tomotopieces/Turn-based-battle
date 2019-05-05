#pragma once
#include"skill.h"
#include"condition.h"

/******************************************/

//玩家技能

void HIT(Entity&self, Entity&aim);
const Skill Hit("击打", Attack, 0, 0, NOCONDITION, HIT);

void BLOCK(Entity&self, Entity&aim);
const Skill Block("防御", Defence, 0, 0, NOCONDITION, BLOCK);

void FIREBALL(Entity&self, Entity&aim);
const Skill FireBall("火球术", Attack, 1, 1, NOCONDITION, FIREBALL);

void FIREWALL(Entity&self, Entity&aim);
const Skill FireWall("火焰屏障", Defence, 1, 1, NOCONDITION, FIREWALL);

void FIRESLASH(Entity&self, Entity&aim);
const Skill FireSlash("火焰斩击", Attack, 2, 2, NOCONDITION, FIRESLASH);

void FLAMEFANCING(Entity&self, Entity&aim);
const Skill FlameFancing("烈火剑法", Attack, 5, 3, NOCONDITION, FLAMEFANCING);

void HEARTFIRE(Entity&self, Entity&aim);
const Skill HeartFire("攻心火", Other, 0, 5, NOCONDITION, HEARTFIRE);

void IMMORTALFIRE(Entity&self, Entity&aim);
const Skill ImmortalFire("真火三昧", Attack, 15, 8, NOCONDITION, IMMORTALFIRE);

/******************************************/

//敌人技能
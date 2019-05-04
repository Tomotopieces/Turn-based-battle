#pragma once
#include"skill.h"
#include"condition.h"

void HIT();
Skill hit("»÷´ò", Attack, 0, 0, NOCONDITION, HIT);

void BLOCK();
Skill blk("·ÀÓù", Defence, 0, 0, NOCONDITION, BLOCK);

void FIREBALL();
Skill FireBall("»ðÇòÊõ", Attack, 1, 1, NOCONDITION, FIREBALL);

void FIREWALL();
Skill FireWall("»ðÑæÆÁÕÏ", Defence, 1, 1, NOCONDITION, FIREWALL);

void FIRESLASH();
Skill FireSlash("»ðÑæÕ¶»÷", Attack, 2, 2, NOCONDITION, FIRESLASH);

void FLAMEFANCING();
Skill FlameFancing("ÁÒ»ð½£·¨", Attack, 5, 3, NOCONDITION, FLAMEFANCING);

void HEARTFIRE();
Skill HeartFire("¹¥ÐÄ»ð", Other, 0, 5, NOCONDITION, HEARTFIRE);

void IMMORTALFIRE();
Skill ImmortalFire("Õæ»ðÈýÃÁ", Attack, 15, 8, NOCONDITION, IMMORTALFIRE);
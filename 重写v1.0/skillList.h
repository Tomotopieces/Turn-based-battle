#pragma once
#include"skill.h"

void HIT();
Skill hit("»÷´ò", Attack, 0, 0, HIT);

void BLOCK();
Skill blk("·ÀÓù", Defence, 0, 0, BLOCK);

void FIREBALL();
Skill FireBall("»ðÇòÊõ", Attack, 1, 1, FIREBALL);

void FIREWALL();
Skill FireWall("»ðÑæÆÁÕÏ", Defence, 1, 1, FIREWALL);

void FIRESLASH();
Skill FireSlash("»ðÑæÕ¶»÷", Attack, 2, 2, FIRESLASH);

void FLAMEFANCING();
Skill FlameFancing("ÁÒ»ð½£·¨", Attack, 5, 3, FLAMEFANCING);

void HEARTFIRE();
Skill HeartFire("¹¥ÐÄ»ð", Other, 0, 5, HEARTFIRE);

void IMMORTALFIRE();
Skill ImmortalFire("Õæ»ðÈýÃÁ", Attack, 15, 8, IMMORTALFIRE);
#pragma once
#include"skill.h"
#include"condition.h"

void HIT();
const Skill hit("»÷´ò", Attack, 0, 0, NOCONDITION, HIT);

void BLOCK();
const Skill blk("·ÀÓù", Defence, 0, 0, NOCONDITION, BLOCK);

void FIREBALL();
const Skill FireBall("»ðÇòÊõ", Attack, 1, 1, NOCONDITION, FIREBALL);

void FIREWALL();
const Skill FireWall("»ðÑæÆÁÕÏ", Defence, 1, 1, NOCONDITION, FIREWALL);

void FIRESLASH();
const Skill FireSlash("»ðÑæÕ¶»÷", Attack, 2, 2, NOCONDITION, FIRESLASH);

void FLAMEFANCING();
const Skill FlameFancing("ÁÒ»ð½£·¨", Attack, 5, 3, NOCONDITION, FLAMEFANCING);

void HEARTFIRE();
const Skill HeartFire("¹¥ÐÄ»ð", Other, 0, 5, NOCONDITION, HEARTFIRE);

void IMMORTALFIRE();
const Skill ImmortalFire("Õæ»ðÈýÃÁ", Attack, 15, 8, NOCONDITION, IMMORTALFIRE);
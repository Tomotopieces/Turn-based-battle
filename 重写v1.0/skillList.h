#pragma once
#include"skill.h"

void HIT();
skill hit("»÷´ò", Attack, 0, 0, HIT);

void BLOCK();
skill blk("·ÀÓù", Defence, 0, 0, BLOCK);

void FIREBALL();
skill FireBall("»ðÇòÊõ", Attack, 1, 1, FIREBALL);

void FIREWALL();
skill FireWall("»ðÑæÆÁÕÏ", Defence, 1, 1, FIREWALL);

void FIRESLASH();
skill FireSlash("»ðÑæÕ¶»÷", Attack, 2, 2, FIRESLASH);

void FLAMEFANCING();
skill FlameFancing("ÁÒ»ð½£·¨", Attack, 5, 3, FLAMEFANCING);

void HEARTFIRE();
skill HeartFire("¹¥ÐÄ»ð", Other, 0, 5, HEARTFIRE);

void IMMORTALFIRE();
skill ImmortalFire("Õæ»ðÈýÃÁ", Attack, 15, 8, IMMORTALFIRE);
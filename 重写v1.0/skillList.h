#pragma once
#include"skill.h"
#include"condition.h"

void HIT();
Skill hit("����", Attack, 0, 0, NOCONDITION, HIT);

void BLOCK();
Skill blk("����", Defence, 0, 0, NOCONDITION, BLOCK);

void FIREBALL();
Skill FireBall("������", Attack, 1, 1, NOCONDITION, FIREBALL);

void FIREWALL();
Skill FireWall("��������", Defence, 1, 1, NOCONDITION, FIREWALL);

void FIRESLASH();
Skill FireSlash("����ն��", Attack, 2, 2, NOCONDITION, FIRESLASH);

void FLAMEFANCING();
Skill FlameFancing("�һ𽣷�", Attack, 5, 3, NOCONDITION, FLAMEFANCING);

void HEARTFIRE();
Skill HeartFire("���Ļ�", Other, 0, 5, NOCONDITION, HEARTFIRE);

void IMMORTALFIRE();
Skill ImmortalFire("�������", Attack, 15, 8, NOCONDITION, IMMORTALFIRE);
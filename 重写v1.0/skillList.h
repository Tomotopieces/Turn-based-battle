#pragma once
#include"skill.h"

void HIT();
Skill hit("����", Attack, 0, 0, HIT);

void BLOCK();
Skill blk("����", Defence, 0, 0, BLOCK);

void FIREBALL();
Skill FireBall("������", Attack, 1, 1, FIREBALL);

void FIREWALL();
Skill FireWall("��������", Defence, 1, 1, FIREWALL);

void FIRESLASH();
Skill FireSlash("����ն��", Attack, 2, 2, FIRESLASH);

void FLAMEFANCING();
Skill FlameFancing("�һ𽣷�", Attack, 5, 3, FLAMEFANCING);

void HEARTFIRE();
Skill HeartFire("���Ļ�", Other, 0, 5, HEARTFIRE);

void IMMORTALFIRE();
Skill ImmortalFire("�������", Attack, 15, 8, IMMORTALFIRE);
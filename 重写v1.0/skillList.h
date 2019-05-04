#pragma once
#include"skill.h"
#include"condition.h"

void HIT();
const Skill hit("����", Attack, 0, 0, NOCONDITION, HIT);

void BLOCK();
const Skill blk("����", Defence, 0, 0, NOCONDITION, BLOCK);

void FIREBALL();
const Skill FireBall("������", Attack, 1, 1, NOCONDITION, FIREBALL);

void FIREWALL();
const Skill FireWall("��������", Defence, 1, 1, NOCONDITION, FIREWALL);

void FIRESLASH();
const Skill FireSlash("����ն��", Attack, 2, 2, NOCONDITION, FIRESLASH);

void FLAMEFANCING();
const Skill FlameFancing("�һ𽣷�", Attack, 5, 3, NOCONDITION, FLAMEFANCING);

void HEARTFIRE();
const Skill HeartFire("���Ļ�", Other, 0, 5, NOCONDITION, HEARTFIRE);

void IMMORTALFIRE();
const Skill ImmortalFire("�������", Attack, 15, 8, NOCONDITION, IMMORTALFIRE);
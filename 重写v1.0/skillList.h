#pragma once
#include"skill.h"
#include"condition.h"

/******************************************/

//��Ҽ���

void HIT(Entity&self, Entity&aim);
const Skill Hit("����", Attack, 0, 0, NOCONDITION, HIT);

void BLOCK(Entity&self, Entity&aim);
const Skill Block("����", Defence, 0, 0, NOCONDITION, BLOCK);

void FIREBALL(Entity&self, Entity&aim);
const Skill FireBall("������", Attack, 1, 1, NOCONDITION, FIREBALL);

void FIREWALL(Entity&self, Entity&aim);
const Skill FireWall("��������", Defence, 1, 1, NOCONDITION, FIREWALL);

void FIRESLASH(Entity&self, Entity&aim);
const Skill FireSlash("����ն��", Attack, 2, 2, NOCONDITION, FIRESLASH);

void FLAMEFANCING(Entity&self, Entity&aim);
const Skill FlameFancing("�һ𽣷�", Attack, 5, 3, NOCONDITION, FLAMEFANCING);

void HEARTFIRE(Entity&self, Entity&aim);
const Skill HeartFire("���Ļ�", Other, 0, 5, NOCONDITION, HEARTFIRE);

void IMMORTALFIRE(Entity&self, Entity&aim);
const Skill ImmortalFire("�������", Attack, 15, 8, NOCONDITION, IMMORTALFIRE);

/******************************************/

//���˼���
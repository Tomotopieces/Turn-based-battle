#pragma once
#include"skill.h"

void HIT();
skill hit("����", Attack, 0, 0, HIT);

void BLOCK();
skill blk("����", Defence, 0, 0, BLOCK);

void FIREBALL();
skill FireBall("������", Attack, 1, 1, FIREBALL);

void FIREWALL();
skill FireWall("��������", Defence, 1, 1, FIREWALL);

void FIRESLASH();
skill FireSlash("����ն��", Attack, 2, 2, FIRESLASH);

void FLAMEFANCING();
skill FlameFancing("�һ𽣷�", Attack, 5, 3, FLAMEFANCING);

void HEARTFIRE();
skill HeartFire("���Ļ�", Other, 0, 5, HEARTFIRE);

void IMMORTALFIRE();
skill ImmortalFire("�������", Attack, 15, 8, IMMORTALFIRE);
#pragma once
#include"Entity.h"
#include"Buff.h"

struct Team
{
	std::vector<Entity>EntityList;
	std::vector<Buff>BuffList;
};

//��Ҷ���
extern std::vector<Team>playerTeam;
//��ǰ��Ҷ���
extern std::vector<Team>currentPlayerTeam;

//���˶���
extern std::vector<Team>EnemyTeam;				//������ܿ���д�ܶ��̶ֹ����䣿
//��ǰ���˶���
extern std::vector<Team>currentEnemyTeam;
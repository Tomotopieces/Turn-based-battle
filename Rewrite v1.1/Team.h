#pragma once
#include"header.h"
#include"Entity.h"
#include"BuffList.h"

struct Team
{
	std::vector<Entity>members;
	std::vector<BuffList>buffLists;
};

//��Ҷ���
extern Team playerTeam;
//��ǰ��Ҷ���
extern Team curentPlayerTeam;

//���˶���
extern Team enemyTeam;
//��ǰ���˶���
extern Team currentEnemyTeam;
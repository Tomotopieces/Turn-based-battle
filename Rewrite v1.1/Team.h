#pragma once
#include"header.h"
#include"Entity.h"
#include"BuffList.h"

struct Team
{
	std::vector<Entity>members;
	std::vector<BuffList>buffLists;
};

//玩家队伍
extern Team playerTeam;
//当前玩家队伍
extern Team curentPlayerTeam;

//敌人队伍
extern Team enemyTeam;
//当前敌人队伍
extern Team currentEnemyTeam;
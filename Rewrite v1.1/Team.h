#pragma once
#include"Entity.h"
#include"Buff.h"

struct Team
{
	std::vector<Entity>EntityList;
	std::vector<Buff>BuffList;
};

//玩家队伍
extern std::vector<Team>playerTeam;
//当前玩家队伍
extern std::vector<Team>currentPlayerTeam;

//敌人队伍
extern std::vector<Team>EnemyTeam;				//这个可能可以写很多种固定搭配？
//当前敌人队伍
extern std::vector<Team>currentEnemyTeam;
#pragma once
#include<iostream>
#include<Windows.h>
#include<ctime>
#include<fstream>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")
#include"frames.h"

using std::cin;
using std::cout;
using std::endl;

extern std::ifstream fin;
extern std::ofstream fout;

extern int sel;

/* 误选 */
void selwr(int options);

/* 商店 */
void shop();

/* 胜负判定 */
void expJudge();

	extern bool result;//结果胜负判定
	extern int turn;//回合判定
	extern int dam;//伤害
	extern string message[2];//信息输出

/* 我方技能 */
void skill_p(int s);

/* 敌人技能 */
void skill_e();

/* 战斗函数 */
void battle();

/* 存档 */
void saveData();

/* 读档 */
void loadData();
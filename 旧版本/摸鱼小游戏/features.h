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

/* ��ѡ */
void selwr(int options);

/* �̵� */
void shop();

/* ʤ���ж� */
void expJudge();

	extern bool result;//���ʤ���ж�
	extern int turn;//�غ��ж�
	extern int dam;//�˺�
	extern string message[2];//��Ϣ���

/* �ҷ����� */
void skill_p(int s);

/* ���˼��� */
void skill_e();

/* ս������ */
void battle();

/* �浵 */
void saveData();

/* ���� */
void loadData();
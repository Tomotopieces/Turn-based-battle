#pragma once
#include"Buff.h"

/*
	ÿ����λ�������б�
*/

class BuffList
{
private:
	std::vector<Buff>buffList;

	/* ��λ */
	std::vector<Buff>::iterator Locate(Buff&buff);//���ص��ǵ�����
public:
	BuffList() = default;
	~BuffList() = default;
	BuffList&operator=(BuffList&copy);

	/*********************	��ɾ��	*********************/

	/* �����ж� */
	bool Exist(Buff&buff);

	/* ������� */
	BuffList&Get(Buff&buff);

	/* ɾ������ */
	BuffList&Delete(Buff&buff);
};

//Buff������
extern Buff Lost;
extern Buff Normal;

//�޷�����
extern Buff CantTreat;
//�˿�
extern Buff Wound;
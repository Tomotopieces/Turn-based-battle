#pragma once
#include"header.h"

typedef enum skillType { Attack, Defence, Treat, Other }ST;

class skill
{
private:
	string name;		//��
	ST type;			//����
	union _value {
		int atk;			//�˺�
		int def;			//��
		int treat;			//����ֵ
	}value;
	int energy;			//��������
	void(*effect)();	//����Ч��

	explicit skill();
public:
	skill(const char*Name, ST Type, int Val, int Energy, void(*Effect)());

	/******************************************/

	/* ��ʾ������ */
	const string&Name()const;

	/* ��ʾ�������� */
	const string&Type()const;

	/* ��ʾvalue */
	int Value()const;

	/* ��ʾ�������� */
	int Energy()const;

	/******************************************/

	/* ʹ�ü��� */
	bool use()const;
};

extern vector<skill>playerSkill;
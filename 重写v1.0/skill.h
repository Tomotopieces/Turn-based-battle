#pragma once
#include"header.h"

typedef enum skillType { Attack, Defence, Treat, Other }ST;

class Skill
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

	explicit Skill();
public:
	Skill(const char*Name, ST Type, int Val, int Energy, void(*Effect)());
	~Skill() = default;

	/******************************************/

	/* ���ؼ����� */
	const string&Name()const;

	/* ���ؼ������� */
	const string&Type()const;

	/* ����value */
	int Value()const;

	/* ������������ */
	int Energy()const;

	/******************************************/

	/* ʹ�ü��� */
	bool use()const;
};

extern vector<Skill>playerSkill;
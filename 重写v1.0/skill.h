#pragma once
#include"header.h"

/* ������� */
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
	void(*effect)();	//Ч��


	bool(*condition)();		//ʹ������		�����ù���ˮ��ǧ���޷�ʹ�������༼��
	

	explicit Skill();
public:
	Skill(const char*Name, ST Type, int Val, int Energy, bool(*Condition)(), void(*Effect)());
	Skill(const Skill&copy);
	~Skill() = default;
	Skill&operator=(const Skill&copy);

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

	/* �����Ƿ���� */
	bool Usable()const;

	/* ʹ�ü��� */
	bool use()const;
};
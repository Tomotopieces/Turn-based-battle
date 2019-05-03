#pragma once
#include"header.h"

typedef enum skillType ST;
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
	skill(string&Name, ST Type, int Val, int Energy, void(*Effect)());

	/******************************************/

	/* ��ʾ������ */
	const string&Name()const;

	/* ��ʾ�������� */
	const string&Type()const;

	/* ��ʾ�˺� */
	int Atk()const;

	/* ��ʾ�� */
	int Def()const;

	/* ��ʾ����ֵ */
	int Trt()const;

	/* ��ʾ�������� */
	int Energy()const;

	/******************************************/

	/* ʹ�ü��� */
	bool use()const;
};
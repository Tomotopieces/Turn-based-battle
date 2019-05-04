#pragma once
#include"header.h"

class item
{
private:
	string name;		//����
	bool stackable;		//�Ƿ�ɵ���
	void(*effect)();	//Ч��
	bool(*condition)();	//ʹ������

	explicit item();
public:
	item(const string&Name, const bool Stackable, bool(*Condition)(), void(*Effect)())
		:name(Name), stackable(Stackable), effect(Effect),condition(Condition)
	{
	}
	~item() = default;

	/* �������� */
	const string&Name()const;

	/* �����Ƿ�ɵ��� */
	bool Stackable()const;

	/* ʹ�õ��� */		//���߿�����ʹ���������ʷ���Ч����д
	bool use()const;
};
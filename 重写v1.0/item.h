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

	item(const string&Name, const bool Stackable, void(*Effect)(), bool(*Condition)())
		:name(Name), stackable(Stackable), effect(Effect)
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
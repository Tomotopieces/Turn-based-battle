#pragma once
#include"header.h"

class Item
{
private:
	string name;		//����
	bool stackable;		//�Ƿ�ɵ���
	void(*effect)();	//Ч��
	bool(*condition)();	//ʹ������

	explicit Item();
public:
	Item(const string&Name, const bool Stackable, bool(*Condition)(), void(*Effect)())
		:name(Name), stackable(Stackable), effect(Effect),condition(Condition)
	{
	}
	~Item() = default;

	/* ������Ʒ */
	Item&operator=(const Item&copy);

	/* �Ա���Ʒ */
	bool operator==(const Item&opponent);

	/* �������� */
	const string&Name()const;

	/* �����Ƿ�ɵ��� */
	bool Stackable()const;

	/* ʹ�õ��� */		//���߿�����ʹ���������ʷ���Ч����д
	bool use()const;
};
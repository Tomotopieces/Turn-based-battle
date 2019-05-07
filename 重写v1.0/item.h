#pragma once
#include"entity.h"

/* ���� */
class Item
{
private:
	string name;		//����
	bool stackable;		//�Ƿ�ɵ���
	void(*effect)(Entity&self, Entity&aim);	//Ч��
	bool(*condition)();	//ʹ������
public:
	Item() = default;
	Item(const string&Name, const bool Stackable, bool(*Condition)(), void(*Effect)(Entity&self, Entity&aim))
		:name(Name), stackable(Stackable), effect(Effect),condition(Condition)
	{
	}
	Item(const Item&copy)
		:name(copy.name), stackable(copy.stackable), effect(copy.effect), condition(copy.condition)
	{
	}
	~Item() = default;

	Item&operator=(const Item&copy);

	/******************************************/

	/* �Ա���Ʒ */
	bool operator==(const Item&aim);

	/* �������� */
	const string&Name()const;

	/* �����Ƿ�ɵ��� */
	bool Stackable()const;

	/* ʹ�õ��� */		//���߿�����ʹ���������ʷ���Ч����д
	bool useTo(Entity&aim)const;
};
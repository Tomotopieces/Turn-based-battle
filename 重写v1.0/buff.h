#pragma once
#include"entity.h"

class Buff
{
private:
	string name;				//����
	bool stackable;				//�Ƿ�ɵ���
	int level = 0;				//buff�ȼ�
	void(*effect)(Entity&self, Entity&aim);	//Ч��

	explicit Buff();
public:
	Buff(const string & Name, const bool Stackable, void(*Effect)(Entity &self, Entity &aim), void(*Update)())
		:name(Name), stackable(Stackable), effect(Effect)
	{
	}
	Buff(const Buff&copy)
		:name(copy.name), stackable(copy.stackable), level(copy.level), effect(copy.effect)
	{
	}
	~Buff() = default;

	Buff&operator=(const Buff&copy);

	/******************************************/
	/* �������� */

	const string&Name();

	bool Stackable();

	int Level();

	/******************************************/

	/* ����״̬�ȼ� */
	Buff&update(int Level);

	/* ���� */
	Buff&trigger(Entity&self, Entity&aim);
};
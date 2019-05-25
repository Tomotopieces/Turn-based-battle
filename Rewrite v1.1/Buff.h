#pragma once
#include"header.h"
#include"Entity.h"

/*
	���������
*/

class Buff
{
private:
	std::string name;						//����
	bool stackable;							//�Ƿ�ɵ���
	bool isBuff;							//������߼���
	int level = 0;							//buff�ȼ�
	void(*effect)(Entity&self, Entity&aim);	//Ч��

	explicit Buff();
public:
	/* ����������buff */			//����Ҫд�ȼ�
	Buff(const std::string & Name, const bool Stackable, const bool IsBuff, void(*Effect)(Entity &self, Entity &aim))
		:name(Name), stackable(Stackable), isBuff(IsBuff), effect(Effect)
	{
	}
	/* ��λ���buff */			//����pushbackʱ����Ҫд�ȼ�
	Buff(const std::string & Name, const bool Stackable, const bool IsBuff, int Level, void(*Effect)(Entity &self, Entity &aim))
		:name(Name), stackable(Stackable), isBuff(IsBuff), level(Level), effect(Effect)
	{
	}
	Buff(const Buff&copy)
		:name(copy.name), stackable(copy.stackable), isBuff(copy.isBuff), level(copy.level), effect(copy.effect)
	{
	}
	~Buff() = default;

	Buff&operator=(const Buff&copy);

	/*********************	���س�Ա����	*********************/

	const std::string&Name()const { return name; }
	bool Stackable()const { return stackable; }
	bool IsBuff()const { return isBuff; }
	int Level()const { return level; }

	/*********************	�������ⷽ��	*********************/

	/* ����״̬�ȼ� */
	Buff&update(int Level);

	/* ����״̬Ч�� */
	//һ��״̬��������Ч�������������ӣ�ֻ�ƶ�Ч������
	Buff&trigger(Entity&aim);
	//����״̬�Զ�����Ч�����羣�����ˣ�ͬʱָ��Ч��Դ��Ч������
	Buff&trigger(Entity&self, Entity&aim);

	/* ͬ��Buff */
	bool operator==(const Buff&aim);
};
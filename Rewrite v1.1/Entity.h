#pragma once
#include"header.h"

/*
	ս����λ
*/

class Entity
{
private:
	std::string name;		//������

	int hp;					//��������ֵ
	int mp;					//��������ֵ
	int atk;				//���й�����
	int def;				//���з�����
	int currentBlock = 0;	//��ֵ

	int coin;				//���
	int level;				//�ȼ�
	int exp;				//Ŀǰ����
	int maxExp = 20;		//�������辭��ֵ

	std::string img;		//��ɫͼ��

	explicit Entity();		//����Ĭ�Ϲ���
public:
	Entity(const std::string&Name, const int Hp, const int Mp, const int Atk, const int Def, const int Coin, const int Level, const int Exp, const std::string Img)
		:name(Name), hp(Hp), atk(Atk), def(Def), coin(Coin), level(Level), exp(Exp), img(Img)
	{}
	/* ������ͬ��岻ͬ���ֵĵ�λ */		//���ڶ�浵�����Ƶ���
	Entity(const std::string&Name, const Entity&copy)
		:name(Name), hp(copy.hp), atk(copy.atk), def(copy.def), coin(copy.coin), level(copy.level), exp(copy.exp), img(copy.img)
	{}
	Entity(const Entity&copy)
		:name(copy.name), hp(copy.hp), atk(copy.atk), def(copy.def), coin(copy.coin), level(copy.level), exp(copy.exp), img(copy.img)
	{}
	~Entity() = default;

	Entity&operator=(const Entity&copy);

	/*********************	���س�Ա����	*********************/

	const std::string&Name()const { return name; }

	int Hp()const { return hp; }
	int Mp()const { return mp; }
	int Atk()const { return atk; }
	int Def()const { return def; }
	int CurrentBlock()const { return currentBlock; }

	int Coin()const { return coin; }
	int Level()const { return level; }
	int Exp()const { return exp; }
	int MaxExp()const { return maxExp; }

	const std::string&Img()const { return img; }

	/*********************	���³�Ա����	*********************/

	Entity&updateName(const std::string&newName) { name = newName; return*this; }

	Entity&updateHp(int newHp) { hp = newHp; return*this; }
	Entity&updateMp(int newMp) { mp = newMp; return*this; }
	Entity&updateAtk(int newAtk) { atk = newAtk; return*this; }
	Entity&updateDef(int newDef) { def = newDef; return*this; }
	Entity&updateCurrentBlock(int newCurrentBlock) { currentBlock = newCurrentBlock; return*this; }

	Entity&updateCoin(int newCoin) { coin = newCoin; return*this; }
	Entity&levelUp();
		//����levelʱ��������maxExp
	Entity&updateExp(int newExp) { exp = newExp; return*this; }

		//img������
};
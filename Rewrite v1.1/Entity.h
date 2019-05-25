#pragma once
#include"header.h"

class Entity
{
private:
	std::string name;		//������

	int hp;					//��������ֵ
	int currentHp = 0;		//��ǰ����ֵ
	int mp;					//��������ֵ
	int currentMp = 0;		//��ǰ����ֵ
	int atk;				//���й�����
	int currentAtk = 0;		//��ǰ������
	int def;				//���з�����
	int currentDef = 0;		//��ǰ������
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
	int CurrentHp()const { return currentHp; }
	int Mp()const { return mp; }
	int CurrentMp()const { return currentMp; }
	int Atk()const { return atk; }
	int CurrentAtk()const { return currentAtk; }
	int Def()const { return def; }
	int CurrentDef()const { return currentDef; }
	int CurrentBlock()const { return currentBlock; }

	int Coin()const { return coin; }
	int Level()const { return level; }
	int Exp()const { return exp; }
	int MaxExp()const { return maxExp; }

	const std::string&Img()const { return img; }

	/*********************	���³�Ա����	*********************/

	Entity&updateName(const std::string&newName) { name = newName; return*this; }

	Entity&updateHp(int newHp) { hp = newHp; return*this; }
	Entity&updateCurrentHp(int newCurrentHp) { currentHp = newCurrentHp; return*this; }
	Entity&updateMp(int newMp) { mp = newMp; return*this; }
	Entity&updateCurrentMp(int newCurrentMp) { currentMp = newCurrentMp; return*this; }
	Entity&updateAtk(int newAtk) { atk = newAtk; return*this; }
	Entity&updateCurrentAtk(int newCurrentAtk) { currentAtk = newCurrentAtk; return*this; }
	Entity&updateDef(int newDef) { def = newDef; return*this; }
	Entity&updateCurrentDef(int newCurrentDef) { currentDef = newCurrentDef; return*this; }
	Entity&updateCurrentBlock(int newCurrentBlock) { currentBlock = newCurrentBlock; return*this; }

	Entity&updateCoin(int newCoin) { coin = newCoin; return*this; }
	Entity&levelUp();
		//����levelʱ��������maxExp
	Entity&updateExp(int newExp) { exp = newExp; return*this; }

		//img������
};
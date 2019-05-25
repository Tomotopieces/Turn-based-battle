#pragma once
#include"header.h"

enum buff { Normal, OnFire, Undefeatable, CantTreat, Wound };//�ƺ�������д��cpp��Ȼ��������extern������

/* ��λ */
class Entity
{
private:
	string name;		//������

	int hp;				//��������ֵ
	int currentHp = 0;		//��ǰ����ֵ
	int mp;				//��������ֵ
	int currentMp = 0;		//��ǰ����ֵ
	int atk;			//���й�����
	int currentAtk = 0;		//��ǰ������
	int def;			//���з�����
	int currentDef = 0;		//��ǰ������
	int currentBlock = 0;		//��ֵ

	int coin;			//���
	int lvl;			//�ȼ�
	int exp;			//Ŀǰ����
	int maxExp = 20;	//�������辭��ֵ

	string img;			//��ɫͼ��

	explicit Entity();	//����Ĭ�Ϲ���
public:
	Entity(const string&Name, const int Hp, const int Mp, const int Atk, const int Def, const int Coin, const int Lvl, const int Exp, const string Img)
		:name(Name), hp(Hp), atk(Atk), def(Def), coin(Coin), lvl(Lvl), exp(Exp), img(Img)
	{}
	/* ������ͬ��岻ͬ���ֵĵ�λ */		//���ڶ�浵�����Ƶ���
	Entity(const string&Name, const Entity&copy)
		:name(Name), hp(copy.hp), atk(copy.atk), def(copy.def), coin(copy.coin), lvl(copy.lvl), exp(copy.exp), img(copy.img)
	{}
	Entity(const Entity&copy)
		:name(copy.name), hp(copy.hp), atk(copy.atk), def(copy.def), coin(copy.coin), lvl(copy.lvl), exp(copy.exp), img(copy.img)
	{}
	~Entity() = default;

	Entity&operator=(const Entity&copy);

	/******************************************/

	/* �������� */
	const string&Name()const;

	/* ������ */
	Entity&Rename(const string&Name);

	/* ս��ǰ���ݳ�ʼ�� */
	Entity&Init();

	/******************************************/

	/* ���¹�������ֵ */
	Entity&updateHp(const int val);

	/* ���µ�ǰ����ֵ */
	Entity&updateCurrentHp(const int val);

	/* ���ع�������ֵ */
	int Hp()const;

	/* ���ص�ǰ����ֵ */
	int CurrentHp()const;

	/******************************************/

	/* ���¹�������ֵ */
	Entity&updateMp(const int val);

	/* ���µ�ǰ����ֵ */
	Entity&updateCurrentMp(const int val);

	/* ���ع�������ֵ */
	int Mp()const;

	/* ���ص�ǰ����ֵ */
	int CurrentMp()const;

	/******************************************/

	/* ���¹��й����� */
	Entity&updateAtk(const int val);

	/* ���µ�ǰ������ */		//һ�����ҩ���߼��ܲ�����buff
	Entity&updateCurrentAtk(const int val);

	/* ���ع��й����� + ���������� */
	int Atk()const;

	/* ���ص�ǰ������ */
	int CurrentAtk()const;

	/******************************************/

	/* ���¹��з����� */
	Entity&updateDef(const int val);

	/* ���µ�ǰ������ */
	Entity&updateCurrentDef(const int val);

	/* ���µ�ǰ��ֵ */
	Entity&updateCurrentBlock(const int val);

	/* ��ո� */
	Entity&clearBlock();

	/* ���ع��з����� */
	int Def()const;

	/* ���ص�ǰ������ */
	int CurrentDef()const;

	/* ���ظ�ֵ */
	int CurrentBlock()const;

	/******************************************/

	/* ���buff */
	Entity&GetBuff(buff name, int level);

	/* �غϽ���ʱ����buff�� */
	Entity&updateBuffListOnTurnEnd();

	/* һ���ж�����ʱ����buff�� */
	Entity&updateBuffListOnActionEnd();

	/* ����buff */
	bool findBuff(buff name)const;

	/******************************************/

	/* ���½���� */
	Entity&updateCoin(const int inc);

	/* ��ʾ����� */
	int Coin()const;

	/******************************************/

	/* ���¾���ֵ */
	Entity&updateExp(const int val);

	/* ��ʾ����ֵ */
	int Exp()const;

	/******************************************/

	/* ���µȼ� */
	Entity&lvlUp();

	/* ���صȼ� */
	int Lvl()const;

	/******************************************/

	/* ����Max����ֵ */
	int MaxExp()const;

	/******************************************/

	/* ����ͼ�� */
	const string&Img()const;
};

//�����������Ե��ѣ�
/*
	��ҵı���/����������ô��ģ�
	��д��������ķ������ڻغϽ���ʱ����buff�б�/���ж�����ʱ����buff�б�
	��Ϊһ�غϻ��ж���ж������Ҹ��µ�buffҲ��һ�������Էֿ�д��Ȼ�������־͡�����
	updBuffList_endTurn()��updBuffList_endAction()
	Ŀǰ���Ǹ���ѧ����ûд��ʲô����Ŀ���о������ĺ�����ʮ�ַ�����������ȻVS���Զ�����ܺ��þ����ˡ�����
	�����̫�����˻���˵һ��ı���/����������ô����

��Ͱ���
	�ҵĻ����� updateBuffOnTurnEnd() updateBuffOnActionEnd()��
	���ֳ�����ν���ֲ����ü��±�д���룬���ֺ�������������Ҫ�����Բ����������ݽṹ�����ǻ���updateBuffMap֮��ġ�Ҳ��Ҫ�ò�ͨ�õ���д������ʵʵдupdate

˹����
	��java��python�������˵������Ҫô���շ壬Ҫô���»��ߡ����ÿ���ȥ�������
	java����ķ��������������е㳤��
*/
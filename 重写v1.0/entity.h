#pragma once
#include"header.h"

enum buff { Normal, OnFire, Undefeatable, CantTreat, Wound };//�ƺ�������д��cpp��Ȼ��������extern������

/* ��λ */
class entity
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
	struct Buff
	{
		buff name;
		int level;
	};
	vector<Buff>buffList;	//buff��

	int coin;			//���
	int lvl;			//�ȼ�
	int exp;			//Ŀǰ����
	int maxExp = 20;	//�������辭��ֵ

	string img;			//��ɫͼ��

	explicit entity();	//����Ĭ�Ϲ���
public:
	entity(const string&Name, const int Hp, const int Mp, const int Atk, const int Def, const int Coin, const int Lvl, const int Exp, const string Img)
		:name(Name), hp(Hp), atk(Atk), def(Def), coin(Coin), lvl(Lvl), exp(Exp), img(Img)
	{}
	/* ������ͬ��岻ͬ���ֵĵ�λ */		//���ڶ�浵�����Ƶ���
	entity(const string&Name, const entity&copy)
		:name(Name), hp(copy.hp), atk(copy.atk), def(copy.def), coin(copy.coin), lvl(copy.lvl), exp(copy.exp), img(copy.img)
	{}
	entity(const entity&copy)
		:name(copy.name), hp(copy.hp), atk(copy.atk), def(copy.def), coin(copy.coin), lvl(copy.lvl), exp(copy.exp), img(copy.img)
	{}
	~entity() = default;

	entity&operator=(const entity&copy);

	/******************************************/

	/* �������� */
	const string&Name()const;

	/* ������ */
	entity&Rename(const string&Name);

	/* ս��ǰ���ݳ�ʼ�� */
	entity&Init();

	/******************************************/

	/* ���¹�������ֵ */
	entity&updateHp(const int val);

	/* ���µ�ǰ����ֵ */
	entity&updateCurrentHp(const int val);

	/* ���ع�������ֵ */
	int Hp()const;

	/* ���ص�ǰ����ֵ */
	int CurrentHp()const;

	/******************************************/

	/* ���¹�������ֵ */
	entity&updateMp(const int val);

	/* ���µ�ǰ����ֵ */
	entity&updateCurrentMp(const int val);

	/* ���ع�������ֵ */
	int Mp()const;

	/* ���ص�ǰ����ֵ */
	int CurrentMp()const;

	/******************************************/

	/* ���¹��й����� */
	entity&updateAtk(const int val);

	/* ���µ�ǰ������ */		//һ�����ҩ���߼��ܲ�����buff
	entity&updateCurrentAtk(const int val);

	/* ���ع��й����� + ���������� */
	int Atk()const;

	/* ���ص�ǰ������ */
	int CurrentAtk()const;

	/******************************************/

	/* ���¹��з����� */
	entity&updateDef(const int val);

	/* ���µ�ǰ������ */
	entity&updateCurrentDef(const int val);

	/* ���µ�ǰ��ֵ */
	entity&updateCurrentBlock(const int val);

	/* ��շ��� */
	entity&ClrBlk();

	/* ���ع��з����� */
	int Def()const;

	/* ���ص�ǰ������ */
	int CurrentDef()const;

	/* ���ظ�ֵ */
	int CurrentBlock()const;

	/******************************************/

	/* ���buff */
	entity&GetBuff(buff name, int level);

	/* �غϽ���ʱ����buff�� */
	entity&updateBuffListOnTurnEnd();

	/* һ���ж�����ʱ����buff�� */
	entity&updateBuffListOnActionEnd();

	/* ����buff */
	bool findBuff(buff name)const;

	/******************************************/

	/* ���½���� */
	entity&updateCoin(const int inc);

	/* ��ʾ����� */
	int Coin()const;

	/******************************************/

	/* ���¾���ֵ */
	entity&updateExp(const int val);

	/* ��ʾ����ֵ */
	int Exp()const;

	/******************************************/

	/* ���µȼ� */
	entity&lvlUp();

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
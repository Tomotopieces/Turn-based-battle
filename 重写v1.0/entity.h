#pragma once
#include"header.h"

enum buff;

/* ��λ */
class entity
{
private:
	string name;		//������

	int hp;				//��������ֵ
	int hp_c = 0;		//��ǰ����ֵ
	int mp;				//��������ֵ
	int mp_c = 0;		//��ǰ����ֵ
	int atk;			//���й�����
	int atk_c = 0;		//��ǰ������
	int def;			//���з�����
	int def_c = 0;		//��ǰ������
	int block = 0;		//��ֵ
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

	/* ��ʾ���� */
	const string&Name()const;

	/* ������ */
	entity&Rename(const string&Name);

	/* ս��ǰ���ݳ�ʼ�� */
	entity&Init();

	/******************************************/

	/* ���¹�������ֵ */
	entity&updHp(const int val);

	/* ���µ�ǰ����ֵ */
	entity&updHp_c(const int val);

	/* ��ʾ��������ֵ */
	int Hp()const;

	/* ��ʾ��ǰ����ֵ */
	int Hp_c()const;

	/******************************************/

	/* ���¹�������ֵ */
	entity&updMp(const int val);

	/* ���µ�ǰ����ֵ */
	entity&updMp_c(const int val);

	/* ��ʾ��������ֵ */
	int Mp()const;

	/* ��ʾ��ǰ����ֵ */
	int Mp_c()const;

	/******************************************/

	/* ���¹��й����� */
	entity&updAtk(const int val);

	/* ���µ�ǰ������ */		//һ�����ҩ���߼��ܲ�����buff
	entity&updAtk_c(const int val);

	/* ��ʾ���й����� + ���������� */
	int Atk()const;

	/* ��ʾ��ǰ������ */
	int Atk_c()const;

	/******************************************/

	/* ���¹��з����� */
	entity&updDef(const int val);

	/* ���µ�ǰ������ */
	entity&updDef_c(const int val);

	/* ���µ�ǰ��ֵ */
	entity&updBlk_c(const int val);

	/* ��շ��� */
	entity&ClrBlk();

	/* ��ʾ���з����� */
	int Def()const;

	/* ��ʾ��ǰ������ */
	int Def_c()const;

	/* ��ʾ��ֵ */
	int Blk_c()const;

	/******************************************/

	/* ���buff */
	entity&GetBuff(buff name, int level);

	/* �غϽ���ʱ����buff�� */
	entity&updBuffList_endTurn();

	/* һ���ж�����ʱ����buff�� */
	entity&updBuffList_endAction();

	/******************************************/

	/* ���½���� */
	entity&updCoin(const int inc);

	/* ��ʾ����� */
	int Coin()const;

	/******************************************/

	/* ���¾���ֵ */
	entity&updExp(const int val);

	/* ��ʾ����ֵ */
	int Exp()const;

	/******************************************/

	/* ���µȼ� */
	entity&lvlUp();

	/* ��ʾ�ȼ� */
	int Lvl()const;

	/******************************************/

	/* ��ʾMax����ֵ */
	int MaxExp()const;

	/******************************************/

	/* ��ʾͼ�� */
	const string&Img()const;
};

extern entity proto;
extern entity player;
extern entity enemys[];
extern entity enemy;
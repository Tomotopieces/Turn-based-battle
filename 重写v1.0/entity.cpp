#include "entity.h"

enum buff { Normal, OnFire, Undefeatable, CantTreat, Wound };

entity & entity::operator=(const entity & copy)
{
	name = copy.name;
	hp = copy.hp;
	atk = copy.atk;
	def = copy.def;
	coin = copy.coin;
	lvl = copy.lvl;
	exp = copy.exp;
	img = copy.img;
	return*this;
}

const string & entity::Name() const
{
	return name;
}

entity & entity::Rename(const string & Name)
{
	name = Name;
	return *this;
}

entity & entity::Init()
{
	hp_c = hp;
	atk_c = atk/* + weapon.atk */;
	block = 0;
	return*this;
}

entity & entity::updHp(const int val)
{
	hp = val;
	return *this;
}

entity & entity::updHp_c(const int val)
{
	hp_c = val;
	return *this;
}

int entity::Hp() const
{
	return hp;
}

int entity::Hp_c() const
{
	return hp_c;
}

entity & entity::updMp(const int val)
{
	mp = val;
	return *this;
}

entity & entity::updMp_c(const int val)
{
	mp_c = val;
	return *this;
}

int entity::Mp() const
{
	return mp;
}

int entity::Mp_c() const
{
	return mp_c;
}

entity & entity::updAtk(const int val)
{
	atk = val;
	return *this;
}

entity & entity::updAtk_c(const int val)
{
	atk_c = val;
	return *this;
}

int entity::Atk() const
{
	return atk;
}

int entity::Atk_c() const
{
	return atk_c;
}

entity & entity::updDef(const int val)
{
	def = val;
	return*this;
}

entity & entity::updDef_c(const int val)
{
	def_c = val;
	return*this;
}

entity & entity::updBlk_c(const int val)
{
	block = val;
	return*this;
}

entity & entity::ClrBlk()
{
	block = 0;
	return*this;
}

int entity::Def() const
{
	return def;
}

int entity::Def_c() const
{
	return def_c;
}

int entity::Blk_c() const
{
	return block;
}

entity & entity::GetBuff(buff name, int level)
{
	buffList.push_back({ name,level });
	return*this;
}

entity & entity::updBuffList_endTurn()
{
	for (auto it = buffList.begin(); it != buffList.end(); ++it) {
		switch (it->name) {
			//�Ż�
			case OnFire:
				it->level--;
				break;
			default:
				break;
		}
	}
	return*this;
}

entity & entity::updBuffList_endAction()
{
	for (auto it = buffList.begin(); it != buffList.end(); ++it) {
		switch (it->name) {
			//�˿�
			case Wound:
				//0.1�����˿ڱ���
				if (rand() % 5)
					it->level++;
				else
					player.updHp_c(player.Hp_c() - it->level);
				buffList.erase(it);
				it--;
				break;
			default:
				break;
		}
	}
	return*this;
}

entity & entity::updCoin(const int inc)
{
	coin += inc;
	return*this;
}

int entity::Coin() const
{
	return coin;
}

entity & entity::updExp(const int val)
{
	exp = val;
	return*this;
}

int entity::Exp() const
{
	return exp;
}

entity & entity::lvlUp()
{
	lvl++;
	return*this;
}

int entity::Lvl() const
{
	return lvl;
}

int entity::MaxExp() const
{
	int ME = 20;
	for (int i = 1; i < lvl; ++i) {
		ME += (i + 1) * 10;
	}
	return ME;
}

const string & entity::Img() const
{
	return img;
}

/******************************************/

//ԭ�ͻ�
entity proto
{ "NULL",20,0,1,1,10,1,0,
"     �u �v     �u �vn     �v   �v �u �u �un     �u �v �u �v �un   �u�u    �v �u �vn �u�u        �v   �vn����         �u �v �un����       �un����     �un����   �un���� �un���un"
};
entity player = proto;

//����
entity enemys[]
{
	{ "ħ��",50,0,3,2,50,99,100,
	"���v                       �u��n�� ��                     �� ��n�� ��      __      __     �� ��n��  �v __�u   �v __�u   �v __�u  ��n �v ____              ____�un      ��      �U      ��n       �v     �U     �un        ��    �p    ��n         �v   __  �un          �� �� �� ��n           �v�� ���un"
	},
	{ "С͵",20,0,1,1,5,1,10,
	"     �u �v     �u �vn     �v   �v �u �u �un     �u �v �u �v �un   �u�u    �v �u �vn �u�u        �v   �vn����         �u �v �un����       �un����     �un����   �un���� �un���un"
	},
	{"ʳ��������",99,0,99,99,1000,999,1000,
	"          __ n    __  __�v �v n    �v �v �v �v�� ���u�� __ n __���v�� �� ��    �u  �v �v n �v �v�v_�v �v�� �� ��  _�u �u n   �v  �v��  �u  ���u  �u n    ���������� []���������� n    �� ������   ������ �� n    ��  �\�T   �T�_  �� n    ���v         �u�� n    �� ��   __  �� �� n     �v �v ____�u �u n       �v�� __���u n"
	}
};
entity enemy = proto;
#include"skill.h"
#include"entityList.h"

vector<Skill>playerSkill;

Skill::Skill(const char* Name, ST Type, int Val, int Energy, bool(*Condition)(), void(*Effect)())
	:name(string(Name)), type(Type), energy(Energy), condition(Condition), effect(Effect)
{
	switch (type) {
		case Attack:
			value.atk = Val;
			break;
		case Defence:
			value.def = Val;
			break;
		case Treat:
			value.treat = Val;			break;
		case Other:
			value.atk = 0;
			break;
	}
	playerSkill.push_back(*this);
}

const string & Skill::Name() const
{
	return name;
}

const string & Skill::Type() const
{
	switch (type) {
		case Attack:
			return "������";
			break;
		case Defence:
			return "������";
			break;
		case Treat:
			return "������";
			break;
		case Other:
			return "������";
			break;
	}
}

int Skill::Value() const
{
	switch (type) {
		case Attack:
			return value.atk;
			break;
		case Defence:
			return value.def;
			break;
		case Treat:
			return value.def;
			break;
		case Other:
			return 0;
			break;
	}
}

int Skill::Energy() const
{
	return energy;
}

bool Skill::Usable() const
{
	return condition();//�˴�������false��Ϊ    �޷�ʹ��    ������ʹ��ʧ��
}

bool Skill::use()const
{
	if (player.CurrentMp() < energy)
		return false;//�˴�Ϊ    ʹ��ʧ��    �������޷�ʹ��
	player.updateCurrentMp(player.CurrentMp() - energy);
	effect();
	return true;
}

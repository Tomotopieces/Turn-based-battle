#include "skill.h"
#include"entity.h"

enum skillType { Attack, Defence, Treat, Other };

skill::skill(string & Name, ST Type, int Val, int Energy, void(*Effect)())
	:name(Name), type(Type), energy(Energy), effect(Effect)
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
}

const string & skill::Name() const
{
	return name;
}

const string & skill::Type() const
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

int skill::Atk() const
{
	return value.atk;
}

int skill::Def() const
{
	return value.def;
}

int skill::Trt() const
{
	return value.treat;
}

int skill::Energy() const
{
	return energy;
}

bool skill::use()const
{
	if (player.Mp_c() < energy)
		return false;
	player.updMp_c(player.Mp_c() - energy);
	effect();
	return true;
}

#include "skill.h"
#include"entity.h"

vector<skill>playerSkill;

skill::skill(const char* Name, ST Type, int Val, int Energy, void(*Effect)())
	:name(string(Name)), type(Type), energy(Energy), effect(Effect)
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

int skill::Value() const
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

int skill::Energy() const
{
	return energy;
}

bool skill::use()const
{
	if (player.CurrentMp() < energy)
		return false;
	player.updateCurrentMp(player.CurrentMp() - energy);
	effect();
	return true;
}

#include"skill.h"
#include"entityList.h"

Skill::Skill(const char* Name, ST Type, int Val, int Energy, bool(*Condition)(), void(*Effect)(Entity&, Entity&aim))
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
			value.treat = Val;
			break;
		case Other:
			value.atk = 0;
			break;
	}
}

Skill::Skill(const Skill & copy)
	:name(copy.name), type(copy.type), energy(copy.energy), condition(copy.condition), effect(copy.effect)
{
	switch (type) {
		case Attack:
			value.atk = copy.value.atk;
			break;
		case Defence:
			value.def = copy.value.def;
			break;
		case Treat:
			value.treat = copy.value.treat;
			break;
		case Other:
			value.atk = 0;
			break;
	}
}

Skill & Skill::operator=(const Skill & copy)
{
	if (&copy == this)
		return*this;
	name = copy.name;
	type = copy.type;
	energy = copy.energy;
	condition = copy.condition;
	effect = copy.effect;
	return*this;
}

const string & Skill::Name() const
{
	return name;
}

const string & Skill::Type() const
{
	switch (type) {
		case Attack:
			return "攻击型";
			break;
		case Defence:
			return "防御型";
			break;
		case Treat:
			return "治疗型";
			break;
		case Other:
			return "特殊型";
			break;
		default:
			return "特殊型";
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
		default:
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
	return condition();//此处若返回false则为    无法使用    而不是使用失败
}

bool Skill::use()const
{
	if (player.CurrentMp() < energy)
		return false;//此处为    使用失败    而不是无法使用
	player.updateCurrentMp(player.CurrentMp() - energy);
	effect(player, enemy);
	return true;
}

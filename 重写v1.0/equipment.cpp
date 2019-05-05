#include "equipment.h"

Equipment::Equipment(const string&Name, const EType EquipmentType, const int Val, bool(*Condition)(), void(*Effect)(Entity&self, Entity&aim), const WType WeaponType)
	:equipmentType(EquipmentType), weaponType(WeaponType), Item(Name, false, Condition, Effect)
{
	switch (EquipmentType) {
		case Weapon:
			value.atk = Val;
			break;
		case Armor:
			value.def = Val;
			break;
		case Other:
			value.atk = 0;
			break;
	}
}

Equipment::Equipment(const Equipment & copy)
	:equipmentType(copy.equipmentType), weaponType(copy.weaponType), Item(copy)
{
	switch (equipmentType) {
		case Weapon:
			value.atk = copy.value.atk;
			break;
		case Armor:
			value.def = copy.value.def;
			break;
		case Other:
			value.atk = 0;
			break;
	}
}

Equipment & Equipment::operator=(const Equipment & copy)
{
	if (&copy == this)
		return*this;
	Item::operator=(copy);
	equipmentType = copy.equipmentType;
	weaponType = copy.weaponType;
	switch (equipmentType) {
		case Weapon:
			value.atk = copy.value.atk;
			break;
		case Armor:
			value.def = copy.value.def;
			break;
		case Other:
			value.atk = 0;
			break;
	}
	return*this;
}

const EType & Equipment::EquipmentType() const
{
	return equipmentType;
}

const WType & Equipment::WeaponType() const
{
	return weaponType;
}

int Equipment::Value() const
{
	switch (equipmentType) {
		case Weapon:
			return value.atk;
			break;
		case Armor:
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

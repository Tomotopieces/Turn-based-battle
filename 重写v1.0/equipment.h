#pragma once
#include"header.h"
#include"item.h"

/* 装备类别 */
enum EType { Weapon, Armor, Other };
/* 武器类别 */
enum WType { NoType, Sword, Staff, Bow };

/* 武器/装备 */
class Equipment:public Item
{
private:
	EType equipmentType;		//装备类别
	WType weaponType;			//武器类别
	union _value {
		int atk;			//额外攻击力
		int def;			//额外防御力
	}value;
public:
	Equipment(const string&Name, const EType EquipmentType, const int Val, bool(*Condition)(), void(*Effect)(), const WType WeaponType = NoType);
	Equipment(const Equipment&copy);
	~Equipment() = default;

	Equipment&operator=(const Equipment&copy);

	/******************************************/

	/* 返回装备类型 */
	const EType&EquipmentType()const;

	/* 返回武器类型 */
	const WType&WeaponType()const;

	/* 返回value */
	int Value()const;
};
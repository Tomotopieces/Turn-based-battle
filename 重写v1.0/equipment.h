#pragma once
#include"header.h"
#include"item.h"

/* װ����� */
enum EType { Weapon, Armor, Other };
/* ������� */
enum WType { NoType, Sword, Staff, Bow };

/* ����/װ�� */
class Equipment:public Item
{
private:
	EType equipmentType;		//װ�����
	WType weaponType;			//�������
	union _value {
		int atk;			//���⹥����
		int def;			//���������
	}value;
public:
	Equipment(const string&Name, const EType EquipmentType, const int Val, bool(*Condition)(), void(*Effect)(), const WType WeaponType = NoType);
	Equipment(const Equipment&copy);
	~Equipment() = default;

	Equipment&operator=(const Equipment&copy);

	/******************************************/

	/* ����װ������ */
	const EType&EquipmentType()const;

	/* ������������ */
	const WType&WeaponType()const;

	/* ����value */
	int Value()const;
};
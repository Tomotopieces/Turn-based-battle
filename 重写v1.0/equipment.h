#pragma once
#include"header.h"
#include"item.h"

/* װ����� */
enum EType { Empty, Weapon, Armor, Other };
/* ������� */
enum WType { NoType, Sword, Staff, Bow };

/* ����/װ�� */
class Equipment:public Item
{
private:
	vector<string>tags;
	EType equipmentType;		//װ�����
	WType weaponType;			//�������
	union _value {
		int atk;			//���⹥����
		int def;			//���������
	}value;
public:
	Equipment() = default;
	Equipment(const string&Name, const EType EquipmentType, const int Val, bool(*Condition)(), void(*Effect)(Entity&self, Entity&aim), const WType WeaponType = NoType);
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
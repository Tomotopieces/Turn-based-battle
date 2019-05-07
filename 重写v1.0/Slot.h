#pragma once
#include"header.h"
#include"equipment.h"

class Slot
{
private:
	vector<Equipment>blocks;
public:
	Slot();
	~Slot() = default;

	/******************************************/

	/* 武器槽 */
	Equipment&weaponSlot();

	/* 防具槽 */
	Equipment&armorSlot();

	/* 特殊物品槽 */
	Equipment&specialSlot();
};

extern Slot slot;
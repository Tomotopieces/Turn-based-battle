#include "Slot.h"
#include"equipmentList.h"

Slot slot;

Slot::Slot()
{
	blocks.resize(3, EquipmentLack);
}

Equipment & Slot::weaponSlot()
{
	return blocks[0];
}

Equipment & Slot::armorSlot()
{
	return blocks[1];
}

Equipment & Slot::specialSlot()
{
	return blocks[2];
}

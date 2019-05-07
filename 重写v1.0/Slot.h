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

	/* ������ */
	Equipment&weaponSlot();

	/* ���߲� */
	Equipment&armorSlot();

	/* ������Ʒ�� */
	Equipment&specialSlot();
};

extern Slot slot;
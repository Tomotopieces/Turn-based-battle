#pragma once
#include"item.h"

bool NOCONDITION();

bool CANTREAT();//���Ա�����
void LIFEPOTION();
item LifePotion("����ҩˮ", true, CANTREAT, LIFEPOTION);

void ENERGYPOTION();
item EnergyPotion("����ҩˮ", true, NOCONDITION, ENERGYPOTION);

void POWERPOTION();
item PowerPotion("����ҩˮ", true, NOCONDITION, ENERGYPOTION);

#pragma once
#include"Item.h"

bool NOCONDITION();
void NOEFFECT();
Item Empty("", false, NOCONDITION, NOEFFECT);

bool CANTREAT();//���Ա�����
void LIFEPOTION();
Item LifePotion("����ҩˮ", true, CANTREAT, LIFEPOTION);

void ENERGYPOTION();
Item EnergyPotion("����ҩˮ", true, NOCONDITION, ENERGYPOTION);

void POWERPOTION();
Item PowerPotion("����ҩˮ", true, NOCONDITION, ENERGYPOTION);

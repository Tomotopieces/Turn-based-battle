#pragma once
#include"item.h"
#include"condition.h"

Item Empty("", false, NOCONDITION, NOEFFECT);
void LIFEPOTION();
Item LifePotion("����ҩˮ", true, CANTREAT, LIFEPOTION);

void ENERGYPOTION();
Item EnergyPotion("����ҩˮ", true, NOCONDITION, ENERGYPOTION);

void POWERPOTION();
Item PowerPotion("����ҩˮ", true, NOCONDITION, ENERGYPOTION);

#pragma once
#include"item.h"
#include"condition.h"

Item Empty("", false, NOCONDITION, NOEFFECT);
void LIFEPOTION();
Item LifePotion("生命药水", true, CANTREAT, LIFEPOTION);

void ENERGYPOTION();
Item EnergyPotion("能量药水", true, NOCONDITION, ENERGYPOTION);

void POWERPOTION();
Item PowerPotion("力量药水", true, NOCONDITION, ENERGYPOTION);

#pragma once
#include"Item.h"

bool NOCONDITION();
void NOEFFECT();
Item Empty("", false, NOCONDITION, NOEFFECT);

bool CANTREAT();//可以被治疗
void LIFEPOTION();
Item LifePotion("生命药水", true, CANTREAT, LIFEPOTION);

void ENERGYPOTION();
Item EnergyPotion("能量药水", true, NOCONDITION, ENERGYPOTION);

void POWERPOTION();
Item PowerPotion("力量药水", true, NOCONDITION, ENERGYPOTION);

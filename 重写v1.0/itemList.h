#pragma once
#include"item.h"

bool NOCONDITION();

bool CANTREAT();//可以被治疗
void LIFEPOTION();
item LifePotion("生命药水", true, CANTREAT, LIFEPOTION);

void ENERGYPOTION();
item EnergyPotion("能量药水", true, NOCONDITION, ENERGYPOTION);

void POWERPOTION();
item PowerPotion("力量药水", true, NOCONDITION, ENERGYPOTION);

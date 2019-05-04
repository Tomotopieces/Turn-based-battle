#pragma once
#include"item.h"
#include"condition.h"

void NOEFFECT();
const Item Empty("", false, NOCONDITION, NOEFFECT);

void LIFEPOTION();
const Item LifePotion("生命药水", true, CANTREAT, LIFEPOTION);

void ENERGYPOTION();
const Item EnergyPotion("能量药水", true, NOCONDITION, ENERGYPOTION);

void POWERPOTION();
const Item PowerPotion("力量药水", true, NOCONDITION, ENERGYPOTION);

#pragma once
#include"item.h"
#include"condition.h"

void NOEFFECT();
const Item Empty("", false, NOCONDITION, NOEFFECT);

void LIFEPOTION();
const Item LifePotion("����ҩˮ", true, CANTREAT, LIFEPOTION);

void ENERGYPOTION();
const Item EnergyPotion("����ҩˮ", true, NOCONDITION, ENERGYPOTION);

void POWERPOTION();
const Item PowerPotion("����ҩˮ", true, NOCONDITION, ENERGYPOTION);

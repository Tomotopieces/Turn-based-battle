#pragma once
#include"item.h"
#include"condition.h"
#include"itemEffect.h"


const Item itemLack("", false, NOCONDITION, NOEFFECT);

void LIFEPOTION(Entity&self, Entity&aim);
const Item LifePotion("����ҩˮ", true, CANTREAT, LIFEPOTION);

void ENERGYPOTION(Entity&self, Entity&aim);
const Item EnergyPotion("����ҩˮ", true, NOCONDITION, ENERGYPOTION);

void POWERPOTION(Entity&self, Entity&aim);
const Item PowerPotion("����ҩˮ", true, NOCONDITION, ENERGYPOTION);

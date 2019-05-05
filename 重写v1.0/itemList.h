#pragma once
#include"item.h"
#include"condition.h"
#include"itemEffect.h"


const Item itemLack("", false, NOCONDITION, NOEFFECT);

void LIFEPOTION(Entity&self, Entity&aim);
const Item LifePotion("生命药水", true, CANTREAT, LIFEPOTION);

void ENERGYPOTION(Entity&self, Entity&aim);
const Item EnergyPotion("能量药水", true, NOCONDITION, ENERGYPOTION);

void POWERPOTION(Entity&self, Entity&aim);
const Item PowerPotion("力量药水", true, NOCONDITION, ENERGYPOTION);

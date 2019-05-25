#pragma once
#include"buff.h"

class BuffEffectList
{
public:
	vector<void(*)(Entity&self, Entity&aim)>buffeffectList;
};
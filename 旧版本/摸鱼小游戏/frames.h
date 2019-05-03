#pragma once
#include<string>

using std::string;

//单位结构
struct entity {
	string name;
	int hp;
	int atk;
	int block;
	int def;

	int coin;
	int lvl;
	int exp;
	int expMax;

	string img;
};

extern entity temp_p, temp_e;//临时结构
extern entity player_d;
extern entity player;
extern entity enemy[];

enum _type { weapon, armor };
struct equipment {
	string name;
	int atk;
	int def;
	int price;
	_type type;
};
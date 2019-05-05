#include"frames.h"


entity temp_p, temp_e;//临时结构
entity player_d{ "empty",20,2,0,1,20,1,0,50 };
entity player{};
entity enemy[]{
	{ "魔王",50,3,0,2,50,99,100,0,
	"     │╲                       ╱│\n     │ │                     │ │\n     │ │      __      __     │ │\n     │  ╲ __╱   ╲ __╱   ╲ __╱  │\n      ╲ ____              ____╱\n           │      ║      │\n            ╲     ║     ╱\n             │    ╬    │\n              ╲   __  ╱\n               │ │ │ │\n                ╲│ │╱\n"
	},
	{ "小偷",20,1,0,1,5,1,10,0,
	"               ╱ ╲     ╱ ╲\n               ╲   ╲ ╱ ╱ ╱\n               ╱ ╲ ╱ ╲ ╱\n             ╱╱    ╲ ╱ ╲\n           ╱╱        ╲   ╲\n          ││         ╱ ╲ ╱\n          ││       ╱\n          ││     ╱\n          ││   ╱\n          ││ ╱\n          │╱\n"
	}
};

equipment sword{ "锈蚀短剑",1,0,15,weapon };
equipment shield{ "木制圆盾",0,1,15,armor };
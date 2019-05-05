#include"entityList.h"

//原型机
Entity proto
{ "NULL",20,0,1,1,10,1,0,
"     ╱ ╲     ╱ ╲n     ╲   ╲ ╱ ╱ ╱n     ╱ ╲ ╱ ╲ ╱n   ╱╱    ╲ ╱ ╲n ╱╱        ╲   ╲n││         ╱ ╲ ╱n││       ╱n││     ╱n││   ╱n││ ╱n│╱n"
};
Entity player = proto;

//敌人
Entity enemys[]
{
	{ "小偷",20,0,1,1,5,1,10,
	"     ╱ ╲     ╱ ╲n     ╲   ╲ ╱ ╱ ╱n     ╱ ╲ ╱ ╲ ╱n   ╱╱    ╲ ╱ ╲n ╱╱        ╲   ╲n││         ╱ ╲ ╱n││       ╱n││     ╱n││   ╱n││ ╱n│╱n"
	},
	{ "魔王",50,0,3,2,50,99,100,
	"│╲                       ╱│n│ │                     │ │n│ │      __      __     │ │n│  ╲ __╱   ╲ __╱   ╲ __╱  │n ╲ ____              ____╱n      │      ║      │n       ╲     ║     ╱n        │    ╬    │n         ╲   __  ╱n          │ │ │ │n           ╲│ │╱n"
	},
	{"食堂泼辣酱",99,0,99,99,1000,999,1000,
	"          __ n    __  __╲ ╲ n    ╲ ╲ ╲ ╲│ │╱│ __ n __│╲│ │ │    ╱  ╲ ╲ n ╲ ╲╲_╲ ╲│ │ │  _╱ ╱ n   ╲  ╲│  ╱  │╱  ╱ n    │──── []────│ n    │ ┗━━   ━━┛ │ n    │  ╘═   ═╛  │ n    │╲         ╱│ n    │ │   __  │ │ n     ╲ ╲ ____╱ ╱ n       ╲│ __│╱ n"
	}
};
Entity enemy = enemys[0];
#include"EntityList.h"

Entity proto
{ "NULL",20,0,1,1,10,1,0,
"     ¨u ¨v     ¨u ¨vn     ¨v   ¨v ¨u ¨u ¨un     ¨u ¨v ¨u ¨v ¨un   ¨u¨u    ¨v ¨u ¨vn ¨u¨u        ¨v   ¨vn©¦©¦         ¨u ¨v ¨un©¦©¦       ¨un©¦©¦     ¨un©¦©¦   ¨un©¦©¦ ¨un©¦¨un"
};
Entity currentPlayer = proto;

Entity enemys[]
{
	{ "Ð¡Íµ",20,0,1,1,5,1,10,
	"     ¨u ¨v     ¨u ¨vn     ¨v   ¨v ¨u ¨u ¨un     ¨u ¨v ¨u ¨v ¨un   ¨u¨u    ¨v ¨u ¨vn ¨u¨u        ¨v   ¨vn©¦©¦         ¨u ¨v ¨un©¦©¦       ¨un©¦©¦     ¨un©¦©¦   ¨un©¦©¦ ¨un©¦¨un"
	},
	{ "Ä§Íõ",50,0,3,2,50,99,100,
	"©¦¨v                       ¨u©¦n©¦ ©¦                     ©¦ ©¦n©¦ ©¦      __      __     ©¦ ©¦n©¦  ¨v __¨u   ¨v __¨u   ¨v __¨u  ©¦n ¨v ____              ____¨un      ©¦      ¨U      ©¦n       ¨v     ¨U     ¨un        ©¦    ¨p    ©¦n         ¨v   __  ¨un          ©¦ ©¦ ©¦ ©¦n           ¨v©¦ ©¦¨un"
	},
	{"StarPlutinum",99,0,99,99,1000,999,1000,
	"          __ n    __  __¨v ¨v n    ¨v ¨v ¨v ¨v©¦ ©¦¨u©¦ __ n __©¦¨v©¦ ©¦ ©¦    ¨u  ¨v ¨v n ¨v ¨v¨v_¨v ¨v©¦ ©¦ ©¦  _¨u ¨u n   ¨v  ¨v©¦  ¨u  ©¦¨u  ¨u n    ©¦©¤©¤©¤©¤ []©¤©¤©¤©¤©¦ n    ©¦ ©»©¥©¥   ©¥©¥©¿ ©¦ n    ©¦  ¨\¨T   ¨T¨_  ©¦ n    ©¦¨v         ¨u©¦ n    ©¦ ©¦   __  ©¦ ©¦ n     ¨v ¨v ____¨u ¨u n       ¨v©¦ __©¦¨u n"
	}
};
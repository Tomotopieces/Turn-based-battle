#include "battle.h"
#include"BaseFeature.h"
#include"entity.h"

void BattleUI::printEntity(const entity & unit, int x, int y)
{
	Cursor.set(x, y);
	for (int i = 0; i < unit.Img().size(); ++i) {
		if (unit.Img()[i] != 'n')
			cout.put(unit.Img()[i]);
		else
			Cursor.set(x, ++y);
	}
}

void BattleUI::printBox()
{
	Cursor.set(0, 25);
	cout << "┌";
	Cursor.set(126, 25);
	cout << "┐";
	Cursor.set(0, 35);
	cout << "└";
	Cursor.set(126, 35);
	cout << "┘";
	for (int y = 27; y < 34; ++y) {
		Cursor.set(14, y);
		cout << "│";
		Cursor.set(95, y);
		cout << "│";
	}
	Cursor.set(4, 28);
	cout << "战斗";
	Cursor.set(4, 30);
	cout << "道具";
	Cursor.set(4, 32);
	cout << "逃跑";
	Cursor.set(104, 28);
	cout << "......";
	Cursor.set(104, 30);
	cout << "......";
	Cursor.set(104, 32);
	cout << "......";
}

void BattleUI::initBattleUI()
{
	Cursor.set(8, 2);
	cout << player.Name();
	cout.width(16);
	Cursor.set(100, 2);
	cout << enemy.Name();
	Cursor.set(8, 3);
	cout << "HP: "; cout.width(2); cout << player.CurrentHp() << "/" << player.Hp();
	Cursor.set(100, 3);
	cout.width(11); cout << "HP: "; cout.width(2); cout << enemy.CurrentHp() << "/" << enemy.Hp();
	printEntity(player, 16, 8);
	printEntity(enemy, 85, 8);
	printBox();
}

void battle()
{
	using namespace BattleUI;
	system("cls");
	//初始化双方数据
	player.Init();
	enemy.Init();
	//打印图案不循环
	initBattleUI();
	//战斗循环
	while (1) {

		while (1);
	}
}

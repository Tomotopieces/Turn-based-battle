#include"GameFeature.h"
#include<iostream>
int main() {
	
	startup();
	
	hall();
	return 0;
}

/*

std::ifstream fin;
std::ofstream fout;

int sel = 1;

//防误选
int select(int options) {
	int i = 0;
	cin >> i;
	while (i < 1 || i > options || !cin) {
		cin.clear();
		cin.ignore();
		cout << "\t";
		cin >> i;
	}
	return i;
}

//主页
void hall() {
	system("cls");
	bool loop = true;
	while (loop) {
		system("mode con cols=60 lines=15");
		PlaySound(TEXT("rest.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP | SND_NODEFAULT);
		cout << "\n\t欢迎!" << player.Name() << endl;
		cout << "\t生命:" << player.Hp() << "\t\t等级:" << player.Lvl() << "\t\t经验:" << player.Exp() << "/" << player.MaxExp() << "\n\t金币:" << player.Coin() << endl;
		cout << "\n\t接下来想做什么?\n\t1.战斗\t\t2.改名\t\t3.存档\n\t4.商店\t\t5.退出\n\t";
		switch (select(4)) {
			case 1: {
				battle();
				break;
			}
			case 2: {cout << "\n\t输入新昵称:\n\t";
				string name;
				cin >> name;
				player.Rename(name);
				break;
			}
			case 3: {
				saveData();
				system("cls");
				cout << "\n\t存档成功" << endl;
				Sleep(500);
				break;
			}
			case 4: {
				loop = false;
				break;
			}
			case 5: {
				loop = false;
				break;
			}
		}
	}
}

//商店
void shop() {
	system("cls");
	cout << "\n\t欢迎你！远道而来的旅人。\n\t需要点什么吗？\n\n\t1.锈蚀短剑\t\t2.木制圆盾\t\t3.离开";
	switch (select(3)) {
		case 1: {

			break;
		}
		case 2: {
			break;
		}
		case 3: {
			break;
		}
	}
}

//升级判定
void expJudge() {
	while (player.Exp() >= player.MaxExp()) {
		player.updateExp(-1 * player.MaxExp());
		player.lvlUp();
		system("cls");
		system("mode con cols=60 lines=15");
		cout << "\n\t恭喜升级到LV." << player.Lvl() << "!" << endl;
		cout << "\t选择一项祝福!\n\t1.攻击力+1\t2.防御力+1\t3.获得" << player.Lvl() * 20 << "金币!" << endl;
		cout << "\t";
		switch (select(3)) {
			case 1: {
				player.updateAtk(1);
				break;
			}
			case 2: {
				player.updateDef(1);
				break;
			}
			case 3: {
				player.updateCoin(player.Lvl() * 20);
				break;
			}
		}
		expJudge();
	}
}

bool result = 1;//结果胜负判定
int turn = 1;//回合判定
int dam = 0;//伤害
string message[2]{};//信息输出

//我方技能
void skill_p(int s) {
	switch (s) {
		case 1: {
			int damage = 0;
			player.Atk(enemy, damage);
			message[0] = "\t你进行了攻击!";
			break;
		}
		case 2: {
			player.Blk();
			message[0] = "\t你进行了防御!";
			break;
		}
		case 3: {
			result = 0;
			break;
		}
	}
	enemy.ClrBlk();
}

//敌人技能
void skill_e() {
	switch (rand() % 2) {
		case 1: {
			int damage = 0;
			enemy.Atk(player, damage);
			message[1] = "\t" + enemy.Name() + "进行了攻击!";
			break;
		}
		case 0: {
			enemy.Blk();
			message[1] = "\t" + enemy.Name() + "进行了防御!";
			break;
		}
	}
	player.ClrBlk();
}

//战斗函数
void battle() {
	PlaySound(TEXT("battle.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP | SND_NODEFAULT);
	system("cls");
	enemy = enemys[0 ? 1 : rand() % 10];
	player.Init();
	message[0] = message[1] = "";//战斗消息初始化
	turn = 1;//回合判定初始化
	result = 1;//胜负判定初始化
	system("mode con cols=38 lines=35");
	while (true) {//循环部分
		system("cls");
		cout << "\n\n\t\t" << enemy.Name() << endl;
		cout << "\t\tLV." << enemy.Lvl() << endl;
		cout << "\n\t生命:" << enemy.CurrentHp() << "\t攻击:" << enemy.CurrentAtk() << "\t格挡:" << enemy.CurrentBlock() << endl;
		cout << endl;
		cout << player.Img() << endl;
		cout << "\n\n\t" << player.Name() << "\tLV." << player.Lvl() << endl;
		cout << "\n\t生命:" << player.CurrentHp() << "\t攻击:" << player.CurrentAtk() << "\t格挡:" << player.CurrentBlock() << endl << endl;
		cout << "--------------------------------------" << endl;
		cout << "--------------------------------------" << endl;
		cout << "\n\t1.攻击\t2.防御\t3.逃跑" << endl;
		if (turn == 1) {
			cout << "\t";
			skill_p(select(3));
			turn = 2;
		}
		else if (turn == 2) {
			skill_e();
			cout << endl << message[0] << endl;
			Sleep(1000);
			turn = 3;
		}
		else if (turn == 3) {
			cout << endl << message[0] << endl;
			cout << message[1] << endl;
			message[0] = message[1] = "";
			Sleep(1000);
			turn = 1;
		}
		if (enemy.CurrentHp() <= 0 || player.CurrentHp() <= 0 || sel == 3)break;
	};
	if (player.CurrentHp() <= 0)result = 0;
	if (result) {
		cout << "\t你打败了" << enemy.Name() << "!" << endl;
		player.updateExp(enemy.Exp());
		cout << "\t获得了" << enemy.Coin() << "金币!" << endl;
		player.updateCoin(enemy.Coin());
		expJudge();
	}
	else cout << "\t你败在了" << enemy.Name() << "的手下!" << endl;
	Sleep(1200);
	system("cls");
}

//存档
void saveData() {
	fout.open("save");
	fout << player.Name() << " "
		<< player.Hp() << " "
		<< player.Atk() << " "
		<< player.Def() << " "
		<< player.Coin() << " "
		<< player.Lvl() << " "
		<< player.Exp() << " "
		<< player.MaxExp() << " ";
	fout.close();
}

//读档
void loadData() {
	fin.open("save");
	if (fin.is_open()) {
		string name;
		int hp;
		int atk;
		int def;
		int coin;
		int lvl;
		int exp;
		int maxExp;
		fin >> name
			>> hp
			>> atk
			>> def
			>> coin
			>> lvl
			>> exp
			>> maxExp;
		entity temp(name, hp, atk, def, coin, lvl, exp, proto.Img());
		fin.close();
	}
	else {
		fin.close();
		cout << "\n\t输入昵称:\n\t";
		string name;
		cin >> name;
		player.Rename(name);
		saveData();
	}
}

*/
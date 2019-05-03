#include<iostream>
#include<fstream>
#include<string>
#include<Windows.h>
#include<ctime>
#include<stdio.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")
using namespace std;
ifstream fin;
ofstream fout;

int sel = 1;

void selwr(int options) {//误选

	while (sel<1 || sel>options || !cin) {
		cin.clear();
		cin.ignore();
		cout << "\t";
		cin >> sel;
	}
}

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
}
temp_p, temp_e,//临时结构
player_d{ "empty",20,2,0,1,20,1,0,50 },
player,
enemy[2]{
	{ "魔王",50,3,0,2,50,99,100,0,
	"     │╲                       ╱│\n     │ │                     │ │\n     │ │      __      __     │ │\n     │  ╲ __╱   ╲ __╱   ╲ __╱  │\n      ╲ ____              ____╱\n           │      ║      │\n            ╲     ║     ╱\n             │    ╬    │\n              ╲   __  ╱\n               │ │ │ │\n                ╲│ │╱\n"
	},
{ "小偷",20,1,0,1,5,1,10,0,
"               ╱ ╲     ╱ ╲\n               ╲   ╲ ╱ ╱ ╱\n               ╱ ╲ ╱ ╲ ╱\n             ╱╱    ╲ ╱ ╲\n           ╱╱        ╲   ╲\n          ││         ╱ ╲ ╱\n          ││       ╱\n          ││     ╱\n          ││   ╱\n          ││ ╱\n          │╱\n"
}
};

void expJudge() {
	while (player.exp >= player.expMax) {
		player.exp -= player.expMax;
		player.lvl++;
		player.expMax += player.lvl * 30;
		system("cls");
		system("mode con cols=60 lines=15");
		cout << "\n\t恭喜升级到LV." << player.lvl << "!" << endl;
		cout << "\t选择一项祝福!\n\t1.攻击力+1\t2.防御力+1\t3.获得" << player.lvl * 20 << "金币!" << endl;
		cout << "\t"; cin >> sel;
		selwr(3);
		switch (sel) {
			case 1: {
				player.atk++;
				break;
			}
			case 2: {
				player.def++;
				break;
			}
			case 3: {
				player.coin += player.lvl * 20;
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

void skill_p(int s) {//我方技能
	switch (s) {
		case 1: {
			dam = temp_p.atk - temp_e.block;
			if (dam > 0)temp_e.hp -= dam;
			message[0] = "\t你进行了攻击!";
			break;
		}
		case 2: {
			temp_p.block += temp_p.def;
			message[0] = "\t你进行了防御!";
			break;
		}
		case 3: {
			result = 0;
			break;
		}
	}
	temp_e.block = 0;
}

void skill_e() {//敌人技能
	switch (rand() % 2) {
		case 1: {
			dam = temp_e.atk - temp_p.block;
			if (dam > 0)temp_p.hp -= dam;
			message[1] = "\t" + temp_e.name + "进行了攻击!";
			break;
		}
		case 0: {
			temp_e.block += temp_e.def;
			message[1] = "\t" + temp_e.name + "进行了防御!";
			break;
		}
	}
	temp_p.block = 0;
}

void battle() {//战斗函数
	PlaySound(TEXT("battle.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP | SND_NODEFAULT);
	system("cls");
	sel = rand() % 10;
	if (sel) sel = 1;
	temp_p = player, temp_e = enemy[sel];//战斗数据初始化
	message[0] = message[1] = "";//战斗消息初始化
	turn = 1;//回合判定初始化
	result = 1;//胜负判定初始化
	system("mode con cols=38 lines=35");
	while (true) {//循环部分
		system("cls");
		cout << "\n\n\t\t" << temp_e.name << endl;
		cout << "\t\tLV." << temp_e.lvl << endl;
		cout << "\n\t生命:" << temp_e.hp << "\t攻击:" << temp_e.atk << "\t格挡:" << temp_e.block << endl;
		cout << endl;
		cout << temp_e.img << endl;
		cout << "\n\n\t" << temp_p.name << "\tLV." << temp_p.lvl << endl;
		cout << "\n\t生命:" << temp_p.hp << "\t攻击:" << temp_p.atk << "\t格挡:" << temp_p.block << endl << endl;
		cout << "--------------------------------------" << endl;
		cout << "--------------------------------------" << endl;
		cout << "\n\t1.攻击\t2.防御\t3.逃跑" << endl;
		if (turn == 1) {
			cout << "\t";
			cin >> sel;
			selwr(3);
			skill_p(sel);
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
		if (temp_e.hp <= 0 || temp_p.hp <= 0 || sel == 3)break;
	};
	if (temp_p.hp <= 0)result = 0;
	if (result) {
		cout << "\t你打败了" << temp_e.name << "!" << endl;
		player.exp += temp_e.exp;
		cout << "\t获得了" << temp_e.coin << "金币!" << endl;
		player.coin += temp_e.coin;
		expJudge();
	}
	else cout << "\t你败在了" << temp_e.name << "的手下!" << endl;
	Sleep(1200);
	system("cls");
}

void saveData() {//存档
	fout.open("save");
	fout << player.name << " "
		<< player.hp << " "
		<< player.atk << " "
		<< player.block << " "
		<< player.def << " "
		<< player.coin << " "
		<< player.lvl << " "
		<< player.exp << " "
		<< player.expMax << " ";
	fout.close();
}

void loadData() {//读档
	fin.open("save");
	if (fin.is_open()) {
		fin >> player.name
			>> player.hp
			>> player.atk
			>> player.block
			>> player.def
			>> player.coin
			>> player.lvl
			>> player.exp
			>> player.expMax;
		fin.close();
	}
	else {
		fin.close();
		player = player_d;
		cout << "\n\t输入昵称:\n\t";
		cin >> player.name;
		saveData();
	}
}

void hall() {//主页
	system("cls");
	while (sel) {
		system("mode con cols=60 lines=15");
		PlaySound(TEXT("rest.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP | SND_NODEFAULT);
		cout << "\n\t欢迎!" << player.name << endl;
		cout << "\t生命:" << player.hp << "\t\t等级:" << player.lvl << "\t\t经验:" << player.exp << "/" << player.expMax << "\n\t金币:" << player.coin << endl;
		cout << "\n\t接下来想做什么?\n\t1.战斗\t\t2.改名\t\t3.存档\n\t4.退出\n\t";
		cin >> sel;
		selwr(4);
		switch (sel) {
			case 1: {
				battle();
				break;
			}
			case 2: {
				cout << "\n\t输入新昵称:\n\t";
				cin >> player.name;
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
				sel = 0;
				break;
			}
		}
	}
}

int main() {
	system("title  MoYu");
	system("mode con cols=35 lines=15");
	srand((unsigned)time(NULL));
	loadData();
	hall();
	saveData();
	return 0;
}
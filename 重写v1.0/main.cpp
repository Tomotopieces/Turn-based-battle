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

//����ѡ
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

//��ҳ
void hall() {
	system("cls");
	bool loop = true;
	while (loop) {
		system("mode con cols=60 lines=15");
		PlaySound(TEXT("rest.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP | SND_NODEFAULT);
		cout << "\n\t��ӭ!" << player.Name() << endl;
		cout << "\t����:" << player.Hp() << "\t\t�ȼ�:" << player.Lvl() << "\t\t����:" << player.Exp() << "/" << player.MaxExp() << "\n\t���:" << player.Coin() << endl;
		cout << "\n\t����������ʲô?\n\t1.ս��\t\t2.����\t\t3.�浵\n\t4.�̵�\t\t5.�˳�\n\t";
		switch (select(4)) {
			case 1: {
				battle();
				break;
			}
			case 2: {cout << "\n\t�������ǳ�:\n\t";
				string name;
				cin >> name;
				player.Rename(name);
				break;
			}
			case 3: {
				saveData();
				system("cls");
				cout << "\n\t�浵�ɹ�" << endl;
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

//�̵�
void shop() {
	system("cls");
	cout << "\n\t��ӭ�㣡Զ�����������ˡ�\n\t��Ҫ��ʲô��\n\n\t1.��ʴ�̽�\t\t2.ľ��Բ��\t\t3.�뿪";
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

//�����ж�
void expJudge() {
	while (player.Exp() >= player.MaxExp()) {
		player.updateExp(-1 * player.MaxExp());
		player.lvlUp();
		system("cls");
		system("mode con cols=60 lines=15");
		cout << "\n\t��ϲ������LV." << player.Lvl() << "!" << endl;
		cout << "\tѡ��һ��ף��!\n\t1.������+1\t2.������+1\t3.���" << player.Lvl() * 20 << "���!" << endl;
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

bool result = 1;//���ʤ���ж�
int turn = 1;//�غ��ж�
int dam = 0;//�˺�
string message[2]{};//��Ϣ���

//�ҷ�����
void skill_p(int s) {
	switch (s) {
		case 1: {
			int damage = 0;
			player.Atk(enemy, damage);
			message[0] = "\t������˹���!";
			break;
		}
		case 2: {
			player.Blk();
			message[0] = "\t������˷���!";
			break;
		}
		case 3: {
			result = 0;
			break;
		}
	}
	enemy.ClrBlk();
}

//���˼���
void skill_e() {
	switch (rand() % 2) {
		case 1: {
			int damage = 0;
			enemy.Atk(player, damage);
			message[1] = "\t" + enemy.Name() + "�����˹���!";
			break;
		}
		case 0: {
			enemy.Blk();
			message[1] = "\t" + enemy.Name() + "�����˷���!";
			break;
		}
	}
	player.ClrBlk();
}

//ս������
void battle() {
	PlaySound(TEXT("battle.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP | SND_NODEFAULT);
	system("cls");
	enemy = enemys[0 ? 1 : rand() % 10];
	player.Init();
	message[0] = message[1] = "";//ս����Ϣ��ʼ��
	turn = 1;//�غ��ж���ʼ��
	result = 1;//ʤ���ж���ʼ��
	system("mode con cols=38 lines=35");
	while (true) {//ѭ������
		system("cls");
		cout << "\n\n\t\t" << enemy.Name() << endl;
		cout << "\t\tLV." << enemy.Lvl() << endl;
		cout << "\n\t����:" << enemy.CurrentHp() << "\t����:" << enemy.CurrentAtk() << "\t��:" << enemy.CurrentBlock() << endl;
		cout << endl;
		cout << player.Img() << endl;
		cout << "\n\n\t" << player.Name() << "\tLV." << player.Lvl() << endl;
		cout << "\n\t����:" << player.CurrentHp() << "\t����:" << player.CurrentAtk() << "\t��:" << player.CurrentBlock() << endl << endl;
		cout << "--------------------------------------" << endl;
		cout << "--------------------------------------" << endl;
		cout << "\n\t1.����\t2.����\t3.����" << endl;
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
		cout << "\t������" << enemy.Name() << "!" << endl;
		player.updateExp(enemy.Exp());
		cout << "\t�����" << enemy.Coin() << "���!" << endl;
		player.updateCoin(enemy.Coin());
		expJudge();
	}
	else cout << "\t�������" << enemy.Name() << "������!" << endl;
	Sleep(1200);
	system("cls");
}

//�浵
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

//����
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
		cout << "\n\t�����ǳ�:\n\t";
		string name;
		cin >> name;
		player.Rename(name);
		saveData();
	}
}

*/
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

void selwr(int options) {//��ѡ

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
temp_p, temp_e,//��ʱ�ṹ
player_d{ "empty",20,2,0,1,20,1,0,50 },
player,
enemy[2]{
	{ "ħ��",50,3,0,2,50,99,100,0,
	"     ���v                       �u��\n     �� ��                     �� ��\n     �� ��      __      __     �� ��\n     ��  �v __�u   �v __�u   �v __�u  ��\n      �v ____              ____�u\n           ��      �U      ��\n            �v     �U     �u\n             ��    �p    ��\n              �v   __  �u\n               �� �� �� ��\n                �v�� ���u\n"
	},
{ "С͵",20,1,0,1,5,1,10,0,
"               �u �v     �u �v\n               �v   �v �u �u �u\n               �u �v �u �v �u\n             �u�u    �v �u �v\n           �u�u        �v   �v\n          ����         �u �v �u\n          ����       �u\n          ����     �u\n          ����   �u\n          ���� �u\n          ���u\n"
}
};

void expJudge() {
	while (player.exp >= player.expMax) {
		player.exp -= player.expMax;
		player.lvl++;
		player.expMax += player.lvl * 30;
		system("cls");
		system("mode con cols=60 lines=15");
		cout << "\n\t��ϲ������LV." << player.lvl << "!" << endl;
		cout << "\tѡ��һ��ף��!\n\t1.������+1\t2.������+1\t3.���" << player.lvl * 20 << "���!" << endl;
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

bool result = 1;//���ʤ���ж�
int turn = 1;//�غ��ж�
int dam = 0;//�˺�
string message[2]{};//��Ϣ���

void skill_p(int s) {//�ҷ�����
	switch (s) {
		case 1: {
			dam = temp_p.atk - temp_e.block;
			if (dam > 0)temp_e.hp -= dam;
			message[0] = "\t������˹���!";
			break;
		}
		case 2: {
			temp_p.block += temp_p.def;
			message[0] = "\t������˷���!";
			break;
		}
		case 3: {
			result = 0;
			break;
		}
	}
	temp_e.block = 0;
}

void skill_e() {//���˼���
	switch (rand() % 2) {
		case 1: {
			dam = temp_e.atk - temp_p.block;
			if (dam > 0)temp_p.hp -= dam;
			message[1] = "\t" + temp_e.name + "�����˹���!";
			break;
		}
		case 0: {
			temp_e.block += temp_e.def;
			message[1] = "\t" + temp_e.name + "�����˷���!";
			break;
		}
	}
	temp_p.block = 0;
}

void battle() {//ս������
	PlaySound(TEXT("battle.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP | SND_NODEFAULT);
	system("cls");
	sel = rand() % 10;
	if (sel) sel = 1;
	temp_p = player, temp_e = enemy[sel];//ս�����ݳ�ʼ��
	message[0] = message[1] = "";//ս����Ϣ��ʼ��
	turn = 1;//�غ��ж���ʼ��
	result = 1;//ʤ���ж���ʼ��
	system("mode con cols=38 lines=35");
	while (true) {//ѭ������
		system("cls");
		cout << "\n\n\t\t" << temp_e.name << endl;
		cout << "\t\tLV." << temp_e.lvl << endl;
		cout << "\n\t����:" << temp_e.hp << "\t����:" << temp_e.atk << "\t��:" << temp_e.block << endl;
		cout << endl;
		cout << temp_e.img << endl;
		cout << "\n\n\t" << temp_p.name << "\tLV." << temp_p.lvl << endl;
		cout << "\n\t����:" << temp_p.hp << "\t����:" << temp_p.atk << "\t��:" << temp_p.block << endl << endl;
		cout << "--------------------------------------" << endl;
		cout << "--------------------------------------" << endl;
		cout << "\n\t1.����\t2.����\t3.����" << endl;
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
		cout << "\t������" << temp_e.name << "!" << endl;
		player.exp += temp_e.exp;
		cout << "\t�����" << temp_e.coin << "���!" << endl;
		player.coin += temp_e.coin;
		expJudge();
	}
	else cout << "\t�������" << temp_e.name << "������!" << endl;
	Sleep(1200);
	system("cls");
}

void saveData() {//�浵
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

void loadData() {//����
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
		cout << "\n\t�����ǳ�:\n\t";
		cin >> player.name;
		saveData();
	}
}

void hall() {//��ҳ
	system("cls");
	while (sel) {
		system("mode con cols=60 lines=15");
		PlaySound(TEXT("rest.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP | SND_NODEFAULT);
		cout << "\n\t��ӭ!" << player.name << endl;
		cout << "\t����:" << player.hp << "\t\t�ȼ�:" << player.lvl << "\t\t����:" << player.exp << "/" << player.expMax << "\n\t���:" << player.coin << endl;
		cout << "\n\t����������ʲô?\n\t1.ս��\t\t2.����\t\t3.�浵\n\t4.�˳�\n\t";
		cin >> sel;
		selwr(4);
		switch (sel) {
			case 1: {
				battle();
				break;
			}
			case 2: {
				cout << "\n\t�������ǳ�:\n\t";
				cin >> player.name;
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
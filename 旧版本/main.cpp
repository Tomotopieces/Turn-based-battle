#include"features.h"
#include "..\��дv1.0\feature.h"

/* ��ҳ */
void hall();

int main() {
	system("title  MoYu");
	system("mode con cols=35 lines=15");
	srand((unsigned)time(NULL));
	loadData();
	hall();
	saveData();
	return 0;
}

//��ҳ
void hall() {
	system("cls");
	while (sel) {
		system("mode con cols=60 lines=15");
		PlaySound(TEXT("rest.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP | SND_NODEFAULT);
		cout << "\n\t��ӭ!" << player.name << endl;
		cout << "\t����:" << player.hp << "\t\t�ȼ�:" << player.lvl << "\t\t����:" << player.exp << "/" << player.expMax << "\n\t���:" << player.coin << endl;
		cout << "\n\t����������ʲô?\n\t1.ս��\t\t2.����\t\t3.�浵\n\t4.�̵�\t\t5.�˳�\n\t";
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
			case 5: {
				sel = 0;
				break;
			}
		}
	}
}
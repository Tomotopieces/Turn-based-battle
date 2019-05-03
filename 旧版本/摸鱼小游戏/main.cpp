#include"features.h"
#include "..\重写v1.0\feature.h"

/* 主页 */
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

//主页
void hall() {
	system("cls");
	while (sel) {
		system("mode con cols=60 lines=15");
		PlaySound(TEXT("rest.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP | SND_NODEFAULT);
		cout << "\n\t欢迎!" << player.name << endl;
		cout << "\t生命:" << player.hp << "\t\t等级:" << player.lvl << "\t\t经验:" << player.exp << "/" << player.expMax << "\n\t金币:" << player.coin << endl;
		cout << "\n\t接下来想做什么?\n\t1.战斗\t\t2.改名\t\t3.存档\n\t4.商店\t\t5.退出\n\t";
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
			case 5: {
				sel = 0;
				break;
			}
		}
	}
}
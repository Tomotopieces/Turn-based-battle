#include"header.h"
#include"BaseFeature.h"
#include"GameFeature.h"
#include"battle.h"
#include"entity.h"

void startup()
{
	/* �����мǵ�Ҫɾ�� */
	player.Rename("Tomoto");
	enemy = enemys[2];

	Screen.title("MoYu  V1.1");
	system("mode con cols=128 lines=36");
	Cursor.hide();
	srand((unsigned)time(NULL));
}

void hall() {
	system("cls");
	bool loop = true;
	while (loop) {
		system("mode con cols=128 lines=36");
		PlaySound(TEXT("hall.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP | SND_NODEFAULT);
		cout << "\n\t" << player.Name();
		cout << "\n\tLevel: " << player.Lvl() << "\tExp: " << player.Exp() << "/" << player.MaxExp();
		cout << "\n\n\t����ʲô��\n\t1.ս��\t2.�˳�\n\n\t";
		switch (select(2)) {
			case 1:
				battle();
				break;
			case 2:
				loop = 0;
				break;
		}
	}
}
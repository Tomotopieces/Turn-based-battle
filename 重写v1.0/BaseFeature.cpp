#include"BaseFeature.h"
#include"header.h"

//����ѡ
int select(int options)
{
	int i = options;
	do {
		cin.clear();//�޸�cin״̬
		cin.sync();//���ʣ�໺��������
		cin >> i;
	} while (i <= 0 || i > options || !cin);
	return i;
}
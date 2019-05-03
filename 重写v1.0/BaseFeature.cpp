#include"BaseFeature.h"
#include"header.h"

//·ÀÎóÑ¡
int select(int options)
{
	int i = options;
	do {
		cin.clear();//ÐÞ¸´cin×´Ì¬
		cin.sync();//Çå¿ÕÊ£Óà»º³åÇøÄÚÈÝ
		cin >> i;
	} while (i <= 0 || i > options || !cin);
	return i;
}
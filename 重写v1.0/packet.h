#pragma once
#include"header.h"
#include"itemList.h"

class Packet
{
public:
	struct block			//背包格
	{
		Item item = Empty;
		unsigned int quantity = 0;

		bool use();
	};
	friend struct block;
private:
	vector<block>blocks;	//背包核心

	/* 整理背包 */
	void sortPacket();
public:
	Packet();
	~Packet() = default;

	/* 定位 */
	const block&operator[](int n);

	/* 获得物品 */
	bool get(Item&opponent, int&quantity);

	/* 丢弃物品 */
	bool drop(Item&opponent, unsigned int quantity);
};

extern Packet packet;
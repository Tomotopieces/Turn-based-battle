#pragma once
#include"header.h"
#include"item.h"

/* ���� */
class Packet
{
public:
	struct block			//������
	{
		Item item;
		unsigned int quantity;

		bool use();
	};
	friend struct block;
private:
	vector<block>blocks;	//��������

	/* ������ */
	void sortPacket();
public:
	Packet();
	~Packet() = default;

	/* ��λ */
	const block&operator[](int n);

	/* �����Ʒ */
	bool get(Item&opponent, int&quantity);

	/* ������Ʒ */
	bool drop(Item&opponent, unsigned int quantity);
};

extern Packet packet;

/* װ���� */
class Slot
{
private:

};
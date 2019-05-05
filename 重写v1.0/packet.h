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

		bool useTo(Entity&aim);
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
	bool get(Item&aim, int&quantity);

	/* ������Ʒ */
	bool drop(Item&aim, unsigned int quantity);
};

extern Packet packet;
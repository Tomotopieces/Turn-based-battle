#include "packet.h"
Packet packet;

void Packet::sortPacket()
{
	for (auto it = blocks.begin(); it != blocks.end(); ++it) {
		if (0 == it->quantity) {
			blocks.erase(it);
			blocks.push_back({ Empty,0 });
			it--;
		}
	}
}

Packet::Packet()
{
	blocks.resize(20);
}

const Packet::block & Packet::operator[](int n)
{
	return blocks[n];
}

bool Packet::get(Item & opponent, int&quantity)
{
	for (auto it = blocks.begin(); it != blocks.end(); ++it) {
		//���ø�Ϊ��
		if (it->item == Empty) {
			it->item = opponent;
			it->quantity = quantity;
			return true;
		}
		//������ͬ������
		else if (it->item == opponent) {
			//���õ��߿ɵ���
			if (it->item.Stackable()) {
				//���ø�ĵ�������С��64
				if (it->quantity < 64) {
					//�������ĵ����������ڻ����64
					if (it->quantity + quantity <= 64) {
						//������������
						it->quantity += quantity;
						return true;
					}
					//�������ĵ�����������64
					else {
						//����ʣ�������
						quantity = 64 - it->quantity;
						it->quantity = 64;
						//��һ��Ѱ��
						continue;
					}
				}
				//���ø�ĵ�����������64���������������ѭ������
			}
			//���õ��߲��ε��ӣ������ѭ������
		}
	}
	return false;
}

bool Packet::drop(Item & opponent, unsigned int quantity)
{
	for (auto it = blocks.begin(); it != blocks.end(); ++it) {
		//���ø�Ϊ�գ�˵���޸�����ߣ�
		if (it->item == Empty) {
			//����ʧ��
			return false;
		}
		//���ҵ�ͬ������
		if (it->item == opponent) {
			//��������ȷ
			if (it->quantity >= quantity) {
				it->quantity -= quantity;
			}
			//����������		��Ϊȫ������
			else {
				it->quantity = 0;
			}
			sortPacket();
			return true;
		}
	}
	//δ�ҵ�����		����ʧ��
	return false;
}

bool Packet::block::use()
{
	if (item.use()) {
		quantity--;
		if (0 == quantity) {
			packet.sortPacket();
		}
	}
}

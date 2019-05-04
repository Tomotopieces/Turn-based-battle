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
		//若该格为空
		if (it->item == Empty) {
			it->item = opponent;
			it->quantity = quantity;
			return true;
		}
		//若存在同名道具
		else if (it->item == opponent) {
			//若该道具可叠加
			if (it->item.Stackable()) {
				//若该格的道具数量小于64
				if (it->quantity < 64) {
					//若增添后的道具数量少于或等于64
					if (it->quantity + quantity <= 64) {
						//道具数量增加
						it->quantity += quantity;
						return true;
					}
					//若增添后的道具数量大于64
					else {
						//计算剩余道具数
						quantity = 64 - it->quantity;
						it->quantity = 64;
						//新一轮寻找
						continue;
					}
				}
				//若该格的道具数量等于64（已满），则继续循环检索
			}
			//若该道具补课叠加，则继续循环检索
		}
	}
	return false;
}

bool Packet::drop(Item & opponent, unsigned int quantity)
{
	for (auto it = blocks.begin(); it != blocks.end(); ++it) {
		//若该格为空（说明无更多道具）
		if (it->item == Empty) {
			//丢弃失败
			return false;
		}
		//若找到同名道具
		if (it->item == opponent) {
			//若数量正确
			if (it->quantity >= quantity) {
				it->quantity -= quantity;
			}
			//若数量过大		视为全部丢弃
			else {
				it->quantity = 0;
			}
			sortPacket();
			return true;
		}
	}
	//未找到道具		丢弃失败
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

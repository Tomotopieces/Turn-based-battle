#pragma once
#include"Buff.h"

/*
	每个单位的增益列表
*/

class BuffList
{
private:
	std::vector<Buff>buffList;

	/* 定位 */
	std::vector<Buff>::iterator Locate(Buff&buff);//返回的是迭代器
public:
	BuffList() = default;
	~BuffList() = default;
	BuffList&operator=(BuffList&copy);

	/*********************	增删查	*********************/

	/* 存在判断 */
	bool Exist(Buff&buff);

	/* 获得增益 */
	BuffList&Get(Buff&buff);

	/* 删除增益 */
	BuffList&Delete(Buff&buff);
};

//Buff不存在
extern Buff Lost;
extern Buff Normal;

//无法治疗
extern Buff CantTreat;
//伤口
extern Buff Wound;
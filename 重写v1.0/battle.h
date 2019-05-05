#pragma once
#include<string>
#include"entity.h"

/* 战斗函数 */
void battle();

namespace BattleUI {

	/* 打印实体 */
	void printEntity(const Entity&unit, int x, int y);

	/* 打印选择框 */
	void printBox();

	/* 初始化战斗界面UI*/
	void initBattleUI();
}

/*
战斗逻辑：
	主体函数：
		初始化UI函数：
			打印双方名称及血量；
			打印图像函数；
			打印选择框及文字；
		初始化行动链；
		初始化双方数据；
		战斗循环流程：
			敌方确定技能；
			显示敌方意图；
			我方回合：
				选择战斗或道具：
					循环:
						1.选择某项技能或道具；
							↓
						2.选择填入的行动框；
							↓
						3.回到1；
					判断产生的combo；
					行动与combo函数加入行动链；
					遍历行动链：
						行动函数；
						更新并打印消息；
						如果结束：
							更新并打印消息；
				逃跑：
					更新并打印消息；
					判负并进入结束结算；
			清空行动链；
			敌方回合：
				行动函数；
				更新并打印消息；
				如果结束：
					更新并打印消息；
		结束结算：
			胜利：
				升级判定：
					如果升级：
						升级奖励函数；
					经验值更新；
				金币更新；
			失败；
*/
#pragma once
#include"header.h"

/******************************************/
/* 使用条件 */

/* 无条件 */
bool NOCONDITION();

/* 可以被治疗 */
bool CANTREAT();

/* 正在使用剑类武器 */
bool USINGSWORD();

/* 达到等级n */
bool LEASTLEVEL(int n);
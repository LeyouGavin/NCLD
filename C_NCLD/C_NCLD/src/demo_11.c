/**
*	@file		demo_11.c
*	@brief		数据类型转换注意
*	@author		嵌入式男单第九名
**************************************************/

#include <stdio.h>
#include "demo_11.h"

void demo_11(void)
{
	printf(DEMO_11);

	float fNum = -10.0f;
	unsigned int uiNum = 0;

	printf("%.2f\n", fNum);

	uiNum = (unsigned int)fNum;
	printf("%08X\n", uiNum);

#pragma warning(disable:4244)	/* 屏蔽 C4244 警告 */
	uiNum = fNum;
	printf("%08X\n", uiNum);
#pragma warning(default:4244)   /* 使能 C4244 警告 */

	uiNum = (int)fNum;
	printf("%08X\n", uiNum);
}

/**
*	@file		demo_9.c
*	@brief		字节对齐
*	@author		嵌入式男单第九名
**************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "demo_9.h"

void demo_9(void)
{
	printf(DEMO_9);

	printf("将10字节内存按4字节向左对齐后的首地址为%d\n", ALIGN_LEFT(10, 4));
	printf("将10字节内存按4字节向右对齐后的首地址为%d\n\n", ALIGN_RIGHT(10, 4));

	struct _stExample1 {
		unsigned char ucEle;
		unsigned short usEle;
		unsigned int uiEle;
	};
	printf("示例1结构体占用%d字节\n", sizeof(struct _stExample1));

	struct _stExample2 {
		unsigned char ucEle;
		unsigned int uiEle;
		unsigned short usEle;

	};
	printf("示例2结构体占用%d字节\n", sizeof(struct _stExample2));

#pragma pack(1)
	struct _stExample3 {
		unsigned char ucEle;
		unsigned int uiEle;
		unsigned short usEle;
	};
#pragma pack()
	printf("示例3结构体占用%d字节\n", sizeof(struct _stExample3));

	struct _stExample4 {
		unsigned char ucEle;
		unsigned short usEle;
		struct _stExample5 {
			float fEle;
			double dEle;
		} stEle;
		unsigned int uiEle;
	};
	printf("示例4结构体占用%d字节\n", sizeof(struct _stExample4));

	void* myMemAddr = malloc(sizeof(struct _stExample4));
	memset(myMemAddr, 0, sizeof(struct _stExample4));
	struct _stExample4* stExample4 = (struct _stExample4*)myMemAddr;
	stExample4->stEle.fEle = 3.f;
	printf("示例4结构体浮点型数据所在内存位置%.2f\n", *((float*)myMemAddr + 2));
	free(myMemAddr);
}

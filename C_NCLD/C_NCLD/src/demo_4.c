/**
*	@file		demo_4.c
*	@brief		指针常量与结构体常量
*	@author		嵌入式男单第九名
**************************************************/

#include <stdio.h>
#include "demo_4.h"

int dataInit = 0x11;
int dataProc = 0xAA;
int dataEnd = 0xFF;
static int_data_t int_data[2];

/*
* 创建结构体对象时，必须对其指针常量进行初始化，
* 否则结构体对象创建后，指针常量的指向不可继续变更，
* 且其元素不可访问（地址异常）。
*
* 建议对常量变量（const int）进行初始化，
* 否则结构体对象创建后，常量变量数值不可再变更，
* 访问其值无意义。
*
* 建议对所有变量进行初始化。
*
* 好习惯是进步的开始，必须对所有变量初始化！
*/
const_test_t const_test1 =
{
	.c_data = 0x00,			/* const int */
	.ipc_data = &dataInit,	/* int* const */
	.icpc_data = &dataInit	/* int* const* */
};

const_test_t const_test2 = {
	0x00,		/* int 全局变量必须用数值常量初始化 */
				/*     局部变量可用变量初始化 */
	0x00,		/* const int */
	&dataInit,	/* int* */
	&dataInit,	/* int const* */
	&dataInit,	/* int* const */
	&dataInit,	/* int* const* */
	&int_data[0]/* struct* */
};

const const_test_hdl_t g_handles[2] =
{
	&const_test1,
	&const_test2
};


void demo_4(void)
{
	printf(DEMO_4);

	int_data[0].data = dataInit;
	int_data[0].p_data = &dataInit;
	g_handles[0]->data = dataInit;
	g_handles[0]->p_data = &dataInit;
	g_handles[0]->icp_data = &dataInit;
	g_handles[0]->int_data = &int_data[0];
	func1(g_handles[0]);

	int_data[1].data = dataEnd;
	int_data[1].p_data = &dataEnd;
	func2(&g_handles[0]->int_data);
}


void func1(const const_test_hdl_t p_hdl)
{
	printf("dataInit dataProc dataEnd || ");
	printf("data c_data *p_data *icp_data *ipc_data *icpc_data\n");
	printf("% 5X% 9X% 9X   ||", dataInit, dataProc, dataEnd);
	printf("% 4X% 5X% 9X% 9X% 10X% 10X\n", p_hdl->data, p_hdl->c_data, *(p_hdl->p_data),
		*(p_hdl->icp_data), *(p_hdl->ipc_data), *(p_hdl->icpc_data));

	printf("                 icp_data = &dataProc\n");
	p_hdl->icp_data = &dataProc;
	printf("% 5X% 9X% 9X   ||", dataInit, dataProc, dataEnd);
	printf("% 4X% 5X% 9X% 9X% 10X% 10X\n", p_hdl->data, p_hdl->c_data, *(p_hdl->p_data),
		*(p_hdl->icp_data), *(p_hdl->ipc_data), *(p_hdl->icpc_data));

	printf("                 *(ipc_data) = dataProc\n");
	*(p_hdl->ipc_data) = dataProc;
	printf("% 5X% 9X% 9X   ||", dataInit, dataProc, dataEnd);
	printf("% 4X% 5X% 9X% 9X% 10X% 10X\n", p_hdl->data, p_hdl->c_data, *(p_hdl->p_data),
		*(p_hdl->icp_data), *(p_hdl->ipc_data), *(p_hdl->icpc_data));
}


void func2(int_data_hdl_t* const p_hdl)
{
	int_data_hdl_t p_idcb = &int_data[1];
	*p_hdl = p_idcb;

	printf("\n\n");
	printf("(*p_hdl)->data = %02X\n", (*p_hdl)->data);
	printf("*(p_idcb->p_data) = %02X\n", *(p_idcb->p_data));
}

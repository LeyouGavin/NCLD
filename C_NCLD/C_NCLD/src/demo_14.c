/**
*	@file		demo_14.c
*	@brief		不定参数函数
*	@author		嵌入式男单第九名
**************************************************/

#include <stdio.h>
#include <stdarg.h>
#include "demo_14.h"

void myfunc(const unsigned char *pucPara1, ...);
//void myfunc(const char *format, ...) __attribute__((format(printf, 1, 2)));

void demo_14(void)
{
	printf(DEMO_14);

	myfunc("Hello Gavin\n", 0x5555, 0xAAAA);
}

void myfunc(const unsigned char *pucPara1, ...)
{
	va_list argp = 0;
	int iPara = 0;

	while(*pucPara1)
	{
		if(*pucPara1 != '\n')
		{
			printf("%c", *pucPara1);
		}
		else
		{
			printf("\n");
		}
		pucPara1++;
	}
	
	va_start(argp, pucPara1);	/**< 从必要参数pucPara1之后为可变参数 */
	
	iPara = va_arg(argp, int);	/**< 第一个可选参数为int类型，类型不可为float */
	printf("第二个参数是0x%04X\n", iPara);

	iPara = va_arg(argp, int);	/**< 第二个可变参数为int类型 */
	printf("第三个参数是0x%04X\n", iPara);

	va_end(argp);				/**< 释放 */
}

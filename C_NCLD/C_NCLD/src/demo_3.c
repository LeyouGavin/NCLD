/**
*	@file		demo_3.c
*	@brief		函数指针与回调函数
*	@author		嵌入式男单第九名
**************************************************/

#include <stdio.h>
#include "demo_3.h"

void demo_3(void)
{
	printf(DEMO_3);

	char *str = "函数指针调用实现： ";

	p_func1 = &functionA;		/**< 函数指针的赋值方法1 */
	p_func2 = functionB;		/**< 函数指针的赋值方法2（编译器会隐式转换） */

	p_func1(1, str);			/**< 函数指针的调用方法1 */
	(*p_func2)(2, str);			/**< 函数指针的调用方法2 */

	callFunc1(functionA, str);	/**< 回调函数的实现1 */
	callFunc2(functionA, str);	/**< 回调函数的实现2 */
}


void functionA(int num, char *str)
{
	printf("functionA %s%d\n", str, num);
	return;
}


void functionB(int num, char *str)
{
	printf("functionB %s%d\n", str, num);
	return;
}


void callFunc1(callback p_callback, char *str)
{
	p_callback(3, str);
	return;
}


void callFunc2(void(*ptr)(int num, char *str),char *str)
{
	ptr(4, str);
	return;
}

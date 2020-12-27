/**
*	@file		main.c
*	@brief		实现基础编程函数的测试调用
*	@author		嵌入式男单第九名
**************************************************/

#include <stdio.h>
#include "demo_n.h"

/**
*	@brief		main入口函数
*	@details	程序唯一入口
*	@param[in]	argc	命令参数个数
*	@param[in]	argv[]	命令参数指针数组
*	@return		程序执行成功与否
*		@retval	0	成功
*		@retval 1	失败
**************************************************/
int main(int argc, char *argv[])
{
	demo_n();		/**< 调用demo_n函数 */

	getchar();		/**< 等待退出 */

	return 0;
}
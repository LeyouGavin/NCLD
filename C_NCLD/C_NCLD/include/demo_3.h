/**
*	@file		demo_3.h
*	@author		嵌入式男单第九名
*	@details	示例内容
*	-# 函数指针的使用方法
*	-# 回调函数的实现原理
**************************************************/
#pragma once

#define DEMO_3	"\n函数指针实现回调函数\n\n"

void(*p_func1)(int, char *str);				/**< 函数指针的定义方法1 */
typedef void(*callback)(int, char *str);	/**< 函数指针的定义方法2 */
callback p_func2;


/**
*	@brief		测试用例入口函数
*	@details	
*				1.介绍函数指针的定义、赋值及调用方法
*				2.通过函数指针实现回调函数	
**************************************************/
void demo_3(void);

/**
*	@brief		函数指针调用函数
*	@details	接收形参输入，并打印输入信息
**************************************************/
void functionA(int num, char *str);
void functionB(int num, char *str);
/**
*	@brief	函数指针实现回调函数
*	@details	
*			1.将函数指针作为形参传递给某函数callFunc
*			2.函数指针传递的函数即为回调函数
*			3.在callFunc中调用回调函数
**************************************************/
void callFunc1(callback p_callback, char *str);
void callFunc2(void(*ptr)(int num, char *str), char *str);

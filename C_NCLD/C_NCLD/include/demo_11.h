/**
*	@file		demo_11.h
*	@author		嵌入式男单第九名
*	@details	示例内容
*	-# Xilinx SDK开发环境下，将浮点型负数转换为无符号整型数据时，结果异常（为0）
*	-# MDK开发环境下，编译器选version5，不开启microLib，将浮点型负数转换为无符号整型数据时，结果异常（为0）
*	-# MDK开发环境下，编译器选version5，开启microLib，将浮点型负数转换为无符号整型数据时，结果异常（为绝对值）
*	-# https://docs.microsoft.com/en-us/cpp/preprocessor/warning?view=vs-2019
**************************************************/
#pragma once

#define DEMO_11	"\n数据类型转换注意\n\n"

/**
*	@brief		测试用例入口函数
*	@details	示例函数说明
**************************************************/
void demo_11(void);

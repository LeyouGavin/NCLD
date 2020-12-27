/**
*	@file		demo_9.h
*	@author		嵌入式男单第九名
*	@details	示例内容
*	-# 地址对齐计算方法
*	-# 地址对齐关键字的使用
*	-# 在上位机中模拟嵌入式地址分配的方法（将指定数据分配在指定地址）
**************************************************/
#pragma once

#define DEMO_9	"\n字节对齐\n\n"

/**
* @ingroup 宏定义
*
* @def ALIGN_RIGHT(size, align)
* 按给定的对齐字节数，向右对齐。
* 如ALIGN_RIGHT(10, 4)，返回值为4。
*/
#define ALIGN_RIGHT(size, align)	(((size) + (align) - 1) & ~((align) - 1))

/**
* @ingroup 宏定义
*
* @def ALIGN_LEFT(size, align)
* 按给定的对齐字节数，向左对齐。
* 如ALIGN_RIGHT(10, 4)，返回值为8。
*/
#define ALIGN_LEFT(size, align)		((size) & ~((align) - 1))

/**
*	@brief		测试用例入口函数
*	@details	示例函数说明
**************************************************/
void demo_9(void);

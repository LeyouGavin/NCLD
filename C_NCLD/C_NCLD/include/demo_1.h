/**
*	@file		demo_1.h
*	@author		嵌入式男单第九名
*	@details	参考链接
*	-# https://www.cnblogs.com/ricksteves/p/9899893.html
*	-# https://www.cnblogs.com/lsgxeva/p/10913024.html
**************************************************/
#pragma once

#define DEMO_1	"\n不同数据类型的内存占用（Bytes）\n\n"

typedef signed char INT8;	/**< char不能简单认为等于signed char，与编译器有关 */
typedef unsigned char UINT8;

typedef short INT16;		/**< short是short int的缩写，short在某些编译器下可能报错 */
typedef unsigned short UINT16;

typedef int INT32;			/**< int在16位系统上占2字节，在32或64位系统上占4字节 */
typedef unsigned int UINT32;

typedef long INT32L;		/**< long在32位系统上占4字节；在64位系统上因平台不同，有4字节、6字节和8字节三种 */
typedef unsigned long UINT32L;

typedef long long INT64;	/**< long long占8字节 */
typedef unsigned long long UINT64;


/**
*	@brief		测试用例入口函数
*	@details	
*				1.输出不同数据类型占用的字节个数
**************************************************/
void demo_1(void);

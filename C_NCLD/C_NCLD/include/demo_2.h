/**
*	@file		demo_2.h
*	@author		嵌入式男单第九名
*	@details	示例内容
*	-# 大小端模式下的数据存储情况
*	-# 数据传输过程中的类型转换
**************************************************/
#pragma once

#define DEMO_2	"\n按给定大小端选项进行数据类型转换\n\n"

#define BIG_ENDIAN 0		/**< 大端模式 */
#define LITTLE_ENDIAN 1		/**< 小端模式 */

/**
*	@union	un_flt_uchar
*	@brief	浮点型数据存储共用体
**************************************************/
union un_flt_uchar
{
	float f32;
	unsigned char buf[4];
}un_flt_uchar_t;

/**
*	@brief		测试用例入口函数
*	@details	按给定大小端选项进行数据类型转换
*	- 大端：高地址存放低字节, 低地址存放高字节。
*	- 小端：高地址存放高字节, 低地址存放低字节。
*
*	egg: 从内存地址为0x0000开始有以下数据：0x1234abcd
*
*	BigEndian:
*	低地址 -->　高地址
*	0x0000  0x0001  0x0002  0x0003
*	0x12    0x34    0xab    0xcd
*
*	LittleEndian :
*	低地址 -->　高地址
*	0x0000  0x0001  0x0002  0x0003
*	0xcd    0xab    0x34    0x12    
*
*	一般操作系统都是小端的，arm大小端都支持，默认是小端模式；
*	STM32是小端模式,51单片机是大端模式。
**************************************************/
void demo_2(void);

unsigned short U8toU16(unsigned char *pucU8, unsigned char littleEndian);
short U8toI16(unsigned char *pucU8, unsigned char littleEndian);
unsigned int U8toU32(unsigned char *pucU8, unsigned char littleEndian);
int U8toI32(unsigned char *pucU8, unsigned char littleEndian);
void U16toU8(unsigned short usU16, unsigned char *pucU8, unsigned char littleEndian);
void I16toU8(short sI16, unsigned char *pucU8, unsigned char littleEndian);
void U32toU8(unsigned int uiU32, unsigned char *pucU8, unsigned char littleEndian);
void I32toU8(int iI32, unsigned char *pucU8, unsigned char littleEndian);
float U8toFLT(unsigned char *pucU8, unsigned char littleEndian);
void FLTtoU8(float f32, unsigned char *pucU8, unsigned char littleEndian);

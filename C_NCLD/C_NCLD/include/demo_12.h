/**
*	@file		demo_12.h
*	@author		嵌入式男单第九名
*	@details	示例内容
*	-# C语言实现二维矩阵在一维数组中的存储及简单变换
*	-# C语言实现二维矩阵的顺时针、逆时针90度变换
*	-# C语言实现二维矩阵关于主对角线、次对角线的对称变换
**************************************************/
#pragma once

#define DEMO_12	"\n二维矩阵的旋转、翻转变换\n\n"

/**
*	@brief		测试用例入口函数
*	@details	示例函数说明
**************************************************/
void demo_12(void);

/**
*	@brief		打印矩阵
*	@details	支持方阵、非方阵的打印操作
**************************************************/
void showMatrix(const int* piMatSrc, int iMatW, int iMatH);

/**
*	@brief		矩阵顺时针旋转90度
*	@details	支持方阵、非方阵的旋转变换
**************************************************/
void clockwiseTrans(const int* piMatSrc, int iMatSrcW, int iMatSrcH, int* piMatDst);

/**
*	@brief		矩阵逆时针旋转90度
*	@details	支持方阵、非方阵的旋转变换
**************************************************/

void clockwiseAntiTrans(const int* piMatSrc, int iMatSrcW, int iMatSrcH, int* piMatDst);
/**
*	@brief		矩阵主对角线对称变换
*	@details
*				1.仅支持方阵
*				2.可看作矩阵顺时针旋转90度后做上下对称变换
*				3.可看作矩阵逆时针旋转90度后做左右对称变换
**************************************************/
void diagonalMainTrans(const int* piMatSrc, int iMatSrcW, int iMatSrcH, int* piMatDst);

/**
*	@brief		矩阵次对角线对称变换
*	@details
*				1.仅支持方阵
*				2.可看作矩阵逆时针旋转90度后做上下对称变换
*				3.可看作矩阵顺时针旋转90度后做左右对称变换
**************************************************/
void diagonalSubTrans(const int* piMatSrc, int iMatSrcW, int iMatSrcH, int* piMatDst);

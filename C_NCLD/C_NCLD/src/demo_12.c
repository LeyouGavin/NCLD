/**
*	@file		demo_12.c
*	@brief		二维矩阵的旋转、翻转变换
*	@author		嵌入式男单第九名
**************************************************/

#include <stdio.h>
#include "demo_12.h"

#define MATRIX_W (3)
#define MATRIX_H (3)

const int iMatSrc[MATRIX_W * MATRIX_H] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
int iMatDst[MATRIX_W * MATRIX_H] = { 0 };

void demo_12(void)
{
	printf(DEMO_12);

	printf("初始矩阵\n");
	showMatrix(iMatSrc, MATRIX_W, MATRIX_H);

	printf("顺时针旋转变换\n");
	clockwiseTrans(iMatSrc, MATRIX_W, MATRIX_H, iMatDst);
	showMatrix(iMatDst, MATRIX_H, MATRIX_W);

	printf("逆时针旋转变换\n");
	clockwiseAntiTrans(iMatSrc, MATRIX_W, MATRIX_H, iMatDst);
	showMatrix(iMatDst, MATRIX_H, MATRIX_W);

	printf("主对角线对称变换\n");
	diagonalMainTrans(iMatSrc, MATRIX_W, MATRIX_H, iMatDst);
	showMatrix(iMatDst, MATRIX_W, MATRIX_H);

	printf("次对角线对称变换\n");
	diagonalSubTrans(iMatSrc, MATRIX_W, MATRIX_H, iMatDst);
	showMatrix(iMatDst, MATRIX_W, MATRIX_H);
}

void showMatrix(const int* piMatSrc, int iMatW, int iMatH)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < iMatH; ++i)
	{
		for (j = 0; j < iMatW; ++j)
		{
			printf("%d\t", *(piMatSrc + i * iMatW + j));
		}
		printf("\n");
	}

	printf("\n");
}

void clockwiseTrans(const int* piMatSrc, int iMatSrcW, int iMatSrcH, int* piMatDst)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < iMatSrcW; ++i)
	{
		for (j = 0; j < iMatSrcH; ++j)
		{
			*(piMatDst + i * iMatSrcH + j) =
				*(piMatSrc + (iMatSrcH - j - 1) * iMatSrcW + i);
		}
	}
}

void clockwiseAntiTrans(const int* piMatSrc, int iMatSrcW, int iMatSrcH, int* piMatDst)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < iMatSrcW; ++i)
	{
		for (j = 0; j < iMatSrcH; ++j)
		{
			*(piMatDst + i * iMatSrcH + j) =
				*(piMatSrc + j * iMatSrcW + (iMatSrcW - i - 1));
		}
	}
}

void diagonalMainTrans(const int* piMatSrc, int iMatSrcW, int iMatSrcH, int* piMatDst)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < iMatSrcW; ++i)
	{
		for (j = 0; j < iMatSrcH; ++j)
		{
			*(piMatDst + i * iMatSrcH + j) =
				*(piMatSrc + (iMatSrcH - j - 1) * iMatSrcW + (iMatSrcW - i - 1));
		}
	}
}

void diagonalSubTrans(const int* piMatSrc, int iMatSrcW, int iMatSrcH, int* piMatDst)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < iMatSrcW; ++i)
	{
		for (j = 0; j < iMatSrcH; ++j)
		{
			*(piMatDst + i * iMatSrcH + j) =
				*(piMatSrc + j * iMatSrcW + i);
		}
	}
}

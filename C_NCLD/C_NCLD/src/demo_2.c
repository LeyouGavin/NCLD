/**
*	@file		demo_2.c
*	@brief		按给定大小端选项进行数据类型转换
*	@author		嵌入式男单第九名
**************************************************/

#include <stdio.h>
#include <string.h>
#include "demo_2.h"

void demo_2(void)
{
	printf(DEMO_2);

	unsigned short usInput = 65297;		/**< 0xFF11 */
	short sInput = -239;				/**< 0xFF11 */
	unsigned int uiInput = 4289335637;	/**< 0xFFAA1155 */
	int iInput = -5631659;				/**< 0xFFAA1155 */
	float fInput = 3.141593f;			/**< 0x40490FDC */

	unsigned short usOutput = 0;
	short sOutput = 0;
	unsigned int uiOutput = 0;
	int iOutput = 0;
	float fOutput = 0.0f;

	unsigned char ucOutput16[2];
	unsigned char ucOutput32[4];
	memset(ucOutput16, 0, sizeof(ucOutput16));
	memset(ucOutput32, 0, sizeof(ucOutput32));

	U16toU8(usInput, ucOutput16, LITTLE_ENDIAN);
	printf("U16toU8，输入%hu(0xFF11)，小端输出{%02X %02X}\n", usInput, ucOutput16[0], ucOutput16[1]);
	usOutput = U8toU16(ucOutput16, LITTLE_ENDIAN);
	printf("U8toU16，输入%hu，小端输出%hu\n\n", usInput, usOutput);

	I16toU8(sInput, ucOutput16, LITTLE_ENDIAN);
	printf("I16toU8，输入%hd(0xFF11)，小端输出{%02X %02X}\n", sInput, ucOutput16[0], ucOutput16[1]);
	sOutput = U8toI16(ucOutput16, LITTLE_ENDIAN);
	printf("U8toI16，输入%hd，小端输出%hd\n\n", sInput, sOutput);

	U32toU8(uiInput, ucOutput32, LITTLE_ENDIAN);
	printf("U32toU8，输入%u(0xFFAA1155)，小端输出{%02X %02X %02X %02X}\n", uiInput, ucOutput32[0], ucOutput32[1], ucOutput32[2], ucOutput32[3]);
	uiOutput = U8toU32(ucOutput32, LITTLE_ENDIAN);
	printf("U8toU32，输入%u，小端输出%u\n\n", uiInput, uiOutput);

	I32toU8(iInput, ucOutput32, LITTLE_ENDIAN);
	printf("I32toU8，输入%d(0xFFAA1155)，小端输出{%02X %02X %02X %02X}\n", iInput, ucOutput32[0], ucOutput32[1], ucOutput32[2], ucOutput32[3]);
	iOutput = U8toI32(ucOutput32, LITTLE_ENDIAN);
	printf("U8toI32，输入%d，小端输出%d\n\n", iInput, iOutput);

	FLTtoU8(fInput, ucOutput32, LITTLE_ENDIAN);
	printf("FLTtoU8，输入%.6f(0x40490FDC)，小端输出{%02X %02X %02X %02X}\n", fInput, ucOutput32[0], ucOutput32[1], ucOutput32[2], ucOutput32[3]);
	fOutput = U8toFLT(ucOutput32, LITTLE_ENDIAN);
	printf("U8toFLT，输入%.6f，小端输出%.6f\n", fInput, fOutput);
}


unsigned short U8toU16(unsigned char *pucU8, unsigned char littleEndian)
{
	unsigned short usU16 = 0;
	if (littleEndian)
	{
		usU16 = (pucU8[0] & 0x000000FF)
			+ ((pucU8[1] << 8) & 0x0000FF00);
	}
	else
	{
		usU16 = (pucU8[1] & 0x000000FF)
			+ ((pucU8[0] << 8) & 0x0000FF00);
	}
	return usU16;
}


short U8toI16(unsigned char *pucU8, unsigned char littleEndian)
{
	short sI16 = 0;
	if (littleEndian)
	{
		sI16 = (pucU8[0] & 0x000000FF)
			+ ((pucU8[1] << 8) & 0x0000FF00);
	}
	else
	{
		sI16 = (pucU8[1] & 0x000000FF)
			+ ((pucU8[0] << 8) & 0x0000FF00);
	}
	return sI16;
}


unsigned int U8toU32(unsigned char *pucU8, unsigned char littleEndian)
{
	unsigned int uiU32 = 0;
	if (littleEndian)
	{
		uiU32 = (pucU8[0] & 0x000000FF)
			+ ((pucU8[1] << 8) & 0x0000FF00)
			+ ((pucU8[2] << 16) & 0x00FF0000)
			+ ((pucU8[3] << 24) & 0xFF000000);
	}
	else
	{
		uiU32 = (pucU8[3] & 0x000000FF)
			+ ((pucU8[2] << 8) & 0x0000FF00)
			+ ((pucU8[1] << 16) & 0x00FF0000)
			+ ((pucU8[0] << 24) & 0xFF000000);
	}
	return uiU32;
}


int U8toI32(unsigned char *pucU8, unsigned char littleEndian)
{
	int iI32 = 0;
	if (littleEndian)
	{
		iI32 = (pucU8[0] & 0x000000FF)
			+ ((pucU8[1] << 8) & 0x0000FF00)
			+ ((pucU8[2] << 16) & 0x00FF0000)
			+ ((pucU8[3] << 24) & 0xFF000000);
	}
	else
	{
		iI32 = (pucU8[3] & 0x000000FF)
			+ ((pucU8[2] << 8) & 0x0000FF00)
			+ ((pucU8[1] << 16) & 0x00FF0000)
			+ ((pucU8[0] << 24) & 0xFF000000);
	}
	return iI32;
}


void U16toU8(unsigned short usU16, unsigned char *pucU8, unsigned char littleEndian)
{
	if (littleEndian)
	{
		pucU8[0] = usU16 & 0xFF;
		pucU8[1] = (usU16 >> 8) & 0xFF;
	}
	else
	{
		pucU8[1] = usU16 & 0xFF;
		pucU8[0] = (usU16 >> 8) & 0xFF;
	}
}


void I16toU8(short sI16, unsigned char *pucU8, unsigned char littleEndian)
{
	if (littleEndian)
	{
		pucU8[0] = sI16 & 0xFF;
		pucU8[1] = (sI16 >> 8) & 0xFF;
	}
	else
	{
		pucU8[1] = sI16 & 0xFF;
		pucU8[0] = (sI16 >> 8) & 0xFF;
	}
}


void U32toU8(unsigned int uiU32, unsigned char *pucU8, unsigned char littleEndian)
{
	if (littleEndian)
	{
		pucU8[0] = uiU32 & 0xFF;
		pucU8[1] = (uiU32 >> 8) & 0xFF;
		pucU8[2] = (uiU32 >> 16) & 0xFF;
		pucU8[3] = (uiU32 >> 24) & 0xFF;
	}
	else
	{
		pucU8[3] = uiU32 & 0xFF;
		pucU8[2] = (uiU32 >> 8) & 0xFF;
		pucU8[1] = (uiU32 >> 16) & 0xFF;
		pucU8[0] = (uiU32 >> 24) & 0xFF;
	}
}


void I32toU8(int iI32, unsigned char *pucU8, unsigned char littleEndian)
{
	if (littleEndian)
	{
		pucU8[0] = iI32 & 0xFF;
		pucU8[1] = (iI32 >> 8) & 0xFF;
		pucU8[2] = (iI32 >> 16) & 0xFF;
		pucU8[3] = (iI32 >> 24) & 0xFF;
	}
	else
	{
		pucU8[3] = iI32 & 0xFF;
		pucU8[2] = (iI32 >> 8) & 0xFF;
		pucU8[1] = (iI32 >> 16) & 0xFF;
		pucU8[0] = (iI32 >> 24) & 0xFF;
	}
}


float U8toFLT(unsigned char *pucU8, unsigned char littleEndian)
{
	float f32 = 0;

	union un_flt_uchar unData;
	memset((void*)&unData, 0, sizeof(unData));

	if (littleEndian)
	{
		memcpy((void*)unData.buf, pucU8, 4 * sizeof(unsigned char));
	}
	else
	{
		unData.buf[0] = *(pucU8 + 3);
		unData.buf[1] = *(pucU8 + 2);
		unData.buf[2] = *(pucU8 + 1);
		unData.buf[3] = *(pucU8 + 0);
	}

	f32 = unData.f32;

	return f32;
}


void FLTtoU8(float f32, unsigned char *pucU8, unsigned char littleEndian)
{
	union un_flt_uchar unData;
	unData.f32 = f32;

	if (littleEndian)
	{
		memcpy((void*)pucU8, unData.buf, 4 * sizeof(unsigned char));
	}
	else
	{
		*(pucU8 + 0) = unData.buf[3];
		*(pucU8 + 1) = unData.buf[2];
		*(pucU8 + 2) = unData.buf[1];
		*(pucU8 + 3) = unData.buf[0];
	}
}

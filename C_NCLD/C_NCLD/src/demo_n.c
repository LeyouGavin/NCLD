/**
*	@file		demo_n.c
*	@brief		创建新的C语言测试示例
*	@author		嵌入式男单第九名
**************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "demo_n.h"

int GetDemoList(const char* pcDemoNameFile);
int GetNewDemoIndex(const char* pcDemoNameFile);
unsigned char CreakNewDemo(unsigned int uiDemoSeq, int iGroupCnt);

/**
*	@brief		创建新的C语言测试示例
*	@details	在工程src文件下创建新的测试示例，
				根据实际情况修改iGroupCnt变量值
**************************************************/
void demo_n(void)
{
	char *pcDemoNameFile = "src/a.log";
	int iNewDemoIndex = 0;
	const int iGroupCnt = 1;

	printf(DEMO_N);

	GetDemoList(pcDemoNameFile);

	iNewDemoIndex = GetNewDemoIndex(pcDemoNameFile);

	remove(pcDemoNameFile);

	CreakNewDemo(iNewDemoIndex, iGroupCnt);
}

/**
*	@brief		获取现有测试文件列表
*	@details	创建包含现有测试文件列表的临时文件
*	@param[in]	pcDemoNameFile	生成临时文件的路径
*	@return		程序执行成功与否
*		@retval	0	成功
*		@retval 1	失败（保留）
**************************************************/
int GetDemoList(const char* pcDemoNameFile)
{
	char *pcCmdHead = "dir src /b /on /s > ";
	char pcCmd[256] = { 0 };

	strcpy(pcCmd, pcCmdHead);

	system(strcat(pcCmd, pcDemoNameFile));

	return 0;
}

/**
*	@brief		获取下一文件索引序号
*	@details	打开包含已有测试用例列表的临时文件，
				根据测试用例文件命名规则查询当前最新的测试用例文件序号，
				计算并返回下一文件索引序号
*	@param[in]	pcDemoNameFile	包含已有测试用例列表的临时文件
*	@return		程序执行结果
*		@retval	下一文件索引序号
**************************************************/
int GetNewDemoIndex(const char* pcDemoNameFile)
{
	FILE* pFileList = NULL;
	char pcDemoName[256];
	char* pcSubName = NULL;
	int index = 0;
	int iNewDemoIndex = 0;

	pFileList = fopen(pcDemoNameFile, "rb");

	fseek(pFileList, 0L, SEEK_SET);

	while (fscanf(pFileList, "%s", pcDemoName) > 0)
	{
		if ((pcSubName = strstr(pcDemoName, "\\demo_")) > 0)
		{
			index = strlen("\\demo_");
			while (('.' != *(pcSubName + index)) &&
				('_' != *(pcSubName + index)))
			{
				index++;
			}
			*(pcSubName + index) = '\0';

			index = strlen("\\demo_");
			if (iNewDemoIndex < atoi(pcSubName + index))
			{
				iNewDemoIndex = atoi(pcSubName + index);
			}
		}
	}

	fclose(pFileList);

	return iNewDemoIndex + 1;
}

/**
*	@brief		创建新的测试用例
*	@details	根据测试用例序号及本组文件个数创建新的测试用例
*	@param[in]	uiDemoSeq	测试用例序号
*	@param[in]	iGroupCnt	本组测试用例包含文件个数
*	@return		程序执行成功与否
*		@retval	0	成功
*		@retval 1	失败(保留)
**************************************************/
unsigned char CreakNewDemo(unsigned int uiDemoSeq, int iGroupCnt)
{
	FILE* pFileSrc = NULL;
	int index = 1;
	char pcNewDemoPath[256] = { 0 };
	char pcDemoSeqStr[8] = { 0 };

	if (iGroupCnt > 1)
	{
		do {
			//获取源文件路径名称
			strcpy(pcNewDemoPath, "src/demo_");
			strcat(pcNewDemoPath, _itoa(uiDemoSeq, pcDemoSeqStr, 10));
			strcat(pcNewDemoPath, "_");
			strcat(pcNewDemoPath, _itoa(index, pcDemoSeqStr, 10));
			strcat(pcNewDemoPath, ".c");
			//创建源文件
			pFileSrc = fopen(pcNewDemoPath, "wb");
			fputs("/**\n", pFileSrc);
			fprintf(pFileSrc, "%s%d%s%d%s", "*	@file		demo_", uiDemoSeq, "_", index, ".c\n");
			fputs("*	@brief		预留\n", pFileSrc);
			fputs("*	@author		嵌入式男单第九名\n", pFileSrc);
			fputs("**************************************************/\n", pFileSrc);
			fputs("\n", pFileSrc);
			fputs("#include <stdio.h>\n", pFileSrc);
			fprintf(pFileSrc, "%s%d%s%d%s", "#include \"demo_", uiDemoSeq, "_", index, " .h\"\n");
			fputs("\n", pFileSrc);
			fputs("/**\n", pFileSrc);
			fputs("*	@brief		测试用例入口函数\n", pFileSrc);
			fputs("*	@details	示例函数说明\n", pFileSrc);
			fputs("**************************************************/\n", pFileSrc);
			fprintf(pFileSrc, "%s%d%s%d%s", "void demo_", uiDemoSeq, "_", index, "(void)\n");
			fputs("{\n", pFileSrc);
			fprintf(pFileSrc, "%s%d%s%d%s", "\tprintf(DEMO_", uiDemoSeq, "_", index, ");\n");
			fputs("}\n", pFileSrc);
			fclose(pFileSrc);

			//获取头文件路径名称
			strcpy(pcNewDemoPath, "include/demo_");
			strcat(pcNewDemoPath, _itoa(uiDemoSeq, pcDemoSeqStr, 10));
			strcat(pcNewDemoPath, "_");
			strcat(pcNewDemoPath, _itoa(index, pcDemoSeqStr, 10));
			strcat(pcNewDemoPath, ".h");
			//创建头文件
			pFileSrc = fopen(pcNewDemoPath, "wb");
			fputs("/**\n", pFileSrc);
			fprintf(pFileSrc, "%s%d%s%d%s", "*	@file		demo_", uiDemoSeq, "_", index, ".h\n");
			fputs("*	@author		嵌入式男单第九名\n", pFileSrc);
			fputs("*	@details	示例内容\n", pFileSrc);
			fputs("*	-# 预留\n", pFileSrc);
			fputs("**************************************************/\n", pFileSrc);
			fputs("\n", pFileSrc);
			fputs("#pragma once\n", pFileSrc);
			fputs("\n", pFileSrc);
			fprintf(pFileSrc, "%s%d%s%d%s", "#define DEMO_", uiDemoSeq, "_", index, " \"\\n待测函数说明（预留）\\n\\n\"\n");
			fputs("\n", pFileSrc);
			fprintf(pFileSrc, "%s%d%s%d%s", "void demo_", uiDemoSeq, "_", index, "(void);\n");
			fclose(pFileSrc);
		} while (index++ < iGroupCnt);
	}
	else
	{
		//获取源文件路径名称
		strcat(pcNewDemoPath, "src/demo_");
		strcat(pcNewDemoPath, _itoa(uiDemoSeq, pcDemoSeqStr, 10));
		strcat(pcNewDemoPath, ".c");
		//创建源文件
		pFileSrc = fopen(pcNewDemoPath, "wb");
		fputs("/**\n", pFileSrc);
		fprintf(pFileSrc, "%s%d%s", "*	@file		demo_", uiDemoSeq, ".c\n");
		fputs("*	@brief		预留\n", pFileSrc);
		fputs("*	@author		嵌入式男单第九名\n", pFileSrc);
		fputs("**************************************************/\n", pFileSrc);
		fputs("\n", pFileSrc);
		fputs("#include <stdio.h>\n", pFileSrc);
		fprintf(pFileSrc, "%s%d%s", "#include \"demo_", uiDemoSeq, ".h\"\n");
		fputs("\n", pFileSrc);
		fputs("/**\n", pFileSrc);
		fputs("*	@brief		测试用例入口函数\n", pFileSrc);
		fputs("*	@details	示例函数说明\n", pFileSrc);
		fputs("**************************************************/\n", pFileSrc);
		fprintf(pFileSrc, "%s%d%s", "void demo_", uiDemoSeq, "(void)\n");
		fputs("{\n", pFileSrc);
		fprintf(pFileSrc, "%s%d%s", "\tprintf(DEMO_", uiDemoSeq, ");\n");
		fputs("}\n", pFileSrc);
		fclose(pFileSrc);

		//获取头文件路径名称
		strcpy(pcNewDemoPath, "include/demo_");
		strcat(pcNewDemoPath, _itoa(uiDemoSeq, pcDemoSeqStr, 10));
		strcat(pcNewDemoPath, ".h");
		//创建头文件
		pFileSrc = fopen(pcNewDemoPath, "wb");
		fputs("/**\n", pFileSrc);
		fprintf(pFileSrc, "%s%d%s", "*	@file		demo_", uiDemoSeq, ".h\n");
		fputs("*	@author		嵌入式男单第九名\n", pFileSrc);
		fputs("*	@details	示例内容\n", pFileSrc);
		fputs("*	-# 预留\n", pFileSrc);
		fputs("**************************************************/\n", pFileSrc);
		fputs("\n", pFileSrc);
		fputs("#pragma once\n", pFileSrc);
		fputs("\n", pFileSrc);
		fprintf(pFileSrc, "%s%d%s", "#define DEMO_", uiDemoSeq, " \"\\n待测函数说明（预留）\\n\\n\"\n");
		fputs("\n", pFileSrc);
		fprintf(pFileSrc, "%s%d%s", "void demo_", uiDemoSeq, "(void);\n");
		fclose(pFileSrc);
	}

	return 0;
}

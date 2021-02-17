/**
*	@file		demo_15.c
*	@brief		按键延时程序
*	@author		嵌入式男单第九名
**************************************************/

#include <stdio.h>
#include "demo_15.h"

extern int bKey1Push = 0;
extern int bKey2Push = 0;

extern int bKeyAPush = 0;
extern int bKeyBPush = 0;
extern int bKeyCPush = 0;

#define TIME_DELAY_TICK 5

void ISR_TIMER(void);
void ResponeKeyKeep(int key);
void ResponeKeyNoraml(void);

unsigned int uiCurrentTick = 0;
unsigned int uiKey1TimeoutTick = 0;
unsigned int uiKey2TimeoutTick = 0;

enum E_KEY_STATUS
{
	KEY_STATUS_RESET = 0,
	KEY_STATUS_PUSH1,
	KEY_STATUS_PUSH2,
	KEY_STATUS_ERROR
}eStatus = KEY_STATUS_RESET;


/**
*	@brief		按键检测程序
*	@details	处理常规、保持两种按键状态：
				1、按下保持键后，常规键做特殊功能处理
				2、释放保持按键，保持状态持续一段时间
				3、保持状态持续时，若有其它保持按键按
				下，则切换最新保持状态、重置状态延时
**************************************************/
void demo_15(void)
{
	printf(DEMO_15);

	if (bKey1Push | bKey2Push)
	{
		if (bKey1Push)
		{
			eStatus = KEY_STATUS_PUSH1;
			uiKey1TimeoutTick = uiCurrentTick + TIME_DELAY_TICK;
			uiKey2TimeoutTick = 0;
		}
		else
		{
			eStatus = KEY_STATUS_PUSH2;
			uiKey1TimeoutTick = 0;
			uiKey2TimeoutTick = uiCurrentTick + TIME_DELAY_TICK;
		}
	}
	else if ((uiCurrentTick > uiKey1TimeoutTick) && (uiCurrentTick > uiKey2TimeoutTick))
	{
		eStatus = KEY_STATUS_RESET;
		uiKey1TimeoutTick = uiKey2TimeoutTick = 0;
	}
	else
	{
		//Continue
	}

	switch (eStatus)
	{
		case KEY_STATUS_RESET:
			ResponeKeyNoraml();
			break;
		case KEY_STATUS_PUSH1:
			ResponeKeyKeep(1);
			break;
		case KEY_STATUS_PUSH2:
			ResponeKeyKeep(2);
			break;
		default:
			break;
	}
}

/**
*	@brief		常规按键处理
*	@details	处理常规键
**************************************************/
void ResponeKeyNoraml(void)
{
	if (bKeyAPush)
		;	/**< Do something */
	if (bKeyBPush)
		;	/**< Do something */
	if (bKeyCPush)
		;	/**< Do something */
}

/**
*	@brief		保持按键处理
*	@details	处理保持键
*	@param 
		key		已按下的保持键
**************************************************/
void ResponeKeyKeep(int key)
{
	if (bKeyAPush)
		;	/**< Do something */
	if (bKeyBPush)
		;	/**< Do something */
	if (bKeyCPush)
		;	/**< Do something */
}

/**
*	@brief		定时器中断
*	@details	全局定时器计数值加1
**************************************************/
void ISR_TIMER(void)
{
	++uiCurrentTick;
}

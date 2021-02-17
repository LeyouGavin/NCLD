/**
*	@file		demo_15.c
*	@brief		������ʱ����
*	@author		Ƕ��ʽ�е��ھ���
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
*	@brief		����������
*	@details	�����桢�������ְ���״̬��
				1�����±��ּ��󣬳���������⹦�ܴ���
				2���ͷű��ְ���������״̬����һ��ʱ��
				3������״̬����ʱ�������������ְ�����
				�£����л����±���״̬������״̬��ʱ
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
*	@brief		���水������
*	@details	�������
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
*	@brief		���ְ�������
*	@details	�����ּ�
*	@param 
		key		�Ѱ��µı��ּ�
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
*	@brief		��ʱ���ж�
*	@details	ȫ�ֶ�ʱ������ֵ��1
**************************************************/
void ISR_TIMER(void)
{
	++uiCurrentTick;
}

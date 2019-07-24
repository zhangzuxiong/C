#pragma once


#include "Double_Linked_List.h"

typedef struct Stack
{
	//˫����
	DL_List list;

	//ջ���������
	int max;

	//ջ����ЧԪ�ظ���
	int count;

} Stack;


// 1.��ʼ��
void initStack(Stack* p);


// 2.�п� ���Ϊ�գ���Ϊ�棻����Ϊ��
int isEmpty(const Stack stack);


// 3.���� ���Ϊ������Ϊ�棻����Ϊ��
int isFull(const Stack stack);


// 4.ѹ��,p ��ʾ��Ҫ������ջ��˭�� num ��ʾ��Ҫѹ��ջ����ֵ�Ƕ���
void pushStack(Stack* p, const int num);


// 5.����
int popStack(Stack* p);


// 6.���
void clearStack(Stack* p);

// 7.��ӡ
void printStack(const Stack stack);

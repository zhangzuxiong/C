#pragma once


#include "Double_Linked_List.h"

typedef struct Stack
{
	//双链表
	DL_List list;

	//栈的最大容量
	int max;

	//栈的有效元素个数
	int count;

} Stack;


// 1.初始化
void initStack(Stack* p);


// 2.判空 如果为空，则为真；否则为假
int isEmpty(const Stack stack);


// 3.判满 如果为满，则为真；否则为假
int isFull(const Stack stack);


// 4.压入,p 表示需要操作的栈是谁， num 表示需要压入栈的数值是多少
void pushStack(Stack* p, const int num);


// 5.弹出
int popStack(Stack* p);


// 6.清空
void clearStack(Stack* p);

// 7.打印
void printStack(const Stack stack);

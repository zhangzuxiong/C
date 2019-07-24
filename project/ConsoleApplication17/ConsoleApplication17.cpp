// ConsoleApplication17.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//双向链表实现栈  头指针和尾指针

#include "Stack_By_Double_Linked_List.h"


int main()
{
	Stack stack = { 0 };
	initStack(&stack);

	int i = 0;

	for ( i = 0; i < 10; i++)
	{
		pushStack(&stack, (i + 1) * 10);
	}

	printf("出栈的值为:%d\n", popStack(&stack));

	printStack(stack);

	clearStack(&stack);

	printStack(stack);

    return 0;
}

// ConsoleApplication11.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//链表实现栈--头指针存放了一个数据

/*
	头结点和头指针的区别：
		头指针第一个需要初始化，存放数据？
		头结点第一个，不需要存放数据（只用来当做一个标记），不需要初始化？

	链表实现栈时，数据从头指针开始存放，
				或者从头结点的下一个节点开始存放

*/

#include "Stack.h"


int main()
{
	Stack stack = { 0 };
	init(&stack);
	push(&stack, 10);
	clear(&stack);
	display(stack);

	return 0;

	is_empoty(stack);
	push(&stack, 10);
	push(&stack, 12);
	push(&stack, 13);
	push(&stack, 14);
	display(stack);

	printf("%d\n", pop(&stack));
	printf("%d\n", pop(&stack));
	printf("%d\n", pop(&stack));
	printf("%d\n", pop(&stack));
	display(stack);

	return 0;
}

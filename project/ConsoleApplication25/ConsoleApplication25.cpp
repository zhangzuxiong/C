// ConsoleApplication25.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//数组实现栈

#include "Stack_By_Array.h"

void testArrayList() {
	ArrayList array = { 0 };

	initArrayList(&array);

	printArrayList(array);

	insertArrayList(&array, 1, 1);


	insertArrayList(&array, 1, 2);


	insertArrayList(&array, 1, 3);

	insertArrayList(&array, 1, 4);


	insertArrayList(&array, 1, 5);

	printArrayList(array);

	printf("\n%d\n", getArrayList(&array, 0));
	printArrayList(array);

	clearArrayList(&array);


	printArrayList(array);
}

void testStackByArrayList() {
	Stack stack = { 0 };
	initStack(&stack);
	printStack(stack);
	for (size_t i = 0; i < 10; i++)
	{
		pushStack(&stack, (i + 1) * 10);
	}

	printStack(stack);

	printf("\n出栈元素为:%d\n", popStack(&stack));
	printf("\n出栈元素为:%d\n", popStack(&stack));

	printStack(stack);

	clearStack(&stack);
	printStack(stack);

}

int main()
{
	testStackByArrayList();

    return 0;
}

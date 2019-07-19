// ConsoleApplication8.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//--栈
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{

	//使用动态内存申请
	int* data;

	//最大容量
	int max;


	//有效元素的个数
	int count;

} Stack;


//初始化
int init(Stack* stack) {
	if (stack == NULL)
	{
		printf("初始化的参数为空\n");
		return -1;
	}

	//申请新的内存空间之前要将旧的空间释放
	if (stack->data != NULL)
	{
		free(stack->data);
	}
	printf("请输入最大容量:");
	scanf_s(" %d", &(stack->max));

	//判断输入
	if (stack->max < 0)
	{
		printf("输入的容量有误\n");
		return -2;
	}

	stack->data = (int*)malloc(sizeof(int) * stack->max);
	int i = 0;
	for (i = 0; i < stack->max; i++)
	{
		stack->data[i] = 0;
	}
	stack->count = 0;
	return 0;
}

//栈销毁
void destory(Stack* stack) {
	if (stack == NULL)
	{
		printf("栈销毁的参数为空\n");
		return;
	}
	stack->count = 0;
	free(stack->data);
}

//判空
int is_empoty(const Stack stack) {
	if (stack.count == 0)
	{
		printf("栈为空\n");
		return 1;
	}
	else
	{
		printf("栈不为空\n");
		return 0;
	}
}

//判满
int is_full(const Stack stack) {
	if (stack.count == stack.max)
	{
		printf("栈为满\n");
		return 1;
	}
	else
	{
		printf("栈不为满\n");
		return 0;
	}
}

//栈顶加入元素
void push(Stack* stack, int num) {
	if (stack == NULL)
	{
		printf("压入的参数为空\n");
		return;
	}
	if (is_full(*stack))
	{
		printf("栈已满，无法再增加\n");
		return;
	}
	stack->data[stack->count] = num;
	stack->count++;
}

//栈顶弹出元素
int pop(Stack* stack) {
	if (stack == NULL)
	{
		printf("弹出参数为空\n");
		return -1;
	}
	if (is_empoty(*stack))
	{
		printf("栈为空，无法弹出\n");
		return -2;
	}
	int n = stack->data[(stack->count) - 1];
	(stack->count)--;
	return n;
}

//清空
void empoty(Stack* stack) {
	if (stack == NULL)
	{
		printf("清空参数为空\n");
		return;
	}

	if (is_empoty(*stack))
	{
		printf("栈已经为空，不需要再清空\n");
		return;
	}
	stack->count = 0;
}

//打印
void display(const Stack stack) {
	if (is_empoty(stack))
	{
		printf("栈为空,不需打印\n");
		return;
	}
	int i = stack.count;
	for (i; i > 0; i--)
	{
		printf("%d ", stack.data[i - 1]);
	}
	printf("\n");
}

int main()
{
	Stack stack = { 0 };
	init(&stack);

	push(&stack, 10);
	push(&stack, 11);
	push(&stack, 12);
	push(&stack, 13);
	push(&stack, 14);
	display(stack);

	printf("%d\n", pop(&stack));
	printf("%d\n", pop(&stack));
	display(stack);

	empoty(&stack);
	display(stack);

	printf("\n");
	destory(&stack);
	push(&stack, 15);
	display(stack);

	return 0;
}

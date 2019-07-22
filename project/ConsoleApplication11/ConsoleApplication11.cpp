// ConsoleApplication11.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//链表实现栈--头指针存放了一个数据

/*
	头结点和头指针的区别：
		头指针第一个需要初始化，存放数据？
		头结点第一个，不需要存放数据（只用来当做一个标记），不需要初始化？

	链表实现栈时，数据从头指针开始存放，
				或者从头结点的下一个节点开始存放

	一定要最大容量？
	命名规则

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//定义节点
typedef struct Node
{
	int data;
	Node* next;
} Node;

typedef struct Stack
{
	//头节点指针
	Node* head;

	//最大容量
	//int max;

	//有效元素个数
	int count;

} Stack;



//初始化,释放所有节点的内存
void init(Stack* p) {
	if (p == NULL)
	{
		printf("初始化参数为空\n");
		return;
	}

	//临时指针变量，释放空间
	Node* temp = p->head;

	while (p->head != NULL)
	{
		//p->head = temp->next;
		p->head = p->head->next;
		free(temp);

		//将temp指向下一个释放的节点
		temp = p->head;
	}
	p->count = 0;

	//头结点指针置位NULL
	//前面的循环已经将head置为NULL
	//p->head->next = NULL;

	//头结点里面存放的数值置位0
	//p->head->data = 0;
}


//判空
int is_empoty(const Stack stack) {
	if (stack.count==0)
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


//入栈,将新创建的节点放到链表的第一个节点，
//这样在出栈的时候只需要拿出第一个节点即可
void push(Stack* p, const int num) {
	if (p==NULL)
	{
		printf("入栈传入的参数为空\n");
		return;
	}

	
	//临时变量保存链表的头
	Node* temp = p->head;

	//循环遍历找到最后一个节点
	/*while (temp!=NULL)
	{
		temp = temp->next;
	}*/

	//创建一个新节点
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = num;


	//将节点加入链表的首个元素
	node->next=temp;
	//最后将新加的节点设置为头
	p->head=node;

	//有效元素加1
	p->count++;
}



//出栈
int pop(Stack* p) {
	if (p==NULL)
	{
		printf("出栈传入的参数为空\n");
		return -1;
	}

	if (is_empoty(*p))
	{
		printf("栈为空，没有元素可以出栈\n");
		return -2;
	}

	//取出头结点，将头结点的下一个节点赋为新的头结点

	Node* temp = p->head;
	p->head = temp->next;

	int data = temp->data;
	free(temp);
	p->count--;
	//出栈
	return data;
}



//清空
void clear(Stack* p) {
	if (p == NULL)
	{
		printf("清空传入的参数为空\n");
		return ;
	}

	if (is_empoty(*p))
	{
		printf("栈为空，无需清空\n");
		return ;
	}

	//清空
	//头结点指向的下一个节点为空，则栈为空
	Node* temp = p->head;

	while (p->head!=NULL)
	{

		//向后移动一个
		p->head = temp->next;

		//释放空间
		free(temp);

		//指向下一个释放的节点
		temp = p->head;
	}
	p->count = 0;
}



//打印
void display(const Stack stack) {
	if (is_empoty(stack))
	{
		printf("栈为空，没有可以打印的元素\n");
		return;
	}

	Node* temp = stack.head;

	while (temp!=NULL)
	{
		printf(" %d ", temp->data);
		temp = temp->next;
	}
}


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

	printf("%d\n",pop(&stack));
	printf("%d\n",pop(&stack));
	printf("%d\n",pop(&stack));
	printf("%d\n",pop(&stack));
	display(stack);

    return 0;
}

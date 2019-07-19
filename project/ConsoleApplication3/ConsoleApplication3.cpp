// ConsoleApplication2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//链表

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int a;
	Node* next;

} Node;

Node* head = NULL;
int num = 0;

//初始化
void init() {
	head = NULL;
	num = 0;
}


//判空
int is_empoty() {
	if (head == NULL || num == 0)
	{
		printf("链表为空\n");
		return 1;
	}
	else
	{
		printf("链表不为空\n");
		return 0;
	}
}

//打印
void dispaly() {
	if (is_empoty())
	{
		printf("没有数据，不需打印\n");
		return;
	}

	Node* temp = head;

	while (temp != NULL)
	{
		printf("%d   ", temp->a);
		temp = temp->next;
	}

}


//放入
void insert_begin() {
	Node* temp = (Node*)malloc(sizeof(Node));
	printf("请输入数值:");
	scanf(" %d", &(temp->a));

	temp->next = head;


	head = temp;
	num++;
}

//取出
void get_begin() {
	if (is_empoty())
	{
		printf("数据为空，无法取出\n");
		return;
	}
	Node* temp = head;
	printf("取出的数据为a=%d\n", temp->a);
	head = head->next;
	free(temp);
	num--;
}


//清空
void empoty() {
	if (is_empoty())
	{
		printf("链表已经为空\n");
		return;
	}

	Node* temp = head;

	while (head != NULL)
	{
		head = head->next;
		free(temp);//释放节点之后再将head赋给temp
		temp = head;
	}
	num = 0;

}

//查找
void search() {
	if (is_empoty())
	{
		printf("链表为空，找不到数据\n");
		return;
	}
	int n = 0;
	printf("请输入查找的数据:");
	scanf(" %d", &n);

	Node* temp = head;

	while (temp != NULL)
	{
		if (temp->a == n)
		{
			printf("找到了数据，数据是a=%d\n", temp->a);
			return;
		}
		temp = temp->next;
	}

	printf("没有找到\n");
}


int main()
{

	init();

	insert_begin();
	insert_begin();
	insert_begin();
	dispaly();


	printf("\n-------------------------\n");
	get_begin();
	dispaly();


	printf("\n-------------------------\n");
	empoty();
	dispaly();


	printf("\n-------------------------\n");
	insert_begin();
	insert_begin();
	insert_begin();
	insert_begin();
	insert_begin();
	insert_begin();
	dispaly();
	search();


	printf("\n-------------------------\n");


	return 0;
}

// ConsoleApplication11.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//链表实现队列--头指针存放了一个数据


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//定义节点
typedef struct Node
{
	int data;
	Node* next;
} Node;

typedef struct Queue
{
	//头节点指针
	Node* head;

	//最大容量
	//int max;

	//有效元素个数
	int count;

} Queue;



//初始化,释放所有节点的内存
void init(Queue* p) {
	if (p == NULL)
	{
		printf("初始化参数为空\n");
		return;
	}

	while (p->head != NULL)
	{
		//临时指针变量，释放空间
		Node* temp = p->head->next;
		//p->head.next = p->head.next->next;
		p->head->next = temp->next;
		free(temp);

		//将temp指向下一个释放的节点
		temp = p->head->next;
	}
	p->count = 0;

	//头结点指针置位NULL
	//p->head->next = NULL;

	//头结点里面存放的数值置位0
	//p->head->data = 0;
}


//判空
int is_empoty(const Queue queue) {
	if (queue.count == 0)
	{
		printf("队列为空\n");
		return 1;
	}
	else
	{
		printf("队列不为空\n");
		return 0;
	}
}


//入队,将新创建的节点放到链表的最后一个节点，
//这样在出队的时候只需要拿出第一个节点即可
void put_Queue(Queue* p, const int num) {
	if (p == NULL)
	{
		printf("入栈传入的参数为空\n");
		return;
	}
	//临时变量保存链表的头
	Node* temp = p->head;

	//创建一个新节点
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = num;

	//队列为空,特殊处理，直接将新加的节点赋为链表的头指针
	if (temp==NULL)
	{
		p->head = node;
		p->count++;
		node->next = NULL;
		return;
	}

	//循环遍历找到最后一个节点
	while (temp->next != NULL)
	{
		temp = temp->next;
	}


	//将节点加入链表的末尾
	temp->next = node;
	//最后将新节点的next置位NULL
	node->next = NULL;

	//有效元素加1
	p->count++;
}



//出队
int get_Queue(Queue* p) {
	if (p == NULL)
	{
		printf("出队传入的参数为空\n");
		return -1;
	}

	if (is_empoty(*p))
	{
		printf("队列为空，没有元素可以出队\n");
		return -2;
	}

	//取出头结点，将头结点的下一个节点赋为新的头结点

	Node* temp = p->head;
	p->head = temp->next;

	int data = temp->data;
	free(temp);
	p->count--;
	//返回出队的值
	return data;
}



//清空
void clear(Queue* p) {
	if (p == NULL)
	{
		printf("清空传入的参数为空\n");
		return;
	}

	if (is_empoty(*p))
	{
		printf("队列为空，无需清空\n");
		return;
	}

	//清空
	//头结点指向的下一个节点为空，则栈为空
	Node* temp = p->head;

	while (p->head != NULL)
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
void display(const Queue queue) {
	if (is_empoty(queue))
	{
		printf("队列为空，没有可以打印的元素\n");
		return;
	}

	Node* temp = queue.head;

	while (temp != NULL)
	{
		printf(" %d ", temp->data);
		temp = temp->next;
	}
}


int main()
{
	Queue queue = { 0 };
	init(&queue);
	//display(queue);
	put_Queue(&queue, 10);
	printf("\n");
	clear(&queue);
	display(queue);
	return 0;

	is_empoty(queue);
	put_Queue(&queue, 10);
	put_Queue(&queue, 11);
	put_Queue(&queue, 12);
	put_Queue(&queue, 13);
	put_Queue(&queue, 14);
	display(queue);

	printf("%d\n", get_Queue(&queue));
	printf("%d\n", get_Queue(&queue));
	display(queue);

	return 0;
}

// ConsoleApplication19.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//双向链表实现队列  头尾指针

#include "Queue_By_Double_Linked_List.h"

int main()
{
	Queue queue = { 0 };
	initQueue(&queue);
	int i = 0;
	for ( i = 0; i < 10; i++)
	{
		putQueue(&queue, (i + 1) * 10);
	}

	printQueue(queue);

	printf("出队的值为:%d\n",getQueue(&queue));
	printf("出队的值为:%d\n",getQueue(&queue));

	clearQueue(&queue);

	printQueue(queue);

}



#include "Queue_By_Double_Linked_List.h"

// 1.初始化
void initQueue(Queue* p) {

	// 指针判空
	if (p == NULL)
	{
		printf("初始化函数形参为空\n");

		return;
	}

	// 手动输入队列空间需要的最大容量
	printf(" 请输入队列空间需要的最大容量（正整数）：");

	scanf(" %d", &(p->max));


	// 初始化队列的存储空间，就是初始化双链表
	initDoubleLinkedList(&(p->list));


	// 队列内有效元素的个数 置零
	p->count = 0;

	// 头放置到数组的第一个元素
	p->head = 0;

	// 尾放置到数组的第一个元素
	p->tail = 0;

}



// 2.判空 如果为空，则为真；否则为假
int isEmpty(const Queue queue) {

	if (queue.count == 0)
	{
		printf(" 队列 为空\n");

		return 1;
	}
	else
	{
		printf(" 队列 不为空\n");

		return 0;
	}
}



// 3.判满 如果为满，则为真；否则为假
int isFull(const Queue queue) {

	if (queue.tail == queue.max)
	{
		printf(" 队列 为满\n");

		return 1;
	}
	else
	{
		printf(" 队列 不为满\n");

		return 0;
	}
}



// 4.放入,p 表示需要操作的队列是谁， num 表示需要放入队尾的数值是多少
void putQueue(Queue* p, const int num) {

	// 指针判空
	if (p == NULL)
	{
		printf(" 放入函数形参为空\n");

		return;
	}

	// 判满
	if (isFull(*p))
	{
		printf(" 当前队列为满，无法放入新的元素\n");

		return;
	}

	// 找到队列的末尾，将 num 放入
	// 相当于在双链表的末尾插入一个新的结点
	insertPositionDoubleLinkedList(&(p->list), p->count + 1, num);

	// 队尾向后挪一格
	p->tail++;

	// 有效元素的个数
	p->count++;
}



// 5.取出
int getQueue(Queue* p) {

	// 指针判空
	if (p == NULL)
	{
		printf(" 取出函数形参为空\n");

		return -1;
	}

	// 判空
	if (isEmpty(*p))
	{
		printf(" 当前队列为空，没有可以取出的元素\n");

		return -2;
	}

	// 用一个临时变量保存需要返回的数值
	int temp = 0;

	//相当于从双链表的头 取出第一个结点的数值
	temp = p->list.head.next->data;

	// 删除双链表头的第一个结点
	deletePositionDoubleLinkedList(&(p->list), 1);

	// 下面一行代码可以取代上面三行代码
	//int temp = deletePositionDoubleLinkedList(&(p->list), 1);

	// 有效元素个数 -1
	p->count--;

	// head 先后挪一格
	p->head++;

	// 判断 head 是否 取空了队列，如果取空队列，head 和 tail 要返回数组第一个元素的位置
	if (p->head == p->tail)
	{
		p->head = 0;
		p->tail = 0;
	}

	return temp;
}



// 6.清空
void clearQueue(Queue* p) {

	// 指针判空
	if (p == NULL)
	{
		printf(" 清空函数形参为空\n");

		return;
	}

	// 判空
	if (isEmpty(*p))
	{
		printf(" 当前队列为空，没有清空的必要\n");

		return;
	}

	//清空一个队列，实质上就是清空双链表
	clearDoubleLinkedList(&(p->list));

	// 有效元素的个数 置零
	p->count = 0;

	// 头和尾回到数组的第一个元素上
	p->head = 0;

	p->tail = 0;
}



// 7.打印
void printQueue(const Queue queue) {

	// 判空
	if (isEmpty(queue))
	{
		printf(" 当前队列为空，没有可以打印的元素\n");

		return;
	}

	//打印的时候需要按照队列的图形打印，先打印队列的头，最后是尾
	printDoubleLinkedList(queue.list);
}



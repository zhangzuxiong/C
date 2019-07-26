
#include "CQueue_By_Array.h"


// 1.初始化
void initCQueue(CQueue* p) {

	// 指针判空
	if (p == NULL)
	{
		return;
	}

	// 手动输入循环队列需要的最大容量
	printf(" 请输入队列需要的最大容量（正整数）：");

	scanf(" %d", &(p->max));

	// 循环队列使用的是数组，所初始化循环队列，就是初始化其中属性 数组
	initArrayList(&(p->list));

	// 循环队列有效元素的个数 置零
	p->count = 0;

}



// 2.判空 如果为空，则为真；否则为假
int isEmpty(const CQueue queue) {

	if (queue.count == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}



// 3.判满 如果为满，则为真；否则为假
int isFull(const CQueue queue) {

	if (queue.max == queue.count)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}



// 4.插入,p 表示需要操作的循环队列是谁， num 表示需要插入循环队列的数值是多少
void putCQueue(CQueue* p, const Element num) {

	// 指针判空
	if (p == NULL)
	{
		return;
	}

	// 判满
	if (isFull(*p))
	{
		printf(" 循环队列已满，无法放入新的元素\n");
		return;
	}

	// 给队列放入一个值
	// 相当于在数组第一位增加一个元素
	insertArrayList(&(p->list), 1, num);

	// 有效元素的个数 +1
	p->count++;
}



// 5.取出
Element getCQueue(CQueue* p) {

	// 指针判空
	if (p == NULL)
	{

		return NULL;
	}

	// 判空
	if (isEmpty(*p))
	{
		printf(" 循环队列为空，没有可以出队的元素\n");

		return NULL;
	}

	// 将需要弹出的数值先保留下来
	int res = p->list.arr[0];


	// 相当于 删除 数组的第一个元素
	getArrayList(&(p->list), 1);

	// 下面一行代码等价于上面两行
	//int res = getArrayList(&(p->list), 1);

	// 循环队列的有效元素个数 -1
	p->count--;

	return res;
}



// 6.清空
void clearCQueue(CQueue* p) {

	// 指针判空
	if (p == NULL)
	{
		//printf(" 清空函数形参为空\n");

		return;
	}

	// 判空
	if (isEmpty(*p))
	{
		printf(" 当前队列为空，没有清空的必要\n");

		return;
	}

	//清空一个循环队列，实质上需要清空数组
	clearArrayList(&(p->list));

	// 循环队列的有效元素个数 置零
	p->count = 0;

}



// 7.打印
void printCQueue(const CQueue stack) {

	// 判空
	if (isEmpty(stack))
	{
		printf(" 循环队列为空，没有可以打印的元素\n");

		return;
	}


	printArrayList(stack.list);
}


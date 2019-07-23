// ConsoleApplication4.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <stdlib.h>

typedef int Element;


/*
	单链表的数据类型

	设计一个结构体，用结构体变量来实现一个队列

	以整数作为数据来举例

*/

// 设计结点的数据类型
typedef struct Node {

	Element data;

	Node* next_pointer;

} Node;

// 设计单链表的数据类型
typedef struct Single_Linked_List {

	// 方式2
	Node head;

	// 记录有效结点的个数
	int count;

} SL_List;



// 1.初始化
void  init_Single_Linked_List( SL_List* p ) {

	// 指针判空
	if ( p == NULL )
	{
		printf(" initt_Single_Linked_List 函数形参为空\n");

		return;
	}


	// 临时指针变量，用来释放结点空间
	Node* temp = p->head.next_pointer;

	// 循环遍历整个单链表，逐一释放每个结点
	while ( p->head.next_pointer != NULL )
	{
		// 将头结点的 next 指向第一个结点的下一个结点（第二个）
		//p->head.next_pointer = p->head.next_pointer->next_pointer;
		p->head.next_pointer = temp->next_pointer;

		// 释放 temp 所指向的结点，原单链表的第一个结点
		free(temp);

		// 将 temp 再次指向下一个需要释放的结点
		temp = p->head.next_pointer;
	}

	// 有效元素的个数 置零
	p->count = 0;

	// 头结点的 next 指针 置空
	p->head.next_pointer = NULL;

	// 头结点 里面  存放的垃圾值，需要处理一下（可选）
	//p->head.data = 0;
}



// 2.判空 如果为空，则为真；否则为假
int judge_empty_Single_Linked_List( const SL_List list ) {

	if ( list.count == 0 )
	{
		printf(" 单链表 为空\n");

		return 1;
	}
	else
	{
		printf(" 单链表 不为空\n");

		return 0;
	}
}



// 3.插入
// p 表示需要操作的单链表是谁， position 表示插入的位置， num 表示需要放入任意位置的数值是多少
void insert_position_Single_Linked_List( SL_List* p, const int position, const Element data ) {

	// 指针判空
	if ( p == NULL )
	{
		printf(" insert_position_Single_Linked_List 函数形参为空\n");

		return;
	}

	// 判断插入的位置是否在单链表的长度范围内
	//if ( position < p->count + 2 && position > 0 )
	if ( position > p->count + 1 || position < 1 )
	{
		printf(" 插入的位置，不在单链表的长度范围内\n");

		return;
	}

	// 用临时指针变量 index 去定位，定需要插入的位置的前一个结点的位置（地址）
	/*
		如果需要插入的结点是第一个结点，那么必须知道头结点的位置（地址）

		所以这个 index 开始的位置就是头结点的地址
	*/ 
	Node* index = &(p->head);

	int i = 0;

	while ( i < position-1 )
	{
		index = index->next_pointer;

		i++;
	}

	// 开始动态申请空间，创建新的结点
	Node* node = (Node*)malloc(sizeof(Node));

	// node 赋值
	node->data = data;

	node->next_pointer = index->next_pointer;

	// 将插入的位置的前一个结点 的 next 指针 指向 新的结点
	index->next_pointer = node;

	// 有效结点元素的个数 +1
	p->count++;
}


// 4.删除
Element delete_position_Single_Linked_List( SL_List* p, const int position ) {

	// 指针判空
	if ( p == NULL )
	{
		printf(" delete_position_Single_Linked_List 函数形参为空\n");

		return -1;
	}

	// 判空
	if ( judge_empty_Single_Linked_List(*p) )
	{
		printf(" 单链表为空，没有可以删除的结点元素\n");

		return -2;
	}

	// 判断删除的位置是否在单链表的长度范围内
	//if ( position < p->count + 1 && position > 0 )
	if ( position > p->count || position < 1 )
	{
		printf(" 删除的位置，不在单链表的长度范围内\n");

		return -3;
	}

	// 保存需要返回的值
	Element res = NULL;

	// 用临时指针变量 index 去定位，定需要删除的位置的前一个结点的位置（地址）
	Node* index = &(p->head);

	int i = 0;

	while (i < position - 1)
	{
		index = index->next_pointer;

		i++;
	}

	// 用临时指针变量 temp 保存需要释放的结点空间
	Node* temp = index->next_pointer;

	/*
		将需要删除的位置上的结点的前一个结点 的 next指针 
		指向
		需要删除的位置上的结点的后一个结点（地址）
	*/ 
	//index->next_pointer = index->next_pointer->next_pointer;
	index->next_pointer = temp->next_pointer;

	res = temp->data;

	// 释放 temp 指向的结点空间
	free(temp);

	temp = NULL;

	// 有效结点的个数 -1
	p->count--;

	return res;
}


// 5.查询
// 按位置查询里面保存的数值
Element lookup_position_Single_Linked_List( const SL_List list, const int position ) {

	// 判空
	if ( judge_empty_Single_Linked_List(list) )
	{
		printf(" 单链表为空，没有查询的必要\n");

		return -1;
	}

	// 判断查询的位置是否在单链表的长度范围内
	//if ( position < list.count + 1 && position > 0 )
	if ( position > list.count || position < 1)
	{
		printf(" 查询的位置，不在单链表的长度范围内\n");

		return -2;
	}

	// 用临时指针变量 index 遍历单链表进行定位
	// index 先定位在头结点的地址上
	Node* index = (Node*)&(list.head);

	int i = 0;

	while ( i < position )
	{
		index = index->next_pointer;

		i++;
	}

	return index->data;
}


// 按数值查询结点为位置
int lookup_value_Single_Linked_List( const SL_List list, const int value ) {

	// 判空
	if ( judge_empty_Single_Linked_List(list) )
	{
		printf(" 单链表为空，没有查询的必要\n");

		return -1;
	}

	// 用临时指针变量 index 遍历单链表进行定位
	// index 先定位在头结点的地址上
	Node* index = (Node*) & (list.head.next_pointer);

	// 用来计数
	int i = 1;

	while ( index != NULL )
	{
		if ( index->data == value )
		{
			return i;
		}
		
		index = index->next_pointer;

		i++;
	}

	printf(" 查询的数值，不在单链表的长度范围内\n");

	return -2;
}


// 按位置查询结点的地址
// 按数值查询结点的地址



// 6.清空
void clear_Single_Linked_List( SL_List* p ) {

	// 指针判空
	if ( p == NULL )
	{
		printf(" clear_Single_Linked_List 函数形参为空\n");

		return;
	}

	// 判空
	if ( judge_empty_Single_Linked_List(*p) )
	{
		printf(" 单链表为空，没有清空的必要\n");

		return;
	}

	// 临时指针变量，用来释放结点空间
	Node* temp = p->head.next_pointer;

	// 循环遍历整个单链表，逐一释放每个结点
	while ( p->head.next_pointer != NULL )
	{
		//p->head.next_pointer = p->head.next_pointer->next_pointer;
		p->head.next_pointer = temp->next_pointer;

		// 释放 temp 所指向的结点，原单链表的第一个结点
		free(temp);

		// 将 temp 再次指向下一个需要释放的结点
		temp = p->head.next_pointer;
	}

	// 有效元素的个数 置零
	p->count = 0;
}



// 7.打印
void print_Single_Linked_List( const SL_List list ) {

	// 判空
	if ( judge_empty_Single_Linked_List(list) )
	{
		printf(" 单链表为空，没有可以打印的结点元素\n");

		return;
	}

	// 用临时变量来遍历整个单链表
	Node* temp = list.head.next_pointer;

	printf(" 从单链表头开始：\n");

	while ( temp != NULL )
	{
		printf(" %d\n", temp->data);

		temp = temp->next_pointer;
	}

	printf(" 到单链表尾结束：\n");
}



int main()
{
	SL_List list = { 0 };

	init_Single_Linked_List(&list);

	print_Single_Linked_List(list);

	printf("\n-------------------------------\n\n");

	//insert_position_Single_Linked_List(&list, 2, 100);

	Element i = 0;

	for ( i = 0; i < 10; i++ )
	{
		insert_position_Single_Linked_List(&list, i + 1, (i + 1) * 100);
	}

	print_Single_Linked_List(list);

	printf("\n-------------------------------\n\n");

	insert_position_Single_Linked_List(&list, 1, 10000);

	print_Single_Linked_List(list);

	insert_position_Single_Linked_List(&list, 7, 77777);

	print_Single_Linked_List(list);

	//insert_position_Single_Linked_List(&list, -1, 77777);

	//insert_position_Single_Linked_List(&list, 20, 77777);

	printf("\n-------------------------------\n\n");

	printf(" 删除的结点的元素值是： %d\n", delete_position_Single_Linked_List(&list, 1));

	print_Single_Linked_List(list);

	printf(" 删除的结点的元素值是： %d\n", delete_position_Single_Linked_List(&list, 6));

	print_Single_Linked_List(list);

	for ( i = 0; i < 10; i++ )
	{
		printf(" 删除的结点的元素值是： %d\n", delete_position_Single_Linked_List(&list, 1));
	}

	print_Single_Linked_List(list);

	clear_Single_Linked_List(&list);

	printf("\n-------------------------------\n\n");

	for ( i = 0; i < 10; i++ )
	{
		insert_position_Single_Linked_List(&list, i + 1, (i + 1) * 100);
	}

	print_Single_Linked_List(list);

	clear_Single_Linked_List(&list);

	print_Single_Linked_List(list);


	return 0;
}



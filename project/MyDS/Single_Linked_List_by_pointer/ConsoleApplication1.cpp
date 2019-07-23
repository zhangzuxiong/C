// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <stdlib.h>

/*
	单链表的数据类型

	设计一个结构体，用结构体变量来实现一个队列

	以整数作为数据来举例

*/

// 设计结点的数据类型
typedef struct Node {

	int data;

	Node* next_pointer;

} Node;

// 设计单链表的数据类型
typedef struct Single_Linked_List {

	// 方式1
	Node* head;

	// 方式2
	//Node head;

	// 下面的内容无论方式1还是2都需要用
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

	// 在申请新的内存空间给 data_pointer 之前，需要先将它指向的旧空间释放掉
	/*
		注意：

			1.不能释放同一个空间两次
			2.不能释放 NULL
	*/
	// 临时指针变量，用来释放结点空间
	Node* temp = p->head;

	// 循环遍历整个单链表，逐一释放每个结点
	while ( p->head != NULL )
	{
		// 将 头指针 指向第一个结点的下一个结点（第二个）
		p->head = p->head->next_pointer;
		//p->head = temp->next_pointer;

		// 释放 temp 所指向的结点，原单链表的第一个结点
		free( temp );

		// 将 temp 再次指向下一个需要释放的结点
		// 现单链表第一个结点，原单链表第二个结点
		temp = p->head;
	}

	// 有效元素的个数 置零
	p->count = 0;

	// 头指针 置空 （可选，因为前面的while循环已经将 head 置空）
	//p->head = NULL;

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
void insert_position_Single_Linked_List( SL_List* p, const int position, const int num ) {

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

	/*
		相较于之前用头结点的方式来表示链表

		头指针在插入第一个结点的时候，与之后其他位置插入结点的操作有些不同

		需要特殊处理

		不论链表是否为空，只要插入的位置 是 第一个位置，都需要单独处理

		如果插入的位置不是第一个结点，则需要先定位

		index 定位到插入位置的前一个结点上
	*/
	if ( position == 1 )
	{
		// 创建新结点
		Node* node = (Node*)malloc(sizeof(Node));

		// head 指向哪个地方， node->next 就指向哪
		node->next_pointer = p->head;

		// 赋值
		node->data = num;

		// 将头指针 指向 新结点，这是单链表的 新的 第一个有效结点
		p->head = node;
	}
	else
	{
		// 需要一个临时指针变量来定位
		Node* index = p->head;

		int i = 0;

		/*
			index 先停留在 第一个有效结点上，如果需要插入到第三个位置上

			index 需要定位到第二个结点所在的位置上

			那么 index 从第一个有效结点坐在的位置上移动一次

			position = 3 -------- index 挪动 1次
		*/ 
		while ( i < position-2 )
		{
			// 定位 的指针变量，向后挪用一个结点
			index = index->next_pointer;

			// 挪动次数的控制
			i++;
		}

		// 定位之后，创建新的结点
		Node* node = (Node*)malloc(sizeof(Node));

		// 将插入位置的结点的地址，赋值给新结点的 next 指针
		node->next_pointer = index->next_pointer;

		// 赋值
		node->data = num;

		// 将插入位置之前的结点的 next 指针指向 新结点
		index->next_pointer = node;
	}

	// 有效结点元素的个数 +1
	p->count++;
}



// 4.删除
int delete_position_Single_Linked_List( SL_List* p, const int position ) {

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

	// 用临时变量保存需要返回的数值
	int res = 0;

	/*
		相比于之前使用头结点

		使用头指针在删除任意位置时，会有细节上的差异

		主要体现在删除第一个结点的操作上
	*/
	// 判断删除的结点是不是第一个，如果是操作需要单独处理
	if ( position == 1 )
	{
		// 用临时指针变量记录需要释放的结点的空间地址
		Node* temp = p->head;

		// 将头指针 挪到原单链表的第二个结点上，也就向后挪到下一个结点上
		p->head = p->head->next_pointer;
		//p->head = temp->next_pointer;

		res = temp->data;

		// 释放原单链表第一个结点的空间
		free(temp);

		temp = NULL;
	}
	else
	{
		// 先定位到需要删除的位置的前一个结点上
		Node* index = p->head;

		int i = 0;

		// 循环向后遍历
		while ( i < position-2 )
		{
			// 定位的指针变量向下一个结点挪动
			index = index->next_pointer;

			// 挪动次数的控制
			i++;
		}

		// 先用临时指针变量记录需要删除的结点的空间的地址
		Node* temp = index->next_pointer;

		/*
			定位的结点（需要删除的结点的前一个结点） 的 next
			指向
			需要删除的结点的后一个结点的空间的地址
		*/ 
		index->next_pointer = index->next_pointer->next_pointer;
		//index->next_pointer = temp->next_pointer;

		res = temp->data;

		// 释放需要删除的结点的空间
		free(temp);

		temp = NULL;
	}

	// 有效结点的个数 -1
	p->count--;

	return res;
}



// 5.查询
// 按位置查询里面保存的数值
int lookup_position_Single_Linked_List( const SL_List list, const int position ) {

	// 判空
	if ( judge_empty_Single_Linked_List(list) )
	{
		printf(" 单链表为空，没有查询的必要\n");

		return -1;
	}

	// 判断查询的位置是否在单链表的长度范围内
	//if ( position < list.count + 1 && position > 0 )
	if ( position > list.count || position < 1 )
	{
		printf(" 查询的位置，不在单链表的长度范围内\n");

		return -2;
	}

	// 用临时指针变量 index 遍历单链表进行定位
	// index 先定位在头指针指向的第一个结点的地址上
	Node* index = list.head;

	int i = 1;

	while (i < position)
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
	Node* index = list.head;

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
Node* lookup_position_return_address_Single_Linked_List( const SL_List list, const int position ) {

	// 判空
	if ( judge_empty_Single_Linked_List(list) )
	{
		printf(" 单链表为空，没有查询的必要\n");

		return NULL;
	}

	// 判断查询的位置是否在单链表的长度范围内
	//if ( position < list.count + 1 && position > 0 )
	if ( position > list.count || position < 1 )
	{
		printf(" 查询的位置，不在单链表的长度范围内\n");

		return NULL;
	}

	// 用临时指针变量 index 遍历单链表进行定位
	// index 先定位在头指针指向的第一个结点的地址上
	Node* index = list.head;

	int i = 1;

	while ( i < position )
	{
		index = index->next_pointer;

		i++;
	}

	return index;
}


// 按数值查询结点的地址
Node* lookup_value_return_address_Single_Linked_List( const SL_List list, const int value ) {

	// 判空
	if ( judge_empty_Single_Linked_List(list) )
	{
		printf(" 单链表为空，没有查询的必要\n");

		return NULL;
	}

	// 用临时指针变量 index 遍历单链表进行定位
	// index 先定位在头指针所指向的第一个结点的地址上
	Node* index = list.head;

	// 用来计数
	//int i = 1;

	while ( index != NULL )
	{
		if ( index->data == value )
		{
			return index;
		}

		index = index->next_pointer;

		//i++;
	}

	printf(" 查询的数值，不在单链表的长度范围内\n");

	return NULL;
}



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
	Node* temp = p->head;

	// 循环遍历整个单链表，逐一释放每个结点
	while ( p->head != NULL )
	{
		// 将头指针指向第一个结点的下一个结点（第二个）
		p->head = p->head->next_pointer;
		//p->head = temp->next_pointer;

		// 释放 temp 所指向的结点，原单链表的第一个结点
		free(temp);

		// 将 temp 再次指向下一个需要释放的结点
		// 现单链表第一个结点，原单链表第二个结点
		temp = p->head;
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
	Node* temp = list.head;

	printf(" 从单链表头开始：\n");

	while ( temp != NULL )
	{
		// 打印所指结点里面存放的值
		printf(" %d\n", temp->data);

		// 打印完成之后 temp 挪到 下一个结点处
		temp = temp->next_pointer;
	}

	printf(" 到单链表尾结束：\n");
}





int main()
{
	SL_List list = { 0 };

	init_Single_Linked_List( &list );

	print_Single_Linked_List( list );

	printf("\n-------------------------------\n\n");

	//insert_position_Single_Linked_List( &list, 2, 100);

	int i = 0;

	for ( i = 0; i < 10; i++ )
	{
		insert_position_Single_Linked_List( &list, i+1, (i+1)*100);
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

	for (i = 0; i < 10; i++)
	{
		insert_position_Single_Linked_List(&list, i + 1, (i + 1) * 100);
	}

	print_Single_Linked_List(list);

	clear_Single_Linked_List(&list);

	print_Single_Linked_List(list);

	printf("\n-------------------------------\n\n");

	for (i = 0; i < 10; i++)
	{
		insert_position_Single_Linked_List(&list, i + 1, (i + 1) * 100);
	}

	print_Single_Linked_List(list);

	printf(" 查询第 1 个的数值是：%d\n", lookup_position_Single_Linked_List(list, 1));

	printf(" 查询第 10 个的数值是：%d\n", lookup_position_Single_Linked_List(list, 10));

	printf(" 查询第 5 个的数值是：%d\n", lookup_position_Single_Linked_List(list, 5));


	printf(" 查询100是第 %d 个位置上的值\n", lookup_value_Single_Linked_List(list, 100));

	printf(" 查询1000是第 %d 个位置上的值\n", lookup_value_Single_Linked_List(list, 1000));

	printf(" 查询200是第 %d 个位置上的值\n", lookup_value_Single_Linked_List(list, 200));






	return 0;
}



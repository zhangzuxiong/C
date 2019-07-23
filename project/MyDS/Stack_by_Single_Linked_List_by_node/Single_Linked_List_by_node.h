#pragma once

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
	//Node* head;

	// 方式2
	Node head;

	// 下面的内容无论方式1还是2都需要用
	// 记录有效结点的个数
	int count;

} SL_List;



// 1.初始化
void  init_Single_Linked_List(SL_List* p);



// 2.判空 如果为空，则为真；否则为假
int judge_empty_Single_Linked_List(const SL_List list);



// 3.插入
// p 表示需要操作的单链表是谁， position 表示插入的位置， num 表示需要放入任意位置的数值是多少
void insert_position_Single_Linked_List(SL_List* p, const int position, const int num);


// 4.删除
int delete_position_Single_Linked_List(SL_List* p, const int position);


// 5.查询
// 按位置查询里面保存的数值
int lookup_position_Single_Linked_List(const SL_List list, const int position);


// 按数值查询结点为位置
int lookup_value_Single_Linked_List(const SL_List list, const int value);


// 按位置查询结点的地址
// 按数值查询结点的地址



// 6.清空
void clear_Single_Linked_List(SL_List* p);



// 7.打印
void print_Single_Linked_List(const SL_List list);
#pragma once


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	//前一个
	Node* pre;

	//下一个
	Node* next;

	//数据
	int data;

} Node;

typedef struct Double_Linked_List
{
	//头节点
	Node head;

	//尾节点
	Node tail;

	//有效元素个数
	int count;
} DL_List;


//初始化
void initDoubleLinkedList(DL_List* p);


//判空
bool judgeEmpotyDoubleLinked_List(const DL_List list);


//插入，在第position个位置插入一个数num
int insertPositionDoubleLinkedList(DL_List* p, const const int position, const int num);


//删除--根据位置删除
int deletePositionDoubleLinkedList(DL_List* p, const int position);


//查找--根据值查找，返回值的位置
int searchValueDoubleLinkedList(const DL_List list, const int num);

//查找--根据位置查找，返回这个位置的值
int searchPositionDoubleLinkedList(const DL_List list, const int position);

//查找--根据位置查找这个位置的地址
Node* searchPositionReturnAddressSingleLinkedList(const DL_List list, const int position);


//查找--按照值查询返回查找的地址
Node* searchValueReturnAddressSingleLinkedList(const DL_List list, const int value);

//清空
void clearDoubleLinkedList(DL_List* p);


//打印
void printDoubleLinkedList(const DL_List list);


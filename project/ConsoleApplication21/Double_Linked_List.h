#pragma once


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	//ǰһ��
	Node* pre;

	//��һ��
	Node* next;

	//����
	int data;

} Node;

typedef struct Double_Linked_List
{
	//ͷ�ڵ�
	Node head;

	//β�ڵ�
	Node tail;

	//��ЧԪ�ظ���
	int count;
} DL_List;


//��ʼ��
void initDoubleLinkedList(DL_List* p);


//�п�
bool judgeEmpotyDoubleLinked_List(const DL_List list);


//���룬�ڵ�position��λ�ò���һ����num
int insertPositionDoubleLinkedList(DL_List* p, const const int position, const int num);


//ɾ��--����λ��ɾ��
int deletePositionDoubleLinkedList(DL_List* p, const int position);


//����--����ֵ���ң�����ֵ��λ��
int searchValueDoubleLinkedList(const DL_List list, const int num);

//����--����λ�ò��ң��������λ�õ�ֵ
int searchPositionDoubleLinkedList(const DL_List list, const int position);

//����--����λ�ò������λ�õĵ�ַ
Node* searchPositionReturnAddressSingleLinkedList(const DL_List list, const int position);


//����--����ֵ��ѯ���ز��ҵĵ�ַ
Node* searchValueReturnAddressSingleLinkedList(const DL_List list, const int value);

//���
void clearDoubleLinkedList(DL_List* p);


//��ӡ
void printDoubleLinkedList(const DL_List list);


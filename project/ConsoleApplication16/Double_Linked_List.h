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
void init_Double_Linked_List(DL_List* p);


//�п�
bool judge_Empoty_Double_Linked_List(const DL_List list);


//���룬�ڵ�position��λ�ò���һ����num
int insert_Position_Double_Linked_List(DL_List* p, const const int position, const int num);


//ɾ��--����λ��ɾ��
int delete_Position_Double_Linked_List(DL_List* p, const int position);


//����--����ֵ���ң�����ֵ��λ��
int search_Value_Double_Linked_List(const DL_List list, const int num);

//����--����λ�ò��ң��������λ�õ�ֵ
int search_Position_Double_Linked_List(const DL_List list, const int position);

//����--����λ�ò������λ�õĵ�ַ
Node* search_Position_Return_Address_Single_Linked_List(const DL_List list, const int position);


//����--����ֵ��ѯ���ز��ҵĵ�ַ
Node* search_Value_Return_Address_Single_Linked_List(const DL_List list, const int value);

//���
void clear_Double_Linked_List(DL_List* p);


//��ӡ
void print_Double_Linked_List(const DL_List list);


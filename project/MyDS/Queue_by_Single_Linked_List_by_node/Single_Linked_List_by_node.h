#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <stdlib.h>

/*
	���������������

	���һ���ṹ�壬�ýṹ�������ʵ��һ������

	��������Ϊ����������

*/

// ��ƽ�����������
typedef struct Node {

	int data;

	Node* next_pointer;

} Node;

// ��Ƶ��������������
typedef struct Single_Linked_List {

	// ��ʽ1
	//Node* head;

	// ��ʽ2
	Node head;

	// ������������۷�ʽ1����2����Ҫ��
	// ��¼��Ч���ĸ���
	int count;

} SL_List;



// 1.��ʼ��
void  init_Single_Linked_List(SL_List* p);



// 2.�п� ���Ϊ�գ���Ϊ�棻����Ϊ��
int judge_empty_Single_Linked_List(const SL_List list);



// 3.����
// p ��ʾ��Ҫ�����ĵ�������˭�� position ��ʾ�����λ�ã� num ��ʾ��Ҫ��������λ�õ���ֵ�Ƕ���
void insert_position_Single_Linked_List(SL_List* p, const int position, const int num);


// 4.ɾ��
int delete_position_Single_Linked_List(SL_List* p, const int position);


// 5.��ѯ
// ��λ�ò�ѯ���汣�����ֵ
int lookup_position_Single_Linked_List(const SL_List list, const int position);


// ����ֵ��ѯ���Ϊλ��
int lookup_value_Single_Linked_List(const SL_List list, const int value);


// ��λ�ò�ѯ���ĵ�ַ
// ����ֵ��ѯ���ĵ�ַ



// 6.���
void clear_Single_Linked_List(SL_List* p);



// 7.��ӡ
void print_Single_Linked_List(const SL_List list);
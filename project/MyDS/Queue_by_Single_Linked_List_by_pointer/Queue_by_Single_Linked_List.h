#pragma once

#include "Single_Linked_List.h"


// ������ʵ�ֶ���

typedef struct Queue {

	// �õ������������������
	SL_List list;

	// ���е��������
	int max;

	// ��¼������е���ЧԪ�ظ���
	int count;

	// ��Ƕ��е�ͷ
	int head;
	//Node* head;

	// ��Ƕ��е�β
	int tail;
	//Node* tail;

} Queue;



// 1.��ʼ��
void init_Queue(Queue* p);



// 2.�п� ���Ϊ�գ���Ϊ�棻����Ϊ��
int judge_empty(const Queue queue);



// 3.���� ���Ϊ������Ϊ�棻����Ϊ��
int judge_full(const Queue queue);



// 4.����
// p ��ʾ��Ҫ�����Ķ�����˭�� num ��ʾ��Ҫ�����β����ֵ�Ƕ���
void put_Queue(Queue* p, const int num);



// 5.ȡ��
int get_Queue(Queue* p);



// 6.���
void clear_Queue(Queue* p);



// 7.��ӡ
void print_Queue(const Queue queue);

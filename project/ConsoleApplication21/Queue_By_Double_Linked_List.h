#pragma once

#include "Double_Linked_List.h"


// ˫����ʵ�ֶ���

typedef struct Queue {

	// ��˫�����������������
	DL_List list;

	// ���е��������
	int max;

	// ��¼������е���ЧԪ�ظ���
	int count;

	// ��Ƕ��е�ͷ
	int head;

	// ��Ƕ��е�β
	int tail;

} Queue;


// 1.��ʼ��
void initQueue(Queue* p);



// 2.�п� ���Ϊ�գ���Ϊ�棻����Ϊ��
int isEmpty(const Queue queue);



// 3.���� ���Ϊ������Ϊ�棻����Ϊ��
int isFull(const Queue queue);



// 4.����,p ��ʾ��Ҫ�����Ķ�����˭�� num ��ʾ��Ҫ�����β����ֵ�Ƕ���
void putQueue(Queue* p, const int num);



// 5.ȡ��
int getQueue(Queue* p);



// 6.���
void clearQueue(Queue* p);



// 7.��ӡ
void printQueue(const Queue queue);


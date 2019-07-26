#pragma once


#include "Array_List.h"

typedef struct Queue
{
	//����
	ArrayList list;

	//���е��������
	int max;

	//���е���ЧԪ�ظ���
	int count;


	//���е�ͷ��βֻ��������
	//���е�ͷ
	int head;

	//���е�β
	int tail;

} Queue;


// 1.��ʼ��
void initQueue(Queue* p);



// 2.�п� ���Ϊ�գ���Ϊ�棻����Ϊ��
int isEmpty(const Queue queue);



// 3.���� ���Ϊ������Ϊ�棻����Ϊ��
int isFull(const Queue queue);



// 4.����,p ��ʾ��Ҫ�����Ķ�����˭�� num ��ʾ��Ҫ������е���ֵ�Ƕ���
void putQueue(Queue* p, const Element num);



// 5.ȡ��
Element getQueue(Queue* p);



// 6.���
void clearQueue(Queue* p);



// 7.��ӡ
void printQueue(const Queue stack);



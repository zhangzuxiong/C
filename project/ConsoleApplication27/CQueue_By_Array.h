#pragma once


#include "Array_List.h"

typedef struct CQueue
{
	//����
	ArrayList list;

	//ѭ�����е��������
	int max;

	//ѭ�����е���ЧԪ�ظ���
	int count;

} CQueue;


// 1.��ʼ��
void initCQueue(CQueue* p);



// 2.�п� ���Ϊ�գ���Ϊ�棻����Ϊ��
int isEmpty(const CQueue queue);



// 3.���� ���Ϊ������Ϊ�棻����Ϊ��
int isFull(const CQueue queue);



// 4.����,p ��ʾ��Ҫ������ѭ��������˭�� num ��ʾ��Ҫ����ѭ�����е���ֵ�Ƕ���
void putCQueue(CQueue* p, const Element num);



// 5.ȡ��
Element getCQueue(CQueue* p);



// 6.���
void clearCQueue(CQueue* p);



// 7.��ӡ
void printCQueue(const CQueue stack);



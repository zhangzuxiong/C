#pragma once

#include "Double_Linked_List.h"


// ˫����ʵ��ѭ������

typedef struct CQueue {

	// ��˫�����������������
	DL_List list;

	// ���е��������
	int max;

	// ��¼������е���ЧԪ�ظ���
	int count;

} CQueue;


// 1.��ʼ��
void initCQueue(CQueue* p);



// 2.�п� ���Ϊ�գ���Ϊ�棻����Ϊ��
int isEmpty(const CQueue queue);



// 3.���� ���Ϊ������Ϊ�棻����Ϊ��
int isFull(const CQueue queue);



// 4.����,p ��ʾ��Ҫ�����Ķ�����˭�� num ��ʾ��Ҫ�����β����ֵ�Ƕ���
void putCQueue(CQueue* p, const int num);



// 5.ȡ��
int getCQueue(CQueue* p);



// 6.���
void clearCQueue(CQueue* p);



// 7.��ӡ
void printCQueue(const CQueue queue);


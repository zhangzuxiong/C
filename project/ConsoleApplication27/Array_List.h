#pragma once


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE 100//���ֵĴ�С

typedef int Element;//���鱣���Ԫ������

typedef struct ArrayList
{
	//��������
	Element arr[SIZE];


	//��ЧԪ��
	int count;

}ArrayList;




//��ʼ��ȫ����ֵΪ0
void initArrayList(ArrayList* p);

//�ж��Ƿ�Ϊ��
int isEmpoty(const ArrayList array);

//����
int isFull(const ArrayList array);

//����,������ĵ�position��λ�÷���value
void insertArrayList(ArrayList*p,const int position,const Element value);

//ȡ��,ȡ�������еĵ�position��λ�õ�ֵ
Element getArrayList(ArrayList* p, const int position);

//���
void clearArrayList(ArrayList* p);

//��ӡ
void printArrayList(const ArrayList array);

//����
Element searchArrayList(const ArrayList array, const Element value);


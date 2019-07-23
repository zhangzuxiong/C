#pragma once

#include  "Single_Linked_List.h"

typedef struct Stack {

	// ʹ�õ���������������ֵ
	SL_List list;
	//SL_List* p;

	// ջ���������
	int max;

	// ��¼����ջ����ЧԪ�ظ���
	int count;

} Stack;



// 1.��ʼ��
void init_Stack(Stack* p);



// 2.�п� ���Ϊ�գ���Ϊ�棻����Ϊ��
int judge_empty( const Stack stack );



// 3.���� ���Ϊ������Ϊ�棻����Ϊ��
int judge_full( const Stack stack );



// 4.ѹ��
// p ��ʾ��Ҫ������ջ��˭�� num ��ʾ��Ҫѹ��ջ����ֵ�Ƕ���
void push_Stack( Stack* p, const int num );



// 5.����
// �����ı��������ͣ�ȡ����ջ�����ŵ�Ԫ�ص�����
// �����ı�Ȼ��ջ�����Ǹ�Ԫ�أ����Բ���Ҫ�β���֪����Ҫ�����ĸ�Ԫ��
int pop_Stack( Stack* p );



// 6.���
void clear_Stack( Stack* p );



// 7.��ӡ
void print_Stack( const Stack stack );
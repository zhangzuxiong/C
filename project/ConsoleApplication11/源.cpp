// ConsoleApplication11.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//����ʵ��ջ--ͷָ������һ������

/*
	ͷ����ͷָ�������
		ͷָ���һ����Ҫ��ʼ����������ݣ�
		ͷ����һ��������Ҫ������ݣ�ֻ��������һ����ǣ�������Ҫ��ʼ����

	����ʵ��ջʱ�����ݴ�ͷָ�뿪ʼ��ţ�
				���ߴ�ͷ������һ���ڵ㿪ʼ���

*/

#include "Stack.h"


int main()
{
	Stack stack = { 0 };
	init(&stack);
	push(&stack, 10);
	clear(&stack);
	display(stack);

	return 0;

	is_empoty(stack);
	push(&stack, 10);
	push(&stack, 12);
	push(&stack, 13);
	push(&stack, 14);
	display(stack);

	printf("%d\n", pop(&stack));
	printf("%d\n", pop(&stack));
	printf("%d\n", pop(&stack));
	printf("%d\n", pop(&stack));
	display(stack);

	return 0;
}

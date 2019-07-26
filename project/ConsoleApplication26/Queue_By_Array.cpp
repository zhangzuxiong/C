
#include "Queue_By_Array.h"


// 1.��ʼ��
void initQueue(Queue* p) {

	// ָ���п�
	if (p == NULL)
	{
		return;
	}

	// �ֶ����������Ҫ���������
	printf(" �����������Ҫ���������������������");

	scanf(" %d", &(p->max));

	// ����ʹ�õ������飬����ʼ�����У����ǳ�ʼ���������� ����
	initArrayList(&(p->list));

	// ������ЧԪ�صĸ��� ����
	p->count = 0;

	p->head = 0;

	p->tail = 0;
}



// 2.�п� ���Ϊ�գ���Ϊ�棻����Ϊ��
int isEmpty(const Queue queue) {

	if (queue.count == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}



// 3.���� ���Ϊ������Ϊ�棻����Ϊ��
int isFull(const Queue queue) {

	if (queue.max == queue.tail)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}



// 4.����,p ��ʾ��Ҫ�����Ķ�����˭�� num ��ʾ��Ҫ������е���ֵ�Ƕ���
void putQueue(Queue* p, const Element num) {

	// ָ���п�
	if (p == NULL)
	{
		return;
	}

	// ����
	if (isFull(*p))
	{
		printf(" �����������޷������µ�Ԫ��\n");
		return;
	}

	// �����з���һ��ֵ
	// �൱���������һλ����һ��Ԫ��
	insertArrayList(&(p->list), 1, num);

	// ��ЧԪ�صĸ��� +1
	p->count++;

	p->tail++;
}



// 5.ȡ��
Element getQueue(Queue* p) {

	// ָ���п�
	if (p == NULL)
	{

		return NULL;
	}

	// �п�
	if (isEmpty(*p))
	{
		printf(" ����Ϊ�գ�û�п��Գ��ӵ�Ԫ��\n");

		return NULL;
	}

	// ����Ҫ��������ֵ�ȱ�������
	int res = p->list.arr[0];


	// �൱�� ɾ�� ����ĵ�һ��Ԫ��
	getArrayList(&(p->list), 1);

	// ����һ�д���ȼ�����������
	//int res = getArrayList(&(p->list), 1);

	// ���е���ЧԪ�ظ��� -1
	p->count--;

	p->head++;

	if (p->head == p->tail)
	{
		p->head = 0;
		p->tail = 0;
	}

	return res;
}



// 6.���
void clearQueue(Queue* p) {

	// ָ���п�
	if (p == NULL)
	{
		//printf(" ��պ����β�Ϊ��\n");

		return;
	}

	// �п�
	if (isEmpty(*p))
	{
		printf(" ��ǰ����Ϊ�գ�û����յı�Ҫ\n");

		return;
	}

	//���һ�����У�ʵ������Ҫ�������
	clearArrayList(&(p->list));

	// ���е���ЧԪ�ظ��� ����
	p->count = 0;

	p->head = 0;
	p->tail = 0;
}



// 7.��ӡ
void printQueue(const Queue stack) {

	// �п�
	if (isEmpty(stack))
	{
		printf(" ����Ϊ�գ�û�п��Դ�ӡ��Ԫ��\n");

		return;
	}


	printArrayList(stack.list);
}


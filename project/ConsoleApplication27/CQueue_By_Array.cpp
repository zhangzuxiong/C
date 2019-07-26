
#include "CQueue_By_Array.h"


// 1.��ʼ��
void initCQueue(CQueue* p) {

	// ָ���п�
	if (p == NULL)
	{
		return;
	}

	// �ֶ�����ѭ��������Ҫ���������
	printf(" �����������Ҫ���������������������");

	scanf(" %d", &(p->max));

	// ѭ������ʹ�õ������飬����ʼ��ѭ�����У����ǳ�ʼ���������� ����
	initArrayList(&(p->list));

	// ѭ��������ЧԪ�صĸ��� ����
	p->count = 0;

}



// 2.�п� ���Ϊ�գ���Ϊ�棻����Ϊ��
int isEmpty(const CQueue queue) {

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
int isFull(const CQueue queue) {

	if (queue.max == queue.count)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}



// 4.����,p ��ʾ��Ҫ������ѭ��������˭�� num ��ʾ��Ҫ����ѭ�����е���ֵ�Ƕ���
void putCQueue(CQueue* p, const Element num) {

	// ָ���п�
	if (p == NULL)
	{
		return;
	}

	// ����
	if (isFull(*p))
	{
		printf(" ѭ�������������޷������µ�Ԫ��\n");
		return;
	}

	// �����з���һ��ֵ
	// �൱���������һλ����һ��Ԫ��
	insertArrayList(&(p->list), 1, num);

	// ��ЧԪ�صĸ��� +1
	p->count++;
}



// 5.ȡ��
Element getCQueue(CQueue* p) {

	// ָ���п�
	if (p == NULL)
	{

		return NULL;
	}

	// �п�
	if (isEmpty(*p))
	{
		printf(" ѭ������Ϊ�գ�û�п��Գ��ӵ�Ԫ��\n");

		return NULL;
	}

	// ����Ҫ��������ֵ�ȱ�������
	int res = p->list.arr[0];


	// �൱�� ɾ�� ����ĵ�һ��Ԫ��
	getArrayList(&(p->list), 1);

	// ����һ�д���ȼ�����������
	//int res = getArrayList(&(p->list), 1);

	// ѭ�����е���ЧԪ�ظ��� -1
	p->count--;

	return res;
}



// 6.���
void clearCQueue(CQueue* p) {

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

	//���һ��ѭ�����У�ʵ������Ҫ�������
	clearArrayList(&(p->list));

	// ѭ�����е���ЧԪ�ظ��� ����
	p->count = 0;

}



// 7.��ӡ
void printCQueue(const CQueue stack) {

	// �п�
	if (isEmpty(stack))
	{
		printf(" ѭ������Ϊ�գ�û�п��Դ�ӡ��Ԫ��\n");

		return;
	}


	printArrayList(stack.list);
}


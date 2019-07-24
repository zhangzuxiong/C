
#include "CQueue_By_Double_Linked_List.h"

// 1.��ʼ��
void initCQueue(CQueue* p) {

	// ָ���п�
	if (p == NULL)
	{
		printf("��ʼ�������β�Ϊ��\n");

		return;
	}

	// �ֶ�������пռ���Ҫ���������
	printf(" ������ѭ�����пռ���Ҫ���������������������");

	scanf(" %d", &(p->max));


	// ��ʼ�����еĴ洢�ռ䣬���ǳ�ʼ��˫����
	initDoubleLinkedList(&(p->list));


	// ��������ЧԪ�صĸ��� ����
	p->count = 0;
}



// 2.�п� ���Ϊ�գ���Ϊ�棻����Ϊ��
int isEmpty(const CQueue queue) {

	if (queue.count == 0)
	{
		printf(" ѭ������ Ϊ��\n");

		return 1;
	}
	else
	{
		printf(" ѭ������ ��Ϊ��\n");

		return 0;
	}
}



// 3.���� ���Ϊ������Ϊ�棻����Ϊ��
int isFull(const CQueue queue) {

	if (queue.count == queue.max)
	{
		printf(" ѭ������ Ϊ��\n");

		return 1;
	}
	else
	{
		printf(" ѭ������ ��Ϊ��\n");

		return 0;
	}
}



// 4.����,p ��ʾ��Ҫ�����Ķ�����˭�� num ��ʾ��Ҫ�����β����ֵ�Ƕ���
void putCQueue(CQueue* p, const int num) {

	// ָ���п�
	if (p == NULL)
	{
		printf(" ���뺯���β�Ϊ��\n");

		return;
	}

	// ����
	if (isFull(*p))
	{
		printf(" ��ǰѭ������Ϊ�����޷������µ�Ԫ��\n");

		return;
	}

	// �ҵ����е�ĩβ���� num ����
	// �൱����˫�����ĩβ����һ���µĽ��
	insertPositionDoubleLinkedList(&(p->list), p->count + 1, num);

	//��ЧԪ�ؼ�1
	p->count++;
}



// 5.ȡ��
int getCQueue(CQueue* p) {

	// ָ���п�
	if (p == NULL)
	{
		printf(" ȡ�������β�Ϊ��\n");

		return -1;
	}

	// �п�
	if (isEmpty(*p))
	{
		printf(" ��ǰѭ������Ϊ�գ�û�п���ȡ����Ԫ��\n");

		return -2;
	}

	// ��һ����ʱ����������Ҫ���ص���ֵ
	int temp = 0;

	// �൱�ڴ�˫�����ͷ ȡ����һ��������ֵ
	temp = p->list.head.next->data;

	// ɾ��������ͷ�ĵ�һ�����
	deletePositionDoubleLinkedList(&(p->list), 1);

	// ����һ�д������ȡ���������д���
	//int temp = deletePositionDoubleLinkedList(&(p->list), 1);

	// ��ЧԪ�ظ��� -1
	p->count--;

	return temp;
}



// 6.���
void clearCQueue(CQueue* p) {

	// ָ���п�
	if (p == NULL)
	{
		printf(" ��պ����β�Ϊ��\n");

		return;
	}

	// �п�
	if (isEmpty(*p))
	{
		printf(" ��ǰѭ������Ϊ�գ�û����յı�Ҫ\n");

		return;
	}

	//���һ�����У�ʵ���Ͼ������˫����
	clearDoubleLinkedList(&(p->list));

	// ��ЧԪ�صĸ��� ����
	p->count = 0;
}



// 7.��ӡ
void printCQueue(const CQueue queue) {

	// �п�
	if (isEmpty(queue))
	{
		printf(" ��ǰѭ������Ϊ�գ�û�п��Դ�ӡ��Ԫ��\n");

		return;
	}

	//��ӡ��ʱ����Ҫ���ն��е�ͼ�δ�ӡ���ȴ�ӡ���е�ͷ�������β
	printDoubleLinkedList(queue.list);
}



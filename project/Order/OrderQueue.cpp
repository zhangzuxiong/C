
#include "OrderQueue.h"
// 1.��ʼ��
void initOrderCQueue(OrderCQueue* p) {

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
	initOrderList(&(p->list));


	// ��������ЧԪ�صĸ��� ����
	p->count = 0;
}



// 2.�п� ���Ϊ�գ���Ϊ�棻����Ϊ��
int isEmptyOrderCQueue(const OrderCQueue queue) {

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
int isFullOrderCQueue(const OrderCQueue queue) {

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



// 4.����,p ��ʾ��Ҫ�����Ķ�����˭�� num ��ʾ��Ҫ�����β�Ķ����Ƕ���
void putOrderCQueue(OrderCQueue* p, const Order order) {

	// ָ���п�
	if (p == NULL)
	{
		printf(" ���뺯���β�Ϊ��\n");

		return;
	}

	// ����
	if (isFullOrderCQueue(*p))
	{
		printf(" ��ǰѭ������Ϊ�����޷������µ�Ԫ��\n");

		return;
	}

	// �ҵ����е�ĩβ���� num ����
	// �൱����˫�����ĩβ����һ���µĽ��
	insertPositionOrderList(&(p->list), p->count + 1, order);

	//��ЧԪ�ؼ�1
	p->count++;
}



// 5.ȡ��
Order* getOrderCQueue(OrderCQueue* p) {

	// ָ���п�
	if (p == NULL)
	{
		printf(" ȡ�������β�Ϊ��\n");

		return NULL;
	}

	// �п�
	if (isEmptyOrderCQueue(*p))
	{
		printf(" ��ǰѭ������Ϊ�գ�û�п���ȡ����Ԫ��\n");

		return NULL;
	}

	// ��һ����ʱ����������Ҫ���ص���ֵ
	Order temp = { 0 };

	// �൱�ڴ�˫�����ͷ ȡ����һ��������ֵ
	temp = p->list.head->order;

	// ɾ��������ͷ�ĵ�һ�����
	deletePositionOrderList(&(p->list), 1);

	// ����һ�д������ȡ���������д���
	//Order temp = deletePositionOrderList(&(p->list), 1);

	// ��ЧԪ�ظ��� -1
	p->count--;

	return &temp;
}



// 6.���
void clearOrderCQueue(OrderCQueue* p) {

	// ָ���п�
	if (p == NULL)
	{
		printf(" ��պ����β�Ϊ��\n");

		return;
	}

	// �п�
	if (isEmptyOrderCQueue(*p))
	{
		printf(" ��ǰѭ������Ϊ�գ�û����յı�Ҫ\n");

		return;
	}

	//���һ�����У�ʵ���Ͼ������˫����
	clearOrderList(&(p->list));

	// ��ЧԪ�صĸ��� ����
	p->count = 0;
}



// 7.��ӡ
void printOrderCQueue(const OrderCQueue queue) {

	// �п�
	if (isEmptyOrderCQueue(queue))
	{
		printf(" ��ǰѭ������Ϊ�գ�û�п��Դ�ӡ��Ԫ��\n");

		return;
	}

	//��ӡ��ʱ����Ҫ���ն��е�ͼ�δ�ӡ���ȴ�ӡ���е�ͷ�������β
	printOrderList(queue.list);
}


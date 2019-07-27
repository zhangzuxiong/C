
#include "OrderQueue.h"
/*

// 1.��ʼ��
void init_Circular_Queue(CQ* p) {

	// ָ���п�
	if (p == NULL)
	{
		printf(" initt_Circular_Queue �����β�Ϊ��\n");

		return;
	}

	// �ֶ�����ѭ�����пռ���Ҫ���������
	printf(" ������ѭ�����пռ���Ҫ���������������������");

	scanf(" %d", &(p->max));

	// ���Գ��Զ���������ֽ��з����������ж�

	// ��ʼ�� ѭ���������������������ֵ�� ������
	init_Single_Linked_List(&(p->list));

	// ���Գ��Զ�������ڴ�ռ������ֵ����ʼ����

	// ѭ����������ЧԪ�صĸ��� ����
	p->count = 0;
}



// 2.�п� ���Ϊ�գ���Ϊ�棻����Ϊ��
int judge_empty(const CQ cqueue) {

	if (cqueue.count == 0)
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
int judge_full(const CQ cqueue) {


	//��ѭ�����д�ŵ���ЧԪ�صĸ����ﵽ��������ʱ�������������ʵ����

	if (cqueue.count == cqueue.max)
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



// 4.����
// p ��ʾ��Ҫ������ѭ��������˭�� num ��ʾ��Ҫ�����β����ֵ�Ƕ���
void put_Circular_Queue(CQ* p, const int num) {

	// ָ���п�
	if (p == NULL)
	{
		printf(" put_Circular_Queue �����β�Ϊ��\n");

		return;
	}

	// ����
	if (judge_full(*p))
	{
		printf(" ��ǰѭ������Ϊ�����޷������µ�Ԫ��\n");

		return;
	}

	// �ҵ����е�ĩβ���� num ����
	// ʵ���Ͼ����� ����������ֵ�� ������ ĩβ����һ���µĽ��
	insert_position_Single_Linked_List(&(p->list), p->count + 1, num);

	// ��ЧԪ�صĸ���
	p->count++;
}



// 5.ȡ��
int get_Circular_Queue(CQ* p) {

	// ָ���п�
	if (p == NULL)
	{
		printf(" get_Circular_Queue �����β�Ϊ��\n");

		return -1;
	}

	// �п�
	if (judge_empty(*p))
	{
		printf(" ��ǰѭ������Ϊ�գ�û�п���ȡ����Ԫ��\n");

		return -2;
	}

	// �� head ����ǵ�λ��ȡ����Ӧ��Ԫ��
	// ʵ���� �Ǵ����汣������ֵ�� �������ͷ ȡ����һ�����
	// ����ʱ���� temp ���浥����ɾ��ͷ���ĵ�һ�����ʱ���ص�����ֵ
	int temp = delete_position_Single_Linked_List(&(p->list), 1);

	// ��ЧԪ�ظ��� -1
	p->count--;

	return temp;
}



// 6.���
void clear_Circular_Queue(CQ* p) {

	// ָ���п�
	if (p == NULL)
	{
		printf(" clear_Circular_Queue �����β�Ϊ��\n");

		return;
	}

	// �п�
	if (judge_empty(*p))
	{
		printf(" ��ǰѭ������Ϊ�գ�û����յı�Ҫ\n");

		return;
	}


		//���һ��ѭ������

		//ʵ���Ͼ����������������������ֵ�� ������

	clear_Single_Linked_List(&(p->list));

	// ��ЧԪ�صĸ��� ����
	p->count = 0;
}



// 7.��ӡ
void print_Circular_Queue(const CQ cqueue) {

	// �п�
	if (judge_empty(cqueue))
	{
		printf(" ��ǰѭ������Ϊ�գ�û�п��Դ�ӡ��Ԫ��\n");

		return;
	}


		//��ͷ��β��ӡѭ������

		//ʵ�ʾ��Ǵ�ͷ��β ��ӡ ���е��Ǹ�������

	printf(" ��ѭ�����е�ͷ��ʼ��\n");

	print_Single_Linked_List(cqueue.list);

	printf(" ��ѭ�����е�β������\n");
}

*/

#include "Queue_by_Single_Linked_List.h"

// 1.��ʼ��
void init_Queue(Queue* p) {

	// ָ���п�
	if (p == NULL)
	{
		printf(" init_Queue �����β�Ϊ��\n");

		return;
	}

	// �ֶ�������пռ���Ҫ���������
	printf(" ��������пռ���Ҫ���������������������");

	scanf(" %d", &(p->max));

	// ���Գ��Զ���������ֽ��з����������ж�

	// ��ʼ�����еĴ洢�ռ䣬���ǳ�ʼ��������
	init_Single_Linked_List(&(p->list));

	// ���Գ��Զ�������ڴ�ռ������ֵ����ʼ����

	// ��������ЧԪ�صĸ��� ����
	p->count = 0;

	// ͷ���õ�����ĵ�һ��Ԫ��
	p->head = 0;

	// β���õ�����ĵ�һ��Ԫ��
	p->tail = 0;

}



// 2.�п� ���Ϊ�գ���Ϊ�棻����Ϊ��
int judge_empty(const Queue queue) {

	if (queue.count == 0)
	{
		printf(" ���� Ϊ��\n");

		return 1;
	}
	else
	{
		printf(" ���� ��Ϊ��\n");

		return 0;
	}
}



// 3.���� ���Ϊ������Ϊ�棻����Ϊ��
int judge_full(const Queue queue) {

	/*
		�� tail �ߵ������ĩβʱ����ʵǰ�� head �����Ѿ�Ų�����Դ�ŵĿռ��ˣ�
		���� tail ����ʹ����Щ�ռ䣬����Ǹ��ٵ���
	*/
	if (queue.tail == queue.max)
	{
		printf(" ���� Ϊ��\n");

		return 1;
	}
	else
	{
		printf(" ���� ��Ϊ��\n");

		return 0;
	}
}



// 4.����
// p ��ʾ��Ҫ�����Ķ�����˭�� num ��ʾ��Ҫ�����β����ֵ�Ƕ���
void put_Queue(Queue* p, const int num) {

	// ָ���п�
	if (p == NULL)
	{
		printf(" put_Queue �����β�Ϊ��\n");

		return;
	}

	// ����
	if (judge_full(*p))
	{
		printf(" ��ǰ����Ϊ�����޷������µ�Ԫ��\n");

		return;
	}

	// �ҵ����е�ĩβ���� num ����
	// �൱���ڵ������ĩβ����һ���µĽ��
	insert_position_Single_Linked_List(&(p->list), p->count + 1, num);

	// ��β���Ųһ��
	p->tail++;

	// ��ЧԪ�صĸ���
	p->count++;
}



// 5.ȡ��
int get_Queue(Queue* p) {

	// ָ���п�
	if (p == NULL)
	{
		printf(" get_Queue �����β�Ϊ��\n");

		return -1;
	}

	// �п�
	if (judge_empty(*p))
	{
		printf(" ��ǰ����Ϊ�գ�û�п���ȡ����Ԫ��\n");

		return -2;
	}

	// ��һ����ʱ����������Ҫ���ص���ֵ
	int temp = 0;

	// �൱�ڴӵ������ͷ ȡ����һ��������ֵ
	temp = p->list.head.next_pointer->data;

	// ɾ��������ͷ�ĵ�һ�����
	delete_position_Single_Linked_List(&(p->list), 1);

	// ����һ�д������ȡ���������д��루�Ƽ�ʹ������һ�д��룩
	//int temp = delete_position_Single_Linked_List(&(p->list), 1);

	// ��ЧԪ�ظ��� -1
	p->count--;

	// head �Ⱥ�Ųһ��
	p->head++;

	// �ж� head �Ƿ� ȡ���˶��У����ȡ�ն��У�head �� tail Ҫ���������һ��Ԫ�ص�λ��
	if (p->head == p->tail)
	{
		p->head = 0;
		p->tail = 0;
	}

	return temp;
}



// 6.���
void clear_Queue(Queue* p) {

	// ָ���п�
	if (p == NULL)
	{
		printf(" clear_Queue �����β�Ϊ��\n");

		return;
	}

	// �п�
	if (judge_empty(*p))
	{
		printf(" ��ǰ����Ϊ�գ�û����յı�Ҫ\n");

		return;
	}

	/*
		���һ�����У�ʵ���Ͼ�����յ�����
	*/
	clear_Single_Linked_List(&(p->list));

	// ��ЧԪ�صĸ��� ����
	p->count = 0;

	// ͷ��β�ص�����ĵ�һ��Ԫ����
	p->head = 0;

	p->tail = 0;
}



// 7.��ӡ
void print_Queue(const Queue queue) {

	// �п�
	if (judge_empty(queue))
	{
		printf(" ��ǰ����Ϊ�գ�û�п��Դ�ӡ��Ԫ��\n");

		return;
	}

	/*
		��ӡ��ʱ����Ҫ���ն��е�ͼ�δ�ӡ���ȴ�ӡ���е�ͷ�������β
	*/
	printf(" �Ӷ��е�ͷ��ʼ��\n");

	print_Single_Linked_List(queue.list);

	printf(" �����е�β������\n");
}



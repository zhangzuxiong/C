
#include "Stack_by_Single_Linked_List.h"


// 1.��ʼ��
void init_Stack(Stack* p) {

	// ָ���п�
	if (p == NULL)
	{
		printf(" init_Stack �����β�Ϊ��\n");

		return;
	}

	// �ֶ�����ջ�ռ���Ҫ���������
	printf(" ������ջ�ռ���Ҫ���������������������");

	scanf(" %d", &(p->max));

	// ջʹ�õ��ǵ���������ʼ��ջ�����ǳ�ʼ���������� ������
	init_Single_Linked_List(&(p->list));

	// ���Գ��Զ�������ڴ�ռ������ֵ����ʼ����

	// ջ����ЧԪ�صĸ��� ����
	p->count = 0;
}



// 2.�п� ���Ϊ�գ���Ϊ�棻����Ϊ��
int judge_empty(const Stack stack) {

	if (stack.count == 0)
	{
		printf(" ջ Ϊ��\n");

		return 1;
	}
	else
	{
		printf(" ջ ��Ϊ��\n");

		return 0;
	}
}



// 3.���� ���Ϊ������Ϊ�棻����Ϊ��
int judge_full(const Stack stack) {

	if (stack.count == stack.max)
	{
		printf(" ջ Ϊ��\n");

		return 1;
	}
	else
	{
		printf(" ջ ��Ϊ��\n");

		return 0;
	}
}



// 4.ѹ��
// p ��ʾ��Ҫ������ջ��˭�� num ��ʾ��Ҫѹ��ջ����ֵ�Ƕ���
void push_Stack(Stack* p, const int num) {

	// ָ���п�
	if (p == NULL)
	{
		printf(" push_Stack �����β�Ϊ��\n");

		return;
	}

	// ����
	if (judge_full(*p))
	{
		printf(" ��ǰջΪ�����޷������µ�Ԫ��\n");

		return;
	}

	// ��ջ������һ��ֵ
	// �൱���ڵ������ͷ����һ���½��
	insert_position_Single_Linked_List(&(p->list), 1, num);

	// ��ЧԪ�صĸ��� +1
	p->count++;
}



// 5.����
// �����ı��������ͣ�ȡ����ջ�����ŵ�Ԫ�ص�����
// �����ı�Ȼ��ջ�����Ǹ�Ԫ�أ����Բ���Ҫ�β���֪����Ҫ�����ĸ�Ԫ��
int pop_Stack(Stack* p) {

	// ָ���п�
	if (p == NULL)
	{
		printf(" pop_Stack �����β�Ϊ��\n");

		return -1;
	}

	// �п�
	if (judge_empty(*p))
	{
		printf(" ��ǰջΪ�գ�û�п��Ե�����Ԫ��\n");

		return -2;
	}

	// ����Ҫ��������ֵ�ȱ�������
	int res = p->list.head.next_pointer->data;

	// ����ջ��Ԫ��
	// �൱�� ɾ�� ������ĵ�һ����Ч���
	delete_position_Single_Linked_List(&(p->list), 1);

	// ����һ�д���ȼ����������У��Ƽ�ʹ������һ�д��룩
	//int res = delete_position_Single_Linked_List(&(p->list), 1);

	// ջ�������ЧԪ�ظ��� -1
	p->count--;

	return res;
}



// 6.���
void clear_Stack(Stack* p) {

	// ָ���п�
	if (p == NULL)
	{
		printf(" clear_Stack �����β�Ϊ��\n");

		return;
	}

	// �п�
	if (judge_empty(*p))
	{
		printf(" ��ǰջΪ�գ�û����յı�Ҫ\n");

		return;
	}

	/*
		���һ��ջ��ʵ������Ҫ��յ�����
	*/
	clear_Single_Linked_List(&(p->list));

	// ջ����ЧԪ�ظ��� ����
	p->count = 0;
}



// 7.��ӡ
void print_Stack(const Stack stack) {

	// �п�
	if (judge_empty(stack))
	{
		printf(" ��ǰջΪ�գ�û�п��Դ�ӡ��Ԫ��\n");

		return;
	}

	/*
		��ӡ��ʱ����Ҫ����ջ��ͼ�δ�ӡ���ȴ�ӡջ�Ķ���������ǵײ�

		���յ������ͷ��β���д�ӡ
	*/
	printf(" ��ջ����ʼ��\n");

	print_Single_Linked_List(stack.list);

	printf(" ��ջ�׽�����\n");
}


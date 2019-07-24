
#include "Stack_By_Double_Linked_List.h"


// 1.��ʼ��
void initStack(Stack* p) {

	// ָ���п�
	if (p == NULL)
	{
		printf("��ʼ�������β�Ϊ��\n");

		return;
	}

	// �ֶ�����ջ�ռ���Ҫ���������
	printf(" ������ջ�ռ���Ҫ���������������������");

	scanf(" %d", &(p->max));

	// ջʹ�õ���˫��������ʼ��ջ�����ǳ�ʼ���������� ˫����
	initDoubleLinkedList(&(p->list));

	// ջ����ЧԪ�صĸ��� ����
	p->count = 0;
}



// 2.�п� ���Ϊ�գ���Ϊ�棻����Ϊ��
int isEmpty(const Stack stack) {

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
int isFull(const Stack stack) {

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



// 4.ѹ��,p ��ʾ��Ҫ������ջ��˭�� num ��ʾ��Ҫѹ��ջ����ֵ�Ƕ���
void pushStack(Stack* p, const int num) {

	// ָ���п�
	if (p == NULL)
	{
		printf(" push_Stack �����β�Ϊ��\n");

		return;
	}

	// ����
	if (isFull(*p))
	{
		printf(" ��ǰջΪ�����޷������µ�Ԫ��\n");

		return;
	}

	// ��ջ������һ��ֵ
	// �൱���ڵ������ͷ����һ���½��
	insertPositionDoubleLinkedList(&(p->list), 1, num);

	// ��ЧԪ�صĸ��� +1
	p->count++;
}



// 5.����
int popStack(Stack* p) {

	// ָ���п�
	if (p == NULL)
	{
		printf(" pop_Stack �����β�Ϊ��\n");

		return -1;
	}

	// �п�
	if (isEmpty(*p))
	{
		printf(" ��ǰջΪ�գ�û�п��Ե�����Ԫ��\n");

		return -2;
	}

	// ����Ҫ��������ֵ�ȱ�������
	int res = p->list.head.next->data;

	// ����ջ��Ԫ��
	// �൱�� ɾ�� ������ĵ�һ����Ч���
	deletePositionDoubleLinkedList(&(p->list), 1);

	// ����һ�д���ȼ�����������
	//int res = deletePositionDoubleLinkedList(&(p->list), 1);

	// ջ�������ЧԪ�ظ��� -1
	p->count--;

	return res;
}



// 6.���
void clearStack(Stack* p) {

	// ָ���п�
	if (p == NULL)
	{
		printf(" ��պ����β�Ϊ��\n");

		return;
	}

	// �п�
	if (isEmpty(*p))
	{
		printf(" ��ǰջΪ�գ�û����յı�Ҫ\n");

		return;
	}

	//���һ��ջ��ʵ������Ҫ��յ�����
	clearDoubleLinkedList(&(p->list));

	// ջ����ЧԪ�ظ��� ����
	p->count = 0;
}



// 7.��ӡ
void printStack(const Stack stack) {

	// �п�
	if (isEmpty(stack))
	{
		printf(" ��ǰջΪ�գ�û�п��Դ�ӡ��Ԫ��\n");

		return;
	}

	//��ӡ��ʱ����Ҫ����ջ��ͼ�δ�ӡ���ȴ�ӡջ�Ķ���������ǵײ�
	//���յ������ͷ��β���д�ӡ
	printDoubleLinkedList(stack.list);
}
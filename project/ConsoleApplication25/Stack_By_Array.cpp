
#include "Stack_By_Array.h"


// 1.��ʼ��
void initStack(Stack* p) {

	// ָ���п�
	if (p == NULL)
	{
		//printf("��ʼ�������β�Ϊ��\n");
		return;
	}

	// �ֶ�����ջ�ռ���Ҫ���������
	printf(" ������ջ�ռ���Ҫ���������������������");

	scanf(" %d", &(p->max));

	// ջʹ�õ������飬����ʼ��ջ�����ǳ�ʼ���������� ����
	initArrayList(&(p->list));

	// ջ����ЧԪ�صĸ��� ����
	p->count = 0;
}



// 2.�п� ���Ϊ�գ���Ϊ�棻����Ϊ��
int isEmpty(const Stack stack) {

	if (stack.count == 0)
	{
		//printf(" ջ Ϊ��\n");
		return 1;
	}
	else
	{
		//printf(" ջ ��Ϊ��\n");
		return 0;
	}
}



// 3.���� ���Ϊ������Ϊ�棻����Ϊ��
int isFull(const Stack stack) {

	if (stack.count == stack.max)
	{
		//printf(" ջ Ϊ��\n");
		return 1;
	}
	else
	{
		//printf(" ջ ��Ϊ��\n");
		return 0;
	}
}



// 4.ѹ��,p ��ʾ��Ҫ������ջ��˭�� num ��ʾ��Ҫѹ��ջ����ֵ�Ƕ���
void pushStack(Stack* p, const Element num) {

	// ָ���п�
	if (p == NULL)
	{
		//printf(" push_Stack �����β�Ϊ��\n");
		return;
	}

	// ����
	if (isFull(*p))
	{
		printf(" ջ�������޷������µ�Ԫ��\n");
		return;
	}

	// ��ջ������һ��ֵ
	// �൱������ЧԪ��ĩβ����һ��Ԫ��
	insertArrayList(&(p->list), p->count+1, num);

	// ��ЧԪ�صĸ��� +1
	p->count++;
}



// 5.����
Element popStack(Stack* p) {

	// ָ���п�
	if (p == NULL)
	{
		//printf(" pop_Stack �����β�Ϊ��\n");

		return NULL;
	}

	// �п�
	if (isEmpty(*p))
	{
		printf(" ջΪ�գ�û�п��Գ�ջ��Ԫ��\n");

		return NULL;
	}

	// ����Ҫ��������ֵ�ȱ�������
	int res = p->list.arr[0];

	// ����ջ��Ԫ��
	// �൱�� ɾ�� ����ĵ�һ��Ԫ��
	getArrayList(&(p->list), 1);

	// ����һ�д���ȼ�����������
	//int res = getArrayList(&(p->list), 1);

	// ջ�������ЧԪ�ظ��� -1
	p->count--;

	return res;
}



// 6.���
void clearStack(Stack* p) {

	// ָ���п�
	if (p == NULL)
	{
		//printf(" ��պ����β�Ϊ��\n");

		return;
	}

	// �п�
	if (isEmpty(*p))
	{
		//printf(" ��ǰջΪ�գ�û����յı�Ҫ\n");

		return;
	}

	//���һ��ջ��ʵ������Ҫ��յ�����
	clearArrayList(&(p->list));

	// ջ����ЧԪ�ظ��� ����
	p->count = 0;
}



// 7.��ӡ
void printStack(const Stack stack) {

	// �п�
	if (isEmpty(stack))
	{
		printf(" ջΪ�գ�û�п��Դ�ӡ��Ԫ��\n");

		return;
	}

	//��ӡ��ʱ����Ҫ����ջ��ͼ�δ�ӡ���ȴ�ӡջ�Ķ���������ǵײ�
	//���յ������ͷ��β���д�ӡ
	printArrayList(stack.list);
}
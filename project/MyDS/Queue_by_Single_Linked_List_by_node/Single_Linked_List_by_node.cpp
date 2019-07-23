
#include "Single_Linked_List_by_node.h"



// 1.��ʼ��
void  init_Single_Linked_List(SL_List* p) {

	// ָ���п�
	if (p == NULL)
	{
		printf(" initt_Single_Linked_List �����β�Ϊ��\n");

		return;
	}

	// �������µ��ڴ�ռ�� data_pointer ֮ǰ����Ҫ�Ƚ���ָ��ľɿռ��ͷŵ�
	/*
		ע�⣺

			1.�����ͷ�ͬһ���ռ�����
			2.�����ͷ� NULL
	*/
	// ��ʱָ������������ͷŽ��ռ�
	Node* temp = p->head.next_pointer;

	// ѭ������������������һ�ͷ�ÿ�����
	while (p->head.next_pointer != NULL)
	{
		// ��ͷ���� next ָ���һ��������һ����㣨�ڶ�����
		p->head.next_pointer = p->head.next_pointer->next_pointer;
		//p->head.next_pointer = temp->next_pointer;

		// �ͷ� temp ��ָ��Ľ�㣬ԭ������ĵ�һ�����
		free(temp);

		// �� temp �ٴ�ָ����һ����Ҫ�ͷŵĽ��
		// �ֵ������һ����㣬ԭ������ڶ������
		temp = p->head.next_pointer;
	}

	// ��ЧԪ�صĸ��� ����
	p->count = 0;

	// ͷ���� next ָ�� �ÿ�
	p->head.next_pointer = NULL;

	// ͷ��� ����  ��ŵ�����ֵ����Ҫ����һ�£���ѡ��
	//p->head.data = 0;
}



// 2.�п� ���Ϊ�գ���Ϊ�棻����Ϊ��
int judge_empty_Single_Linked_List(const SL_List list) {

	if (list.count == 0)
	{
		printf(" ������ Ϊ��\n");

		return 1;
	}
	else
	{
		printf(" ������ ��Ϊ��\n");

		return 0;
	}
}



// 3.����
// p ��ʾ��Ҫ�����ĵ�������˭�� position ��ʾ�����λ�ã� num ��ʾ��Ҫ��������λ�õ���ֵ�Ƕ���
void insert_position_Single_Linked_List(SL_List* p, const int position, const int num) {

	// ָ���п�
	if (p == NULL)
	{
		printf(" insert_position_Single_Linked_List �����β�Ϊ��\n");

		return;
	}

	// �жϲ����λ���Ƿ��ڵ�����ĳ��ȷ�Χ��
	//if ( position < p->count + 2 && position > 0 )
	if (position > p->count + 1 || position < 1)
	{
		printf(" �����λ�ã����ڵ�����ĳ��ȷ�Χ��\n");

		return;
	}

	// ����ʱָ����� index ȥ��λ������Ҫ�����λ�õ�ǰһ������λ�ã���ַ��
	/*
		�����Ҫ����Ľ���ǵ�һ����㣬��ô����֪��ͷ����λ�ã���ַ��

		������� index ��ʼ��λ�þ���ͷ���ĵ�ַ
	*/
	Node* index = &(p->head);

	int i = 0;

	while (i < position - 1)
	{
		index = index->next_pointer;

		i++;
	}

	// ��ʼ��̬����ռ䣬�����µĽ��
	Node* node = (Node*)malloc(sizeof(Node));

	// node ��ֵ
	node->data = num;

	node->next_pointer = index->next_pointer;

	// �������λ�õ�ǰһ����� �� next ָ�� ָ�� �µĽ��
	index->next_pointer = node;

	// ��Ч���Ԫ�صĸ��� +1
	p->count++;
}


// 4.ɾ��
int delete_position_Single_Linked_List(SL_List* p, const int position) {

	// ָ���п�
	if (p == NULL)
	{
		printf(" delete_position_Single_Linked_List �����β�Ϊ��\n");

		return -1;
	}

	// �п�
	if (judge_empty_Single_Linked_List(*p))
	{
		printf(" ������Ϊ�գ�û�п���ɾ���Ľ��Ԫ��\n");

		return -2;
	}

	// �ж�ɾ����λ���Ƿ��ڵ�����ĳ��ȷ�Χ��
	//if ( position < p->count + 1 && position > 0 )
	if (position > p->count || position < 1)
	{
		printf(" ɾ����λ�ã����ڵ�����ĳ��ȷ�Χ��\n");

		return -3;
	}

	// ������Ҫ���ص�ֵ
	int res = 0;

	// ����ʱָ����� index ȥ��λ������Ҫɾ����λ�õ�ǰһ������λ�ã���ַ��
	/*
		�����Ҫɾ���Ľ���ǵ�һ����㣬��ô����֪��ͷ����λ�ã���ַ��

		������� index ��ʼ��λ�þ���ͷ���ĵ�ַ
	*/
	Node* index = &(p->head);

	int i = 0;

	while (i < position - 1)
	{
		index = index->next_pointer;

		i++;
	}

	// ����ʱָ����� temp ������Ҫ�ͷŵĽ��ռ�
	Node* temp = index->next_pointer;

	/*
		����Ҫɾ����λ���ϵĽ���ǰһ����� �� nextָ��
		ָ��
		��Ҫɾ����λ���ϵĽ��ĺ�һ����㣨��ַ��
	*/
	index->next_pointer = index->next_pointer->next_pointer;
	//index->next_pointer = temp->next_pointer;

	res = temp->data;

	// �ͷ� temp ָ��Ľ��ռ�
	free(temp);

	temp = NULL;

	// ��Ч���ĸ��� -1
	p->count--;

	return res;
}


// 5.��ѯ
// ��λ�ò�ѯ���汣�����ֵ
int lookup_position_Single_Linked_List(const SL_List list, const int position) {

	// �п�
	if (judge_empty_Single_Linked_List(list))
	{
		printf(" ������Ϊ�գ�û�в�ѯ�ı�Ҫ\n");

		return -1;
	}

	// �жϲ�ѯ��λ���Ƿ��ڵ�����ĳ��ȷ�Χ��
	//if ( position < list.count + 1 && position > 0 )
	if (position > list.count || position < 1)
	{
		printf(" ��ѯ��λ�ã����ڵ�����ĳ��ȷ�Χ��\n");

		return -2;
	}

	// ����ʱָ����� index ������������ж�λ
	// index �ȶ�λ��ͷ���ĵ�ַ��
	Node* index = (Node*) & (list.head);

	int i = 0;

	while (i < position)
	{
		index = index->next_pointer;

		i++;
	}

	return index->data;
}


// ����ֵ��ѯ���Ϊλ��
int lookup_value_Single_Linked_List(const SL_List list, const int value) {

	// �п�
	if (judge_empty_Single_Linked_List(list))
	{
		printf(" ������Ϊ�գ�û�в�ѯ�ı�Ҫ\n");

		return -1;
	}

	// ����ʱָ����� index ������������ж�λ
	// index �ȶ�λ��ͷ���ĵ�ַ��
	Node* index = (Node*) & (list.head.next_pointer);

	// ��������
	int i = 1;

	while (index != NULL)
	{
		if (index->data == value)
		{
			return i;
		}

		index = index->next_pointer;

		i++;
	}

	printf(" ��ѯ����ֵ�����ڵ�����ĳ��ȷ�Χ��\n");

	return -2;
}


// ��λ�ò�ѯ���ĵ�ַ
// ����ֵ��ѯ���ĵ�ַ



// 6.���
void clear_Single_Linked_List(SL_List* p) {

	// ָ���п�
	if (p == NULL)
	{
		printf(" clear_Single_Linked_List �����β�Ϊ��\n");

		return;
	}

	// �п�
	if (judge_empty_Single_Linked_List(*p))
	{
		printf(" ������Ϊ�գ�û����յı�Ҫ\n");

		return;
	}

	// ��ʱָ������������ͷŽ��ռ�
	Node* temp = p->head.next_pointer;

	// ѭ������������������һ�ͷ�ÿ�����
	while (p->head.next_pointer != NULL)
	{
		// ��ͷ���� next ָ���һ��������һ����㣨�ڶ�����
		p->head.next_pointer = p->head.next_pointer->next_pointer;
		//p->head.next_pointer = temp->next_pointer;

		// �ͷ� temp ��ָ��Ľ�㣬ԭ������ĵ�һ�����
		free(temp);

		// �� temp �ٴ�ָ����һ����Ҫ�ͷŵĽ��
		// �ֵ������һ����㣬ԭ������ڶ������
		temp = p->head.next_pointer;
	}

	// ��ЧԪ�صĸ��� ����
	p->count = 0;
}



// 7.��ӡ
void print_Single_Linked_List(const SL_List list) {

	// �п�
	if (judge_empty_Single_Linked_List(list))
	{
		printf(" ������Ϊ�գ�û�п��Դ�ӡ�Ľ��Ԫ��\n");

		return;
	}

	// ����ʱ��������������������
	Node* temp = list.head.next_pointer;

	printf(" �ӵ�����ͷ��ʼ��\n");

	while (temp != NULL)
	{
		printf(" %d\n", temp->data);

		temp = temp->next_pointer;
	}

	printf(" ��������β������\n");
}
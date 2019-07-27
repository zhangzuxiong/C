
#include "Single_Linked_List.h"



// 1.��ʼ��
void  init_Single_Linked_List( SL_List* p ) {

	// ָ���п�
	if ( p == NULL )
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
	Node* temp = p->head;

	// ѭ������������������һ�ͷ�ÿ�����
	while ( p->head != NULL )
	{
		// �� ͷָ�� ָ���һ��������һ����㣨�ڶ�����
		p->head = p->head->next_pointer;
		//p->head = temp->next_pointer;

		// �ͷ� temp ��ָ��Ľ�㣬ԭ������ĵ�һ�����
		free(temp);

		// �� temp �ٴ�ָ����һ����Ҫ�ͷŵĽ��
		// �ֵ������һ����㣬ԭ������ڶ������
		temp = p->head;
	}

	// ��ЧԪ�صĸ��� ����
	p->count = 0;

	// ͷָ�� �ÿ� ����ѡ����Ϊǰ���whileѭ���Ѿ��� head �ÿգ�
	//p->head = NULL;

	// ͷ��� ����  ��ŵ�����ֵ����Ҫ����һ�£���ѡ��
	//p->head.data = 0;
}



// 2.�п� ���Ϊ�գ���Ϊ�棻����Ϊ��
int judge_empty_Single_Linked_List( const SL_List list ) {

	if ( list.count == 0 )
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
void insert_position_Single_Linked_List( SL_List* p, const int position, const int num ) {

	// ָ���п�
	if ( p == NULL )
	{
		printf(" insert_position_Single_Linked_List �����β�Ϊ��\n");

		return;
	}

	// �жϲ����λ���Ƿ��ڵ�����ĳ��ȷ�Χ��
	//if ( position < p->count + 2 && position > 0 )
	if ( position > p->count + 1 || position < 1 )
	{
		printf(" �����λ�ã����ڵ�����ĳ��ȷ�Χ��\n");

		return;
	}

	/*
		�����֮ǰ��ͷ���ķ�ʽ����ʾ����

		ͷָ���ڲ����һ������ʱ����֮������λ�ò�����Ĳ�����Щ��ͬ

		��Ҫ���⴦��

		���������Ƿ�Ϊ�գ�ֻҪ�����λ�� �� ��һ��λ�ã�����Ҫ��������

		��������λ�ò��ǵ�һ����㣬����Ҫ�ȶ�λ

		index ��λ������λ�õ�ǰһ�������
	*/
	if ( position == 1 )
	{
		// �����½��
		Node* node = (Node*)malloc(sizeof(Node));

		// head ָ���ĸ��ط��� node->next ��ָ����
		node->next_pointer = p->head;

		// ��ֵ
		node->data = num;

		// ��ͷָ�� ָ�� �½�㣬���ǵ������ �µ� ��һ����Ч���
		p->head = node;
	}
	else
	{
		// ��Ҫһ����ʱָ���������λ
		Node* index = p->head;

		int i = 0;

		/*
			index ��ͣ���� ��һ����Ч����ϣ������Ҫ���뵽������λ����

			index ��Ҫ��λ���ڶ���������ڵ�λ����

			��ô index �ӵ�һ����Ч������ڵ�λ�����ƶ�һ��

			position = 3 -------- index Ų�� 1��
		*/
		while (i < position - 2)
		{
			// ��λ ��ָ����������Ų��һ�����
			index = index->next_pointer;

			// Ų�������Ŀ���
			i++;
		}

		// ��λ֮�󣬴����µĽ��
		Node* node = (Node*)malloc(sizeof(Node));

		// ������λ�õĽ��ĵ�ַ����ֵ���½��� next ָ��
		node->next_pointer = index->next_pointer;

		// ��ֵ
		node->data = num;

		// ������λ��֮ǰ�Ľ��� next ָ��ָ�� �½��
		index->next_pointer = node;
	}

	// ��Ч���Ԫ�صĸ��� +1
	p->count++;
}



// 4.ɾ��
int delete_position_Single_Linked_List( SL_List* p, const int position ) {

	// ָ���п�
	if ( p == NULL )
	{
		printf(" delete_position_Single_Linked_List �����β�Ϊ��\n");

		return -1;
	}

	// �п�
	if ( judge_empty_Single_Linked_List(*p) )
	{
		printf(" ������Ϊ�գ�û�п���ɾ���Ľ��Ԫ��\n");

		return -2;
	}

	// �ж�ɾ����λ���Ƿ��ڵ�����ĳ��ȷ�Χ��
	//if ( position < p->count + 1 && position > 0 )
	if ( position > p->count || position < 1 )
	{
		printf(" ɾ����λ�ã����ڵ�����ĳ��ȷ�Χ��\n");

		return -3;
	}

	// ����ʱ����������Ҫ���ص���ֵ
	int res = 0;

	/*
		�����֮ǰʹ��ͷ���

		ʹ��ͷָ����ɾ������λ��ʱ������ϸ���ϵĲ���

		��Ҫ������ɾ����һ�����Ĳ�����
	*/
	// �ж�ɾ���Ľ���ǲ��ǵ�һ��������ǲ�����Ҫ��������
	if ( position == 1 )
	{
		// ����ʱָ�������¼��Ҫ�ͷŵĽ��Ŀռ��ַ
		Node* temp = p->head;

		// ��ͷָ�� Ų��ԭ������ĵڶ�������ϣ�Ҳ�����Ų����һ�������
		p->head = p->head->next_pointer;
		//p->head = temp->next_pointer;

		res = temp->data;

		// �ͷ�ԭ�������һ�����Ŀռ�
		free(temp);

		temp = NULL;
	}
	else
	{
		// �ȶ�λ����Ҫɾ����λ�õ�ǰһ�������
		Node* index = p->head;

		int i = 0;

		// ѭ��������
		while ( i < position - 2 )
		{
			// ��λ��ָ���������һ�����Ų��
			index = index->next_pointer;

			// Ų�������Ŀ���
			i++;
		}

		// ������ʱָ�������¼��Ҫɾ���Ľ��Ŀռ�ĵ�ַ
		Node* temp = index->next_pointer;

		/*
			��λ�Ľ�㣨��Ҫɾ���Ľ���ǰһ����㣩 �� next
			ָ��
			��Ҫɾ���Ľ��ĺ�һ�����Ŀռ�ĵ�ַ
		*/
		index->next_pointer = index->next_pointer->next_pointer;
		//index->next_pointer = temp->next_pointer;

		res = temp->data;

		// �ͷ���Ҫɾ���Ľ��Ŀռ�
		free(temp);

		temp = NULL;
	}

	// ��Ч���ĸ��� -1
	p->count--;

	return res;
}



// 5.��ѯ
// ��λ�ò�ѯ���汣�����ֵ
int lookup_position_Single_Linked_List( const SL_List list, const int position ) {

	// �п�
	if ( judge_empty_Single_Linked_List(list) )
	{
		printf(" ������Ϊ�գ�û�в�ѯ�ı�Ҫ\n");

		return -1;
	}

	// �жϲ�ѯ��λ���Ƿ��ڵ�����ĳ��ȷ�Χ��
	//if ( position < list.count + 1 && position > 0 )
	if ( position > list.count || position < 1 )
	{
		printf(" ��ѯ��λ�ã����ڵ�����ĳ��ȷ�Χ��\n");

		return -2;
	}

	// ����ʱָ����� index ������������ж�λ
	// index �ȶ�λ��ͷָ��ָ��ĵ�һ�����ĵ�ַ��
	Node* index = list.head;

	int i = 1;

	while ( i < position )
	{
		index = index->next_pointer;

		i++;
	}

	return index->data;
}


// ����ֵ��ѯ���Ϊλ��
int lookup_value_Single_Linked_List( const SL_List list, const int value ) {

	// �п�
	if ( judge_empty_Single_Linked_List(list) )
	{
		printf(" ������Ϊ�գ�û�в�ѯ�ı�Ҫ\n");

		return -1;
	}

	// ����ʱָ����� index ������������ж�λ
	// index �ȶ�λ��ͷ���ĵ�ַ��
	Node* index = list.head;

	// ��������
	int i = 1;

	while ( index != NULL )
	{
		if ( index->data == value )
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
Node* lookup_position_return_address_Single_Linked_List( const SL_List list, const int position ) {

	// �п�
	if ( judge_empty_Single_Linked_List(list) )
	{
		printf(" ������Ϊ�գ�û�в�ѯ�ı�Ҫ\n");

		return NULL;
	}

	// �жϲ�ѯ��λ���Ƿ��ڵ�����ĳ��ȷ�Χ��
	//if ( position < list.count + 1 && position > 0 )
	if ( position > list.count || position < 1 )
	{
		printf(" ��ѯ��λ�ã����ڵ�����ĳ��ȷ�Χ��\n");

		return NULL;
	}

	// ����ʱָ����� index ������������ж�λ
	// index �ȶ�λ��ͷָ��ָ��ĵ�һ�����ĵ�ַ��
	Node* index = list.head;

	int i = 1;

	while ( i < position )
	{
		index = index->next_pointer;

		i++;
	}

	return index;
}


// ����ֵ��ѯ���ĵ�ַ
Node* lookup_value_return_address_Single_Linked_List( const SL_List list, const int value ) {

	// �п�
	if ( judge_empty_Single_Linked_List(list) )
	{
		printf(" ������Ϊ�գ�û�в�ѯ�ı�Ҫ\n");

		return NULL;
	}

	// ����ʱָ����� index ������������ж�λ
	// index �ȶ�λ��ͷָ����ָ��ĵ�һ�����ĵ�ַ��
	Node* index = list.head;

	// ��������
	//int i = 1;

	while ( index != NULL )
	{
		if ( index->data == value )
		{
			return index;
		}

		index = index->next_pointer;

		//i++;
	}

	printf(" ��ѯ����ֵ�����ڵ�����ĳ��ȷ�Χ��\n");

	return NULL;
}



// 6.���
void clear_Single_Linked_List( SL_List* p ) {

	// ָ���п�
	if ( p == NULL )
	{
		printf(" clear_Single_Linked_List �����β�Ϊ��\n");

		return;
	}

	// �п�
	if ( judge_empty_Single_Linked_List(*p) )
	{
		printf(" ������Ϊ�գ�û����յı�Ҫ\n");

		return;
	}

	// ��ʱָ������������ͷŽ��ռ�
	Node* temp = p->head;

	// ѭ������������������һ�ͷ�ÿ�����
	while ( p->head != NULL )
	{
		// ��ͷָ��ָ���һ��������һ����㣨�ڶ�����
		p->head = p->head->next_pointer;
		//p->head = temp->next_pointer;

		// �ͷ� temp ��ָ��Ľ�㣬ԭ������ĵ�һ�����
		free(temp);

		// �� temp �ٴ�ָ����һ����Ҫ�ͷŵĽ��
		// �ֵ������һ����㣬ԭ������ڶ������
		temp = p->head;
	}

	// ��ЧԪ�صĸ��� ����
	p->count = 0;
}



// 7.��ӡ
void print_Single_Linked_List( const SL_List list ) {

	// �п�
	if ( judge_empty_Single_Linked_List(list) )
	{
		printf(" ������Ϊ�գ�û�п��Դ�ӡ�Ľ��Ԫ��\n");

		return;
	}

	// ����ʱ��������������������
	Node* temp = list.head;

	printf(" �ӵ�����ͷ��ʼ��\n");

	while ( temp != NULL )
	{
		// ��ӡ��ָ��������ŵ�ֵ
		printf(" %d\n", temp->data);

		// ��ӡ���֮�� temp Ų�� ��һ����㴦
		temp = temp->next_pointer;
	}

	printf(" ��������β������\n");
}


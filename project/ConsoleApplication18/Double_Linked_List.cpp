
#include "Double_Linked_List.h"


//��ʼ��
void initDoubleLinkedList(DL_List* p) {
	//ָ���п�
	if (p == NULL)
	{
		printf("��ʼ������Ϊ��\n");
		return;
	}

	//����Ѿ��ǿգ�ֻҪ��ͷβ����
	if (p->head.next == NULL)
	{
		p->head.next = &(p->tail);
		p->tail.pre = &(p->head);

		return;
	}

	//��ʱָ����������ͷ�˫������֮ǰ���ڵĿռ�
	Node* temp = p->head.next;
	while (p->head.next->next != NULL)
	{
		//��ͷ�����ƶ�һ��
		p->head.next = temp->next;

		//�ͷſռ�
		free(temp);

		//ָ����һ���ͷŵĿռ�
		temp = p->head.next;
	}

	//β�ڵ��ͷ�ڵ�����
	p->head.pre = NULL;
	p->head.data = 0;
	p->tail.next = NULL;
	p->tail.pre = &(p->head);
	p->tail.data = 0;

	//��ЧԪ����λ0
	p->count = 0;

}


//�п�
bool judgeEmpotyDoubleLinkedList(const DL_List list) {
	if (list.count == 0)
	{
		printf("˫����Ϊ��\n");
		return true;
	}
	else
	{
		printf("˫����Ϊ��\n");
		return false;
	}
}


//���룬�ڵ�position��λ�ò���һ����num
int insertPositionDoubleLinkedList(DL_List* p, const const int position, const int num) {
	if (p == NULL)
	{
		printf("����˫����Ĳ���Ϊ��\n");
		return 0;
	}

	if (position < 1 || position > p->count + 1)
	{
		printf("����λ�ò�����\n");
		return 0;
	}

	//�²���Ľڵ�
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = num;

	int i = 0;

	Node* index = &(p->head);

	while (i < position)
	{
		index = index->next;

		i++;
	}

	// �� �½��� next ָ�� ��λ�Ľ��
	node->next = index;

	// �� �½��� pre ָ�� ��λ�Ľ���ǰһ�����
	node->pre = index->pre;

	// �� ��λ����ǰһ������ next ָ�� �½��
	index->pre->next = node;

	// �� ��λ���� pre ָ�� �½��
	index->pre = node;

	//��ЧԪ�ؼ�1
	p->count++;

	return 1;
}


//ɾ��--����λ��ɾ��
int deletePositionDoubleLinkedList(DL_List* p, const int position) {
	if (p == NULL)
	{
		printf("ɾ������Ϊ��\n");
		return 0;
	}

	if (judgeEmpotyDoubleLinkedList(*p))
	{
		printf("˫������Ϊ��,�޷�ɾ��\n");
		return 0;
	}

	if (position < 1 || position > p->count)
	{
		printf("ɾ����λ�ò�����\n");
		return 0;
	}

	//��¼ɾ����λ��
	Node* index = p->head.next;

	//����ɾ��������
	int res = 0;

	int i = 1;
	while (i < position)
	{
		index = index->next;
		i++;
	}

	//ǰһ���ڵ��nextָ���һ���ڵ�
	index->pre->next = index->next;

	//��һ���ڵ��preָ��ǰһ���ڵ�
	index->next->pre = index->pre;

	// ������Ҫ���ص���ֵ
	res = index->data;

	// �ͷ� index
	free(index);

	//��ЧԪ�ؼ�1
	p->count--;
	printf("ɾ���ɹ�\n");
	return res;
}


//����--����ֵ���ң�����ֵ��λ��
int searchValueDoubleLinkedList(const DL_List list, const int num) {
	if (judgeEmpotyDoubleLinkedList(list))
	{
		printf("˫�����Ѿ�Ϊ�գ����ܲ���\n");
		return 0;
	}

	//��ʱ����������˫�������
	Node* temp = list.head.next;

	int i = 1;

	while (temp->next != NULL)
	{
		//�ҵ��˷��أ����Ԫ����˫����ĵڼ���
		if (temp->data == num)
		{
			return i;
		}

		i++;
		temp = temp->next;
	}

	return 0;
}

//����--����λ�ò��ң��������λ�õ�ֵ
int searchPositionDoubleLinkedList(const DL_List list, const int position) {
	if (judgeEmpotyDoubleLinkedList(list))
	{
		printf("˫������Ϊ��,�޷�����\n");
		return 0;
	}

	if (position < 1 || position > list.count)
	{
		printf("���ҵ�λ�ò�����\n");
		return 0;
	}

	//��ʱ������ѭ������˫����
	Node* temp = list.head.next;
	int i = 1;
	while (i < position)
	{
		temp = temp->next;
		i++;
	}

	return temp->data;
}

//����--����λ�ò������λ�õĵ�ַ
Node* searchPositionReturnAddressSingleLinkedList(const DL_List list, const int position) {
	if (judgeEmpotyDoubleLinkedList(list))
	{
		printf("˫�����Ѿ�Ϊ�գ����ܲ���\n");
		return NULL;
	}

	if (position < 1 || position > list.count)
	{
		printf("���ҵ�λ�ò�����\n");
		return NULL;
	}

	//��ʱ������ѭ������˫����
	Node* temp = list.head.next;
	int i = 1;
	while (i < position)
	{
		temp = temp->next;
		i++;
	}

	return temp;
}


//����--����ֵ��ѯ���ز��ҵĵ�ַ
Node* searchValueReturnAddressSingleLinkedList(const DL_List list, const int value) {
	if (judgeEmpotyDoubleLinkedList(list))
	{
		printf("˫�����Ѿ�Ϊ�գ����ܲ���\n");
		return NULL;
	}

	//��ʱָ����������ҵ��ĵ�ַ
	Node* temp = list.head.next;

	while (temp->next != NULL)
	{
		if (temp->data == value)
		{
			return temp;
		}
		//ָ����һ�����ҵ�λ��
		temp = temp->next;
	}

	return NULL;
}

//���
void clearDoubleLinkedList(DL_List* p) {
	if (p == NULL)
	{
		printf("���˫����Ĳ���Ϊ��\n");
		return;
	}
	if (judgeEmpotyDoubleLinkedList(*p))
	{
		printf("˫�����Ѿ�Ϊ�գ����������\n");
		return;
	}

	while (p->head.next->next != NULL)
	{
		// ��һ����ʱָ�����������Ҫ�ͷŵĵ�ǰ�����ڴ�ռ�ĵ�ַ
		Node* temp = p->head.next;

		// �� ͷ��� ��� Ųһ�� ָ�� ԭ˫����ĵڶ������
		p->head.next = p->head.next->next;

		// �ͷ� ԭ˫����ĵ�һ����㣬����tempָ��Ľ��
		free(temp);

		temp = NULL;
	}

	// ��βָ����ǰ ָ��ͷ���
	p->tail.pre = &(p->head);

	//��ЧԪ����Ϊ0
	p->count = 0;
}


//��ӡ
void printDoubleLinkedList(const DL_List list) {
	if (judgeEmpotyDoubleLinkedList(list))
	{
		printf("˫����Ϊ�գ�û�п��Դ�ӡ��Ԫ��\n");
		return;
	}

	//��ʱ�����������洢��ӡ�ڵ�
	Node* temp = list.head.next;

	while (temp->next != NULL)
	{
		printf("%d  ", temp->data);

		//ָ����һ����ӡ�Ľڵ�Ԫ��
		temp = temp->next;
	}
	printf("\n");
}

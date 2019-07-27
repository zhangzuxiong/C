

#include "Order_Have_Goods.h"


//��ʼ��
void initOrderHavaGoods(OrderHaveGoodsList* p) {
	//ָ���п�
	if (p == NULL)
	{
		printf("��ʼ������Ϊ��\n");
		return;
	}

	//��ʱָ����������ͷ�˫������֮ǰ���ڵĿռ�
	OrderHaveGoods* temp = p->head;
	while (p->head != NULL)
	{
		//��ͷ�����ƶ�һ��
		p->head = temp->next;

		//�ͷſռ�
		free(temp);

		//ָ����һ���ͷŵĿռ�
		temp = p->head;
	}

	//βָ����λNULL
	p->tail = NULL;

	//��ЧԪ����λ0
	p->count = 0;

}


//�п�
bool judge_Empoty_Double_Linked_List(const OrderHaveGoodsList list) {
	if (list.count == 0)
	{
		//printf("˫����Ϊ��\n");
		return true;
	}
	else
	{
		//printf("˫����Ϊ��\n");
		return false;
	}
}


//���룬�ڵ�position��λ�ò���
int insertPositionOrderHavaGoods(OrderHaveGoodsList* p, const const int position, const int goodsId, const int count) {
	if (p == NULL)
	{
		//printf("����˫����Ĳ���Ϊ��\n");
		return 0;
	}

	if (position < 1 || position > p->count + 1)
	{
		printf("����λ�ò�����\n");
		return 0;
	}

	//�²���Ľڵ�
	OrderHaveGoods* node = (OrderHaveGoods*)malloc(sizeof(OrderHaveGoods));
	node->goodsId = goodsId;
	node->count = count;

	//����Ϊ��
	if (p->count == 0)
	{
		//�½ڵ����ͷ���Ҳ��β���
		p->head = node;
		p->tail = node;

		//ͷ������һ����β����ǰһ����ΪNULL
		p->head->next = NULL;
		p->tail->pre = NULL;
	}
	//����ǿգ���ͷ��β����
	else if (p->count != 0 && (position == 1 || position == p->count + 1))
	{
		//��ͷ����
		if (position == 1)
		{
			//�½ڵ����һ���ڵ�Ϊͷ���
			node->next = p->head;

			//�½ڵ��ǰһ���ڵ���ͷ����ǰһ���ڵ㣨NULL��
			node->pre = p->head->pre;

			//ͷ�ڵ��ǰһ���ڵ����½ڵ�
			p->head->pre = node;

			//���½ڵ�����Ϊ�µ�ͷ���
			p->head = node;
		}
		//��β����
		else
		{
			//�½ڵ����һ���ڵ�Ϊβ������һ���ڵ㣨NULL��
			node->next = p->tail->next;

			//�½ڵ��ǰһ���ڵ���β���
			node->pre = p->tail;

			//β������һ���ڵ����½ڵ�
			p->tail->next = node;

			//���½ڵ�����Ϊ�µ�β���
			p->tail = node;
		}
	}
	//���м����
	else
	{
		//��¼�����λ��
		OrderHaveGoods* index = p->head;

		//ѭ�����������ҵ������λ��
		int i = 1;
		while (i < position)
		{
			index = index->next;
			i++;
		}
		//�ȸı�next����Ϊ2��
		//1.�½ڵ����һ��ָ��index��λ��
		node->next = index;

		//2.����λ�õ�ǰһ��ָ���½ڵ�
		index->pre->next = node;


		//�ٸı�pre,��Ϊ2��
		//1.�½ڵ��ǰһ��ָ�����ڵ��ǰһ��
		node->pre = index->pre;

		//2.����λ�õ�ǰһ��ָ���½ڵ�
		index->pre = node;
	}

	//��ЧԪ�ؼ�1
	p->count++;

	return 1;
}


//ɾ��--����λ��ɾ��
int deletePositionOrderHavaGoods(OrderHaveGoodsList* p, const int position) {
	if (p == NULL)
	{
		printf("ɾ������Ϊ��\n");
		return 0;
	}

	if (judge_Empoty_Double_Linked_List(*p))
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
	OrderHaveGoods* index = p->head;

	//����ɾ��������
	int res = 1;

	//˫����ֻ��һ��Ԫ�أ�ֱ���ͷ�ͷ��ͷβ��NULL
	if (p->count == 1)
	{

		//�ͷſռ�
		free(p->head);
		p->head = NULL;
		p->tail = NULL;
	}
	//ɾ��֮�󲻿գ�����ɾ����λ���ڵ�һ��
	else if (position == 1 && p->count > 1)
	{

		//��head����ƶ�һ��
		p->head = index->next;

		free(index);

		index = NULL;

		//�½ڵ��ǰһ���ڵ���λNULL
		p->head->pre = NULL;

		/*
		//ͷ��������ƶ�һ����Ϊ�µ�ͷ�ڵ�
		p->head = p->head->next;
		//�ͷžɵ�ͷ�ڵ�
		free(p->head->pre);
		//�µ�ͷ����preΪNULL
		p->head->pre = NULL;
		*/
	}
	//ɾ�����һ��������˫������ЧԪ�ش���1��
	else if (position == p->count && p->count > 1)
	{

		//��tail��ǰ�ƶ�һ��
		p->tail = p->tail->pre;

		//��ĩβ��ǰһ����next��λNULL��Ȼ���ͷ�ԭ�����ĩβ�ڵ�
		free(p->tail->next);
		p->tail->next = NULL;
	}
	//ɾ�����м�
	else
	{
		//ѭ�����������ҵ�ɾ����λ��
		int i = 1;
		while (i < position)
		{
			index = index->next;
			i++;
		}

		//��ǰɾ���ڵ��ǰһ���ڵ�nextָ��ɾ���ڵ��next
		index->pre->next = index->next;

		//��ǰɾ���ڵ�next��preָ��index��pre
		index->next->pre = index->pre;

		//�ͷſռ�
		free(index);
	}

	//��ЧԪ�ؼ�1
	p->count--;
	//ɾ���ɹ�
	return res;
}



//����--����ֵ��ѯ���ز��ҵĵ�ַ
OrderHaveGoods* searchOrderHavaGoodsByGoodsid(const OrderHaveGoodsList list, const int value) {
	if (judge_Empoty_Double_Linked_List(list))
	{
		printf("˫�����Ѿ�Ϊ�գ����ܲ���\n");
		return NULL;
	}

	//��ʱָ����������ҵ��ĵ�ַ
	OrderHaveGoods* temp = list.head;

	while (temp != NULL)
	{
		if (temp->goodsId == value)
		{
			return temp;
		}
		//ָ����һ�����ҵ�λ��
		temp = temp->next;
	}

	return NULL;
}

//���
void clearOrderHavaGoods(OrderHaveGoodsList* p) {
	if (p == NULL)
	{
		printf("���˫����Ĳ���Ϊ��\n");
		return;
	}
	if (judge_Empoty_Double_Linked_List(*p))
	{
		printf("˫�����Ѿ�Ϊ�գ����������\n");
		return;
	}

	while (p->head != NULL)
	{
		//��ʱ�����������ͷſռ�
		OrderHaveGoods* temp = p->head;

		//ͷָ�������ƶ�һ��
		p->head = temp->next;

		//�ͷſռ�
		free(temp);

		temp = NULL;

	}

	//βָ����ΪNULL
	p->tail = NULL;

	//��ЧԪ����Ϊ0
	p->count = 0;
}


//��ӡ
void printOrderHavaGoods(const OrderHaveGoodsList list) {
	if (judge_Empoty_Double_Linked_List(list))
	{
		printf("˫����Ϊ�գ�û�п��Դ�ӡ��Ԫ��\n");
		return;
	}

	//��ʱ�����������洢��ӡ�ڵ�
	OrderHaveGoods* temp = list.head;

	while (temp != NULL)
	{
		printf("��ƷID:%d��%d��\n", temp->goodsId, temp->count);

		//ָ����һ����ӡ�Ľڵ�Ԫ��
		temp = temp->next;
	}
	printf("\n");
}


//�������е�����Ʒ�ж��ϸ�����Ϣ���浽�ļ�
void saveOrderHavaGoodsData(const OrderHaveGoodsList list) {
	FILE* file = fopen("../Order/goodsandorder.txt", "w");
	if (!file)
	{
		printf("�ļ���ʧ��\n");
		return;
	}

	
	OrderHaveGoods* node = list.head;

	//ѭ������д���ļ�
	while (node != NULL)
	{
		fprintf(file, "%d\t\%d\n", node->goodsId, node->count);
		node = node->next;
	}

	printf("����ɹ�\n");

	//�ļ��ر�
	fclose(file);
}

//��ȡ�ļ��е�����Ʒ�ڶ����е�����
void getOrderHavaGoodsData(OrderHaveGoodsList* p) {
	FILE* file = fopen("../Order/goodsandorder.txt", "r");
	if (!file)
	{
		printf("�ļ���ʧ��\n");
		return;
	}

	OrderHaveGoods* temp = NULL;


	//���ļ����ݶ�ȡ����
	while (!feof(file))
	{

		temp = (OrderHaveGoods*)malloc(sizeof(OrderHaveGoods));

		fscanf(file, "%d\t\%d\n", &temp->goodsId, &temp->count);
		insertPositionOrderHavaGoods(p, 1, temp->goodsId, temp->count);

	}

	//�ر��ļ�
	fclose(file);
}




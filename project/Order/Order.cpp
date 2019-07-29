

#include "Order.h"


static int ORDERID = 1;

//��ʼ��
void initOrderList(OrderList* p) {
	//ָ���п�
	if (p == NULL)
	{
		printf("��ʼ������Ϊ��\n");
		return;
	}

	//��ʱָ����������ͷ�˫������֮ǰ���ڵĿռ�
	OrderNode* temp = p->head;
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
bool judgeEmpotyOrderList(const OrderList list) {
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


//���룬�ڵ�position��λ�ò���һ������
int insertPositionOrderList(OrderList* p, const const int position, const Order order) {
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
	OrderNode* node = (OrderNode*)malloc(sizeof(OrderNode));
	node->order = order;
	if (order.order_num < 1)
	{
		node->order.order_num = ORDERID;
	}

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
		OrderNode* index = p->head;

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
	if (order.order_num < 1)
	{
		ORDERID++;
	}

	//��ЧԪ�ؼ�1
	p->count++;

	return 1;
}


//ɾ��--����λ��ɾ��
Order* deletePositionOrderList(OrderList* p, const int position) {
	if (p == NULL)
	{
		printf("ɾ������Ϊ��\n");
		return NULL;
	}

	if (judgeEmpotyOrderList(*p))
	{
		printf("˫������Ϊ��,�޷�ɾ��\n");
		return NULL;
	}

	if (position < 1 || position > p->count)
	{
		printf("ɾ����λ�ò�����\n");
		return NULL;
	}

	//��¼ɾ����λ��
	OrderNode* index = p->head;

	//����ɾ��������
	Order res = { 0 };


	//˫����ֻ��һ��Ԫ�أ�ֱ���ͷ�ͷ��ͷβ��NULL
	if (p->count == 1)
	{
		res = p->head->order;

		//�ͷſռ�
		free(p->head);
		p->head = NULL;
		p->tail = NULL;
	}
	//ɾ��֮�󲻿գ�����ɾ����λ���ڵ�һ��
	else if (position == 1 && p->count > 1)
	{
		res = p->head->order;

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
		res = p->head->order;

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
		res = p->head->order;

		//��ǰɾ���ڵ��ǰһ���ڵ�nextָ��ɾ���ڵ��next
		index->pre->next = index->next;

		//��ǰɾ���ڵ�next��preָ��index��pre
		index->next->pre = index->pre;

		//�ͷſռ�
		free(index);
	}

	//��ЧԪ�ؼ�1
	p->count--;
	printf("ɾ���ɹ�\n");
	return &res;
}


//����--����ֵ���ң�����ֵ��λ��
int searchValueOrderList(const OrderList list, const Order order) {
	if (judgeEmpotyOrderList(list))
	{
		printf("˫�����Ѿ�Ϊ�գ����ܲ���\n");
		return 0;
	}

	//��ʱ����������˫�������
	OrderNode* temp = list.head;

	int i = 1;

	while (temp != NULL)
	{
		//�ҵ��˷��أ����Ԫ����˫����ĵڼ���
		if (temp->order.order_num == order.order_num)
		{
			return i;
		}

		i++;
		temp = temp->next;
	}
	printf("û���ҵ�\n");
	return 0;
}

//����--����λ�ò��ң��������λ�õ�ֵ
Order* searchPositionOrderList(const OrderList list, const int position) {
	if (judgeEmpotyOrderList(list))
	{
		printf("˫������Ϊ��,�޷�����\n");
		return NULL;
	}

	if (position < 1 || position > list.count)
	{
		printf("���ҵ�λ�ò�����\n");
		return NULL;
	}

	//��ʱ������ѭ������˫����
	OrderNode* temp = list.head;
	int i = 1;
	while (i < position)
	{
		temp = temp->next;
		i++;
	}

	return &(temp->order);
}


//����--����ֵ��ѯ���ز��ҵĵ�ַ
Order* searchValueReturnAddressOrderList(const OrderList list, const int ordernum) {
	if (judgeEmpotyOrderList(list))
	{
		printf("˫�����Ѿ�Ϊ�գ����ܲ���\n");
		return NULL;
	}

	//��ʱָ����������ҵ��ĵ�ַ
	OrderNode* temp = list.head;

	while (temp != NULL)
	{
		if (temp->order.order_num == ordernum)
		{
			return &(temp->order);
		}
		//ָ����һ�����ҵ�λ��
		temp = temp->next;
	}

	return NULL;
}

//���
void clearOrderList(OrderList* p) {
	if (p == NULL)
	{
		printf("���˫����Ĳ���Ϊ��\n");
		return;
	}
	if (judgeEmpotyOrderList(*p))
	{
		printf("˫�����Ѿ�Ϊ�գ����������\n");
		return;
	}

	while (p->head != NULL)
	{
		//��ʱ�����������ͷſռ�
		OrderNode* temp = p->head;

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
void printOrderList(const OrderList list) {
	if (judgeEmpotyOrderList(list))
	{
		printf("˫����Ϊ�գ�û�п��Դ�ӡ��Ԫ��\n");
		return;
	}

	//��ʱ�����������洢��ӡ�ڵ�
	OrderNode* temp = list.head;

	if (temp == NULL)
	{
		return;
	}

	while (temp != NULL)
	{

		printf("������:%d,�û�����:%s,��ϵ�绰:%s,�ռ���ַ:%s,�µ�ʱ��:%s\n",
			temp->order.order_num, temp->order.name, temp->order.phone, temp->order.address, temp->order.order_time);

		printf("�������Ʒ��:\n");
		displayGoods(temp->order.goods, temp->order.count);

		printf("\n");
		//ָ����һ����ӡ�Ľڵ�Ԫ��
		temp = temp->next;
	}
	printf("\n");
}


//��������Ϣ���浽�ļ�
void saveAllOrderInfo(const OrderList list) {

	if (judgeEmpotyOrderList(list))
	{
		return;
	}

	FILE* file = fopen("../Order/order.txt", "w");
	if (!file)
	{
		printf("�ļ���ʧ��\n");
		return;
	}

	OrderNode* order = list.head;


	while (order != NULL)
	{
		//д�붩���š��û�������ϵ��ʽ���ռ���ַ���µ�ʱ��
		fprintf(file, "%d\t%s\t%s\t%s\t%s\t", order->order.order_num, order->order.name, order->order.phone, order->order.address, order->order.order_time);

		//д����Ʒ��Ϣ
		int i = 0;
		GoodsNode* goods = order->order.goods.head;
		while (goods != NULL)
		{
			//������ƷId����Ʒ���ơ���Ʒ�۸���Ʒ����
			fprintf(file, "%d\t%s\t%d\t%d\t", goods->goods.ID, goods->goods.name, goods->goods.price, order->order.count[i++]);
			goods = goods->next;
		}

		fprintf(file, "\n");

		order = order->next;
	}

	fclose(file);
}


//��ȡ�ļ���Ϣ���ڴ�
void getAllOrderInfo(OrderList* p) {

	if (p == NULL)
	{
		return;
	}
	FILE* file = fopen("../Order/order.txt", "r");
	if (!file)
	{
		printf("�ļ���ʧ��\n");
		return;
	}

	//OrderNode* node = p->head = (OrderNode*)malloc(sizeof(OrderNode));


	while (!feof(file))
	{
		Order node = { 0 };
		fscanf(file, "%d\t%s\t%s\t%s\t%s\t", &node.order_num, node.name, node.phone, node.address, node.order_time);


		//ѭ����ȡ��������Ʒ��Ϣ
		GoodsList goodsList = { 0 };
		initGoods(&goodsList);
		int i = 0;
		Goods goods = { 0 };

		int count[10] = { 0 };
		fscanf(file, "%d\t%s\t%d\t%d\t", &(goods.ID), goods.name, &(goods.price), &count[i]);

		while (goods.price > 0 && goods.price < 1000)
		{
			i++;
			insertGoodsByFile(&goodsList, goods);

			fscanf(file, "%d\t%s\t%d\t%d\t", &(goods.ID), goods.name, &(goods.price), &count[i]);
		}

		fscanf(file, "\n");

		node.goods = goodsList;
		node.count = count;

		displayGoods(goodsList, NULL);

		insertPositionOrderList(p, p->count + 1, node);

		printOrderList(*p);
	}

	fclose(file);
}
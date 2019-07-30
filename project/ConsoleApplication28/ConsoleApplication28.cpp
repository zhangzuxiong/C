// ConsoleApplication28.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//排序算法

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10


//交换两个数的值
void swap(int* a, int* b) {
	int temp = *b;
	*b = *a;
	*a = temp;
}

//生成数组
void createArrayList(int* arr) {
	if (arr==NULL)
	{
		return;
	}
	srand(time(NULL));

	//标记是否有重复的数字
	int mark[SIZE] = { 0 };

	int i = 0;

	for (i = 0; i < SIZE; i++)
	{
		arr[i] = rand() % SIZE;

		//如果重复，重新生成
		if (mark[arr[i]] != 0)
		{
			i--;
		}
		else
		{
			mark[arr[i]] = 1;
		}
	}
}

//打印数组
void printArray(int* arr) {
	int i = 0;
	while (i<SIZE)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");
}



//冒泡排序  相邻位置进行比较
void bubbleSort(int* arr) {
	if (arr == NULL)
	{
		return;
	}
	//执行次数
	int count = 0;
	int i = 0;
	for (i = 0; i < SIZE - 1; i++)
	{
		int j = 0;
		for (j; j < SIZE-1-i; j++)
		{
			if (arr[j] > arr[j+1])
			{
				count++;
				swap(&arr[j], &arr[j+1]);
			}
		}
	}

	printf("冒泡排序:%d次\n", count);
}

//插入排序
void insertionSort(int* arr) {
	if (arr==NULL)
	{
		return;
	}
	int count = 0;
	int i = 0;
	int j = 0;
	for ( i = 1; i < SIZE; i++)
	{
		int index = arr[i];
		j = i - 1;

		//无序序列的第一个与有序序列循环比较，
		//如果无序的数小于有序序列的数，就将无序的数插入到这个位置
		//while是在循环有序序列
		while (j>=0&&arr[j]>index)
		{
			arr[j + 1] = arr[j];
			count++;
			j--;
		}

		arr[j + 1] = index;
	}

	printf("插入排序:%d次\n", count);
}

//选择排序  交换次数最少,先找到最小值的下标然后交换
//相当于每次找一个无序序列的最小值，放在有序序列的末尾
void selectSort(int* arr) {
	if (arr==NULL)
	{
		return;
	}
	int count = 0;
	int i = 0;
	int j = 0;

	for ( i = 0; i < SIZE-1; i++)
	{
		
		int min = i;//记录最小值得下标
		//循环无序序列找到最小值得下标
		for ( j = i+1; j < SIZE; j++)
		{
			if (arr[min]>arr[j])
			{
				min = j;
			}
		}

		//如果最小值不等于i那么久交换这两个小标对应的值
		if (min!=i)
		{
			count++;
			swap(&arr[min], &arr[i]);
		}
	}
	printf("选择排序:%d次\n", count);
}



//创建大堆顶，i为当节点，n为堆的大小
//从第一个非叶子结点i从下至上，从右至左调整结构
//从两个儿子节点中选出较大的来与父亲节点进行比较
//如果儿子节点比父亲节点大，则进行交换
void creatHeap(int* a, int i, int  n) {

	//注意数组是从0开始计数，所以左节点为2*i+1，右节点为2*i+2
	for (; i >= 0; --i)
	{
		int left = i * 2 + 1;    //左子树节点
		int right = i * 2 + 2;    //右子树节点
		int j = 0;
		//选出左右子节点中最大的
		if (right < n) {
			a[left] > a[right] ? j = left : j = right;
		}
		//没有右子树
		else
			j = left;
		//交换子节点与父节点
		if (a[j] > a[i]) {
			swap(&a[j], &a[i]);
		}
	}
}

//进行堆排序，依次选出最大值放到最后面
void heapSort(int* a, int n) {
	//初始化构造堆
	creatHeap(a, n / 2 - 1, n);
	//交换第一个元素和最后一个元素后，堆的大小减1
	for (int j = n - 1; j >= 0; j--) {

		//最后一个元素和第一个元素进行交换
		swap(&a[0], &a[j]);

		int i = j / 2 - 1;
		creatHeap(a, i, j);
	}
}


//分治法把数组分成两份
int patition(int* a, int left, int right) {
	int j = left;    //用来遍历数组
	int i = j - 1;    //用来指向小于基准元素的位置
	int key = a[right];    //基准元素
	//从左到右遍历数组，把小于基准元素的放到左边，大于基准元素的放到右边
	while (j < right) {
		if (a[j] < key) {
			i++;
			swap(&a[j], &a[i]);
		}
		j++;
	}
	//把基准元素放到中间
	i++;
	swap(&a[right], &a[i]);
	//返回数组中间位置
	return i;
}
//快速排序
void quickSort(int* a, int left, int right) {
	if (left >= right)
		return;
	int mid = patition(a, left, right);
	quickSort(a, left, mid - 1);
	quickSort(a, mid + 1, right);
}

//合并
void merge(int* p, int left, int mid, int right) {
	if (p==NULL)
	{
		return;
	}

	//定义一个新数组，保存数据
	int len = right - left + 1;
	int* temp = (int*)malloc(sizeof(int) * len);

	int index = 0;
	int i = left;
	int j = mid+1;

	while (i <= mid && j <= right)
	{
		temp[index++] = p[i] < p[j] ? p[i++] : p[j++];
		/*if ( p[i] < p[j] )
		{
			temp[index] = p[i];

			i++;
		}
		else
		{
			temp[index] = p[j];

			j++;
		}

		index++;*/
	}

	while (i<=mid)
	{
		temp[index++] = p[i++];
	}
	while (j<=right)
	{
		temp[index++] = p[j++];
	}

	
	for (int i = 0; i < len; i++)
	{
		p[left++] = temp[i];
	}

	free(temp);
}

//归并排序
void mergeSort(int* arr,int left,int right) {
	if (arr==NULL)
	{
		return;
	}

	if (left==right)
	{
		return;
	}

	int mid = (left + right) / 2;

	//拆分
	mergeSort(arr, left, mid);
	mergeSort(arr,mid + 1, right);

	//合并
	merge(arr, left, mid, right);


}


//快速排序
//将数组一分为二，获取中间值
int sign(int* p,int begin,int end) {
	if (p==NULL)
	{
		return -1;
	}
	//第一个位置作为基准值
	//需要一个下标表示较小的序列的末尾
	int min_tail = begin;
	int i = 0;
	for ( i = begin+1; i <= end; i++)
	{
		//如果数值小于基准值，交换较小序列的末尾的后一个
		if (p[i]<p[begin])
		{
			min_tail++;
			swap(&p[min_tail], &p[i]);
		}
	}

	//循环一次可以确定基准值的位置
	swap(&p[min_tail], &p[begin]);
	return min_tail;

}


void quick_Sort(int* arr,int begin,int end) {
	if (arr==NULL)
	{
		return;
	}

	//递归出口
	if (begin>=end)
	{
		return;
	}

	int mid = sign(arr, begin, end);

	//左排序
	quick_Sort(arr, begin, mid-1);

	//右排序
	quick_Sort(arr, mid+1, end);
}


//希尔排序
void shellSort(int* p,int length) {
	if (p==NULL)
	{
		return;
	}

	//组内间隔
	int interval = length / 2;
	for ( interval = length / 2; interval > 0; interval/=2)
	{
		int n = 0;
		//每次分组的个数
		for ( n = 0; n < interval; n++)
		{
			int i = 0;
			int j = 0;
			//组内插入排序
			for (i = n+interval; i < length; i+=interval)
			{
				int index = p[i];
				j = i - interval;

				while (j >= 0 && p[j] > index)
				{
					p[j + interval] = p[j];
					j=j-interval;
				}

				p[j + interval] = index;
			}
		}
	}

}



int main()
{
	int arr[SIZE] = { 0 };

	//createArrayList(arr);
	//printArray(arr);
	//bubbleSort(arr);//冒泡
	//printArray(arr);
	//printf("\n");


	//createArrayList(arr);
	//printArray(arr);
	//insertionSort(arr);//插入排序
	//printArray(arr);
	//printf("\n");

	//createArrayList(arr);
	//printArray(arr);
	//selectSort(arr);//选择排序
	//printArray(arr);
	//printf("\n");


	//createArrayList(arr);
	//printArray(arr);
	//heapSort(arr,SIZE);//堆排序
	//printArray(arr);
	//printf("\n-------------\n");


	//createArrayList(arr);
	//printArray(arr);
	//quickSort(arr,0,SIZE-1);//快速排序
	//printArray(arr);
	//printf("\n------\n");


	//createArrayList(arr);
	//printArray(arr);
	//quick_Sort(arr, 0, SIZE - 1);//快速排序
	//printArray(arr);
	//printf("\n");


	createArrayList(arr);
	printArray(arr);
	mergeSort(arr, 0, SIZE - 1);//归并排序
	printArray(arr);
	printf("\n");

	createArrayList(arr);
	printArray(arr);
	shellSort(arr,SIZE);//归并排序
	printArray(arr);
	printf("\n");

    return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	//日期——每4年一个闰年"这说法不严谨。应该是四年一闰，百年不闰，四百年再闰
	//输入一个日期，判断是今年的第几天
	//输入一个日期，判断是今年还剩多少天

	int y = 0, m = 0, d = 0, sum = 0;
	printf("请输入年份：");
	scanf("%d", &y);
	//判断闰年
	if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
	{
		//闰年366
		y = 1;
	}

	printf("请输入月份：");
	scanf("%d", &m);
	if (m <= 0 || m > 12) {
		printf("您输入的月份不正确！！程序退出！！！");
		return 0;
	}
	int i = m;

	while (i > 0)
	{
		i--;
		switch (i) {
		case 1:sum += 31;
			break;
		case 2:
			if (y == 1)
			{
				sum += 29;
			}
			else {
				sum += 28;
			}
			break;
		case 3:sum += 31;
			break;
		case 4:sum += 30;
			break;
		case 5:sum += 31;
			break;
		case 6:sum += 30;
			break;
		case 7:sum += 31;
			break;
		case 8:sum += 31;
			break;
		case 9:sum += 30;
			break;
		case 10:sum += 31;
			break;
		case 11:sum += 30;
			break;
		case 12:sum += 31;
			break;
		default:
			break;
		}
	}


	printf("请输入日：");
	scanf("%d", &d);
	if (d > 31 || d < 1)
	{
		//判断输入的日是否正确
		printf("您输入的日不正确！！程序退出！！");
		return 0;
	}
	sum += d;
	printf("您输入的日期是今年的第%d天\n", sum);

	if (y == 1)
	{
		printf("还剩%d天\n", 366 - sum);
	}
	if (y != 1)
	{
		printf("还剩%d天\n", 365 - sum);
	}

	return 0;

	//2.输入一个数判断是否可以同时被3或（和）7整除
	int a2 = 0;
	printf("请输入一个数：");
	scanf("%d", &a2);
	if (a2 % 3 == 0 || a2 % 7 == 0)
	{
		printf("可以被3或7整除 !!!    ");
	}
	if (a2 % 3 == 0 && a2 % 7 == 0)
	{
		printf("可以被3和7整除!!!");
	}
	printf("\n");

	return 0;

	//1.输入三个数，打印从小到大的结果
	int a = 0, b = 0, c = 0, temp = 0;
	printf("请输入三个数：");
	scanf("%d", &a);
	scanf("%d", &b);
	if (a > b)
	{
		temp = b;
		b = a;
		a = temp;
	}
	scanf("%d", &c);
	if (b > c)
	{
		temp = c;
		c = b;
		b = temp;
	}
	if (a > b)
	{
		temp = a;
		a = b;
		b = temp;
	}

	printf("从小到大的顺序为：%d   %d   %d\n", a, b, c);

	return 0;
}

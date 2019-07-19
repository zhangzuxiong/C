// ConsoleApplication7.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

/*
	读写
	fwrite()
	fread()
*/
void fun_01() {

	//打开文件
	FILE* wfile = fopen("test.txt", "w");

	//写
	char str[20] = "1234567890qwert";
	//printf("%p   %p\n", str, &str);
	fwrite(str, sizeof(str), 1, wfile);
	fclose(wfile);

	//读
	FILE* rfile = fopen("test.txt", "r");
	char s[20] = { 0 };
	fread(s, sizeof(char), strlen(str), rfile);
	printf("%s\n", s);
	fclose(rfile);
}


/*

	读写
	fgetc()
	fputc()
*/
void fun_02() {
	//打开文件
	FILE* wfile = fopen("test.txt", "w");

	char c = '1';
	while (c != '0')
	{
		c = getchar();
		fputc(c, wfile);

	}

	//文件结束符
	fputc('\0', wfile);

	fclose(wfile);

	FILE* rfile = fopen("test.txt", "r");
	char c1 = fgetc(rfile);
	while (c1 != '\0')
	{
		printf("%c", c1);
		c1 = fgetc(rfile);
	}
	printf("\n");
	fclose(rfile);

}

/*

	读写
	fgets()
	fputs()
*/
void fun_03() {



	FILE* file1 = fopen("test.txt", "w");
	char str[256] = "1234";

	printf("Enter sentence to append: ");
	//fgets(str, 256, stdin);//输入的回车会被写入文件
	fputs(str, file1);//写
	fclose(file1);



	FILE* file2 = fopen("test.txt", "r");
	char ss[100] = { 0 };

	if (file2 == NULL)
		perror("Error opening file");
	else {
		if (fgets(ss, 100, file2) != NULL)//每次读取100个字符
			puts(ss);
		fclose(file2);
	}
	printf("%s\n", ss);
}

/*
	fprintf()
	fscanf()
*/
void fun_04() {
	char str[80];
	float f;
	FILE* pFile;

	pFile = fopen("test.txt", "w+");
	fprintf(pFile, "%f %s", 3.1416, "PI");//写


	rewind(pFile);//将读取的位置设置为开头
	fscanf(pFile, "%f", &f);//读
	fscanf(pFile, "%s", str);
	fclose(pFile);
	printf("I have read: %f and %s \n", f, str);
}

int main()
{
	//fun_01();

	//fun_02();

	//fun_03();

	fun_04();

	return 0;
}


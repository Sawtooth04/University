
#include "stdafx.h"
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#define HEIGHT 10
#define LENGHT 50
#define N 150

struct line
{
	char district[18];
	float first_y;
	float second_y;
};

FILE *f_open(char *str)
{
	char name[N];
	FILE *p;
	do
	{
		printf("Введите путь к файлу: ");
		scanf("%s", name);
		strcpy(str, name);
		if((p = fopen(name, "r")) == NULL)
		{
			printf("Данный файл не найден. Хотите создать его? (y/n)\n");
			if((char)getch() == 'y')
			{
				p = fopen(name, "w");
				return p;
			}
			else
				continue;
		}
		else
		{
			fclose(p);
			p = fopen(name, "w");
			return p;
		}
	}
	while(true);
}

int init(FILE *p)
{
	struct line a;
	int i = 1, n;
	while(true)
	{
		printf("Введите данные %d строки: ", i);
		printf("Регион (введите end для завершения ввода): ");
		fflush(stdin);
		gets(a.district);
		if(strcmp(a.district, "end") == 0)
			return NULL;
		do
		{
			printf("Запас 1940: ");
			n = scanf("%f", &a.first_y);
			fflush(stdin);
		}
		while(n == 0);
		do
		{
			printf("Запас 1958: ");
			n = scanf("%f", &a.second_y);
			fflush(stdin);
		}
		while(n == 0);
		fwrite(&a, sizeof(struct line), 1, p);
		i++;
	}
}

void file_read(FILE *p)
{
	fseek(p, 0, SEEK_SET);
	char temp[N];
	while(!feof(p))
	{
		fgets(temp, N, p);
		printf("%s", temp);
	}
}

int main()
{
	system("color F0");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char temp[LENGHT];
	char name[N];
	struct line file_line;
	bool topic_flag = true;
	int i = 0;
	float difference;
	FILE *pf_in;
	FILE *pf_out;
	char *p;

	pf_in = f_open(name);
	pf_out = fopen("output.txt", "w+");
	init(pf_in);
	fclose(pf_in);
	pf_in = fopen(name, "r");

	while(fread(&file_line, sizeof(struct line), 1, pf_in))
	{
		if(topic_flag)
		{
			printf("Район\t\t1940\t1958");
			topic_flag = false;
		}
		printf("\n%s\t\t%.2f\t%.2f", file_line.district, file_line.first_y, file_line.second_y);
		if((difference = (float)(file_line.second_y - file_line.first_y)) >= 0 && !topic_flag)
		{
			if(i == 0)
				fprintf(pf_out,"\nРайон\t\tРазница");

			fprintf(pf_out,"\n%s\t\t%.2f", file_line.district, difference);
			i++;
		}
		topic_flag = false;
	}

	if(i == 0)
	{
		fprintf(pf_out, "Не найдено газоносных районов, процент запасов которых не снизился.");
		printf("\nНе найдено газоносных районов, процент запасов которых не снизился.");
	}
	else
	{
		printf("\n");
		file_read(pf_out);
	}
	printf("\nПрограмма выполнена успешно. Результат сохранён в файл output.txt\n");

	fclose(pf_in);
	fclose(pf_out);
	getch();
	return 0;
}

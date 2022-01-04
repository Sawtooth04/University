#include "stdafx.h"
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#define N 150
#define MAX 100

struct line
{
	char currency[N];
	float decline_first;
	float decline_second;
	float capacity;
};

float eps_init()
{
	int n;
	float digit;
	do
	{
		printf("������� ��������� �������� �������� ��������: ");
		n = scanf("%f", &digit);
	}
	while(n == 0);
	return digit;
}

int init(FILE *p)
{
	struct line a;
	int i = 1, n;
	while(true)
	{
		printf("������� ������ %d ������: \n", i);
		printf("������ (������� end ��� ���������� �����): ");
		fflush(stdin);
		gets(a.currency);
		if(strcmp(a.currency, "end") == 0)
			return NULL;
		do
		{
			printf("�������� �������� � 1929: ");
			n = scanf("%f", &a.decline_first);
			fflush(stdin);
		}
		while(n == 0);
		do
		{
			printf("�������� �������� � 1957: ");
			n = scanf("%f", &a.decline_second);
			fflush(stdin);
		}
		while(n == 0);
		do
		{
			printf("������� ������������� �����������: ");
			n = scanf("%f", &a.capacity);
			fflush(stdin);
		}
		while(n == 0);
		fwrite(&a, sizeof(struct line), 1, p);
		i++;
	}
}

FILE *f_open(char *str)
{
	char name[N];
	FILE *p;
	do
	{
		printf("������� ���� � �����: ");
		scanf("%s", name);
		strcpy(str, name);
		if((p = fopen(name, "r")) == NULL)
		{
			printf("������ ���� �� ������. ������ ������� ���? (y/n)\n");
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


void max_capacity_decline(FILE *p, FILE *o, float eps)
{
	struct line a;
	float max = 0;
	char �urr_max[N];
	char *point;
	bool first = true;

	while(fread(&a, sizeof(struct line), 1, p))
	{
		if(a.capacity > max)
		{
			strcpy(�urr_max, a.currency);
			max = a.capacity;
		}
		printf("\n%s\t%.4f\t%.4f\t%.4f", a.currency, a.decline_first, a.decline_second, a.capacity);
		if(a.decline_first > eps)
		{
			if(first)
			{
				fprintf(o, "������, �������� ����������� �������� ������� ��������� eps � 1929 ����: \n\n");
				fprintf(o, "������\t\t�������� �����������\t������� ������������� �����������\n\t\t\t1929\t\t1957\n");
				first = false;
			}
			fprintf(o,"\n%s\t\t%.4f\t%.4f\t\t\t%.4f", a.currency, a.decline_first, a.decline_second, a.capacity);
		}
	}
	if(first == true)
		fprintf(o, "\n�� ������� �����, �������� ����������� �������� ������� ��������� eps � 1929 ����. \n");

	fprintf(o, "\n������������ ������� ������������� �����������: %s\n", �urr_max);
}

void decline_eps(FILE *p, FILE *o, float eps)
{
	struct line a;
	char temp[MAX], temp_first[MAX], temp_second[MAX];
	int n = 0;
	char *point;
	bool first = true;
	long sec, start;
	float b;

	fseek(p, 0, SEEK_SET);
	while(fread(&a, sizeof(struct line), 1, p))
	{
		if(a.decline_second <= eps)
		{
			if(first)
			{
				fprintf(o, "\n������, �������� ����������� �������� ������� �� ��������� eps � 1957 ����: \n\n");
				fprintf(o, "������\t\t�������� �����������\t������� ������������� �����������\n\t\t1929\t\t1957");
			}
			n++;
			fprintf(o, "\n");
			if(first)
			{
				start = ftell(o);
				first = false;
			}
			fprintf(o,"%s\t\t%.4f\t\t%.4f\t\t%.4f", a.currency, a.decline_first, a.decline_second, a.capacity);
		}
	}
	if(first == true)
		fprintf(o, "\n�� ������� �����, �������� ����������� �������� ������� �� ��������� eps � 1957 ����.");
	//if(first == false)
	//{
	//	for(int i = 0; i < n - 1; i++)
	//	{
	//		sec = start;
	//		for(int j = 0; j < n - 1; j++)
	//		{
	//			fseek(o, sec, SEEK_SET);
	//			fgets(temp_first, MAX, o);
	//			fgets(temp_second, MAX, o);
	//			if(strcmp(temp_first, temp_second) < 0)
	//			{
	//				fseek(o, sec, SEEK_SET);
	//				fprintf(o, "%s", temp_second);
	//				sec = ftell(o);
	//				fprintf(o, "%s", temp_first);
	//			}
	//			else if(strcmp(temp_first, temp_second) > 0)
	//			{
	//				fseek(o, sec, SEEK_SET);
	//				fprintf(o, "%s", temp_first);
	//				sec = ftell(o);
	//			}
	//		}
	//	}
	//}
}

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	FILE *fp;
	FILE *fo;
	float eps;
	char name[N];

	fp = f_open(name);
	fo = fopen("output.txt", "w+");
	init(fp);
	fclose(fp);
	fp = fopen(name, "r");
	eps = eps_init();
	max_capacity_decline(fp, fo, eps);
	decline_eps(fp, fo, eps);
	printf("\n");
	file_read(fo);
	printf("\n\n��������� ��������� �������. ��������� ������� � ���� output.txt\n");
	system("pause");
}



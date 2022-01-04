
#include "stdafx.h"
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#define HEIGHT 10
#define MIN 1
#define MAX 10000
#define N 6

struct line
{
	int year;
	int turnover;
	int index_exp_us;
	int index_exp_en;
	int index_exp_ge;
};

void init(char *string, int n, int *p, int min, int max)	//�-��� �������� ������������ ����� ������ �������
	{
		char temp[N] = {0};
		bool flag = true;
		do
			{
				memset(temp, 0, sizeof(char)*N);
				fflush(stdin);
				printf("������� %s %d-� ������: ", string, n + 1);
				scanf("%5s", temp);
				for(int i = 0; i < N; i++){
					if(isdigit(temp[i]) != 0 || temp[i] == 0)
						flag = true;	
					else{ 
						flag = false;
						break;
					}
				}
				if(flag == true)
					*p = atoi(temp);	
			}
		while(*p < min || *p > max || flag == false);
	}

void init(char *string, int *p, int min, int max)	//�-��� �������� ������������ ����� ������
{
	char temp[N] = {0};
	bool flag = true;

	do
	{
		memset(temp, 0, sizeof(char)*N);
		fflush(stdin);
		printf("������� %s: ", string);
		scanf("%5s", temp);
		for(int i = 0; i < N; i++)
		{
			if(isdigit(temp[i]) != 0 || temp[i] == 0)
				flag = true;	
			else
			{ 
				flag = false;
				break;
			}
		}
		if(flag == true)
			*p = atoi(temp);	
	}
	while(*p < min || *p > max || flag == false);
}


void main()
{
	setlocale(LC_ALL, "rus");
	system("color F0");
	struct line arr[HEIGHT] = {0};
	int n = 0, min_turnover = 0, min_turnover_year = 0, p, diff = 0;
	bool flag = true;

	init("���������� �����", &n, MIN, HEIGHT);
	init("��������� �������� ������� � �������� �������� ��� � ���", &p, MIN, MAX);

	for(int i = 0; i < n; i++)
	{
		init("���", i, &arr[i].year, MIN, MAX);
		init("������", i, &arr[i].turnover, MIN, MAX);
		init("������ �������� ���", i, &arr[i].index_exp_us, MIN, MAX);
		init("������ �������� ������", i, &arr[i].index_exp_en, MIN, MAX);
		init("������ �������� ���", i, &arr[i].index_exp_ge, MIN, MAX);
	}
	printf("����� �������������� ������� \n\n");
	printf("���\t������(����.$)\t\t������ ��������\n\t\t\t    ���      ������      ���\t\t\n");
	for(int i = 0; i < n; i++)
		printf("%d\t%d\t\t    %d\t     %d\t %d\n", arr[i].year, arr[i].turnover, arr[i].index_exp_us, arr[i].index_exp_en, arr[i].index_exp_ge);

	min_turnover = arr[0].turnover;
	min_turnover_year = arr[0].year;

	for(int i = 0; i < n; i++)
	{
		diff = abs(arr[i].index_exp_us - arr[i].index_exp_ge);
		if(diff <= p)
		{
			if(flag)
			{
				printf("\n\n���\t\t������ ��������\t\t������� ��������\t\n\t\t ���       ���\n");
				flag = false;
			}
			printf("%d\t\t %d       %d \t\t%d\n", arr[i].year, arr[i].index_exp_us, arr[i].index_exp_ge, diff);
		}
		if(arr[i].turnover < min_turnover)
		{
			min_turnover_year = arr[i].year;
			min_turnover = arr[i].turnover;
		}
	}
	printf("\n����������� ������ %d ����.$ ��� � %d ����\n\n", min_turnover, min_turnover_year);

	if(flag)
		printf("�� ������� ���, � ������� �������� � �������� �������� ��� � ��� �� ������ P\n");

	getch();
}


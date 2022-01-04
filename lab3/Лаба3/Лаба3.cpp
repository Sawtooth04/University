
//����������, ����������� �� ������������ ������� ���������� ������� �������, ������� ���� � �������� ���������.

#include "stdafx.h"
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <time.h>
#define N 15

void main()
{
	srand(time(NULL));
	system("color F0");
	setlocale(LC_ALL,"Russian");
	int n, max_temp, max_i, max_j, diagonal_i;
	int arr[N][N];
	
	do
	{
		printf("������� ������� ������� \n");
		scanf("%d", &n);		
	}
	while(n < 2 || n > N);

	for(int i = 0, j = 0; i < n; i++)									// ��������� ������ ����������
			for(int j = 0; j < n; j++)
					arr[i][j] = -25 + rand()%50;

	for(int i = 0; i < n; i++)											// ������� ������ �� �����
	{
		printf("\n\n");
		for(int j = 0; j < n; j++)
			printf("   %d ", arr[i][j]);
	}																	

	printf("\n");

	max_temp = arr[0][0];

	for(int i = 0; i < n; i++)											// ������� ������������ ������� �������
		for(int j = 0; j < n; j++)
			{
				if(arr[i][j] > max_temp)
					{
						max_i = i;
						max_j = j;
						max_temp = arr[i][j];
					}
			}
	printf("������������ ������� ������� - %d (%d , %d)\n", arr[max_i][max_j], max_i + 1, max_j + 1);

	diagonal_i = n - max_j - 1;											// ������� ����� ������ �������� ���������
	if(max_i < diagonal_i)
		printf("������������ ������� ����� ���� �������� ���������");
	else if(max_i > diagonal_i)
		printf("������������ ������� ����� ���� �������� ���������");
	else 
		printf("������������ ������� ����� �� �������� ���������");

	getch();
}


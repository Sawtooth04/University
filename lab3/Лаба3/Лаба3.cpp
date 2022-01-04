
//Определить, принадлежит ли максимальный элемент квадратной матрицы области, лежащей выше её побочной диагонали.

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
		printf("Введите порядок матрицы \n");
		scanf("%d", &n);		
	}
	while(n < 2 || n > N);

	for(int i = 0, j = 0; i < n; i++)									// Заполняем массив элементами
			for(int j = 0; j < n; j++)
					arr[i][j] = -25 + rand()%50;

	for(int i = 0; i < n; i++)											// Выводим массив на экран
	{
		printf("\n\n");
		for(int j = 0; j < n; j++)
			printf("   %d ", arr[i][j]);
	}																	

	printf("\n");

	max_temp = arr[0][0];

	for(int i = 0; i < n; i++)											// Находим максимальный элемент матрицы
		for(int j = 0; j < n; j++)
			{
				if(arr[i][j] > max_temp)
					{
						max_i = i;
						max_j = j;
						max_temp = arr[i][j];
					}
			}
	printf("Максимальный элемент матрицы - %d (%d , %d)\n", arr[max_i][max_j], max_i + 1, max_j + 1);

	diagonal_i = n - max_j - 1;											// Находим номер строки элемента диагонали
	if(max_i < diagonal_i)
		printf("Максимальный элемент лежит выше побочной диагонали");
	else if(max_i > diagonal_i)
		printf("Максимальный элемент лежит ниже побочной диагонали");
	else 
		printf("Максимальный элемент лежит на побочной диагонали");

	getch();
}


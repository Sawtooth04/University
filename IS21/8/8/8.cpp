

#include "stdafx.h"
#include <stdlib.h>
#include "locale.h"
#define N 50

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	int n_A;
	int A[N][N], temp, counter = 0;

	do
	{
		printf("Введите размерность матрицы A: ");
		scanf("%d", &n_A);
	}
	while(n_A < 0 || n_A > N);

	for(int i = 0; i < n_A; i++)
	{
		printf("\n");
		for(int j = 0; j < n_A; j++)
		{
			A[i][j] = rand()%50 - 25;
			printf("  %d  ", A[i][j]);
		}
	}

	for(int i = 0; i < n_A; i++)
		for(int j = 0; j < n_A; j++)
		{
			if(i == j)
				continue;
			if(A[i][j] > A[j][i])
			{
				temp = A[i][j];
				A[i][j] = A[j][i];
				A[j][i] = temp;
				counter++;
			}
		}

	printf("\nИтоговый матрица:\n");
	for(int i = 0; i < n_A; i++)
	{
		printf("\n");
		for(int j = 0; j < n_A; j++)
			printf("  %d  ", A[i][j]);
	}
	printf("\nКоличество перестановок: %d\n", counter);

	system("pause");
	return 0;
}


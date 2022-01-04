
#include "stdafx.h"
#include "stdlib.h"
#include "locale.h"

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	int n, m, temp, start, end, dj = 1;
	bool swap = false;

	do
	{
		printf("Введите количество строк матрицы A: ");
		scanf("%d", &n);
	}
	while(n < 1);

	do
	{
		printf("Введите количество столбцов матрицы A: ");
		scanf("%d", &m);
	}
	while(m < 1);

	int **A = (int**)malloc(n*sizeof(int *));
    for(int i = 0; i < m; i++) 
	{
        A[i] = (int*)malloc(m*sizeof(int));
    }

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			A[i][j] = rand()%50 - 25;

	printf("\nИсходная матрица:\n");
	for(int i = 0; i < n; i++)
	{
		printf("\n");
		for(int j = 0; j < m; j++)
			printf("  %d  ", A[i][j]);
	}

	for(int i = 0; i < n; i++)
	{
		swap = false;
		if((i % 2) == 0)
		{
			end = m - 1;
			start = 0;
		}
		else
		{
			end = 0;
			start = m;		
		}
		for(int k = 0; k < m; k++)
		{
			for(int j = start; j != end; j += dj)	
			{
				if(A[i][j] > A[i][j + dj])
				{
					temp = A[i][j];
					A[i][j] = A[i][j + dj];
					A[i][j + dj] = temp;
					swap = true;
				}
			}
			if(!swap)
				break;
		}
		dj *= -1;
	}

	printf("\nИтоговая матрица:\n");
	for(int i = 0; i < n; i++)
	{
		printf("\n");
		for(int j = 0; j < m; j++)
			printf("  %d  ", A[i][j]);
	}
	printf("\n");

	system("pause");
	return 0;
}


#include "stdafx.h"
#include "locale.h"
#include "stdlib.h"
#define N 100

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	int n_A, n, start, lenght = 0, start_temp, lenght_temp = 0;
	int A[N], B[N];

	do
	{
		printf("¬ведите размерность массива A: ");
		scanf("%d", &n_A);
	}
	while(n_A < 0 || n_A > N);

	for(int i = 0; i < n_A; i++)
	{
		printf("¬ведите %d элемент массива: ", i + 1);
		scanf("%d", &A[i]);
	}
	printf("Ёлементы массива A:\n");
	for(int i = 0; i < n_A; i++)
		printf("  %d  ", A[i]);

	for(int i = 0; i < n_A; i++)
	{
		if(A[i] < A[i + 1])
		{
			start_temp = i;
			for(int j = i; j < n_A; j++)
				if(A[j] > A[j + 1])
				{
					lenght_temp = j - i;
					i = j;
					break;
				}
		}
		if(lenght_temp > lenght)
		{
			lenght = lenght_temp;
			start = start_temp;
		}
	}

	if(lenght_temp != 0)
		for(int i = 0; i < lenght + 1; i++)
			B[i] = A[start + i];

	if(lenght_temp != 0)
	{
		printf("\nЁлементы массива B:\n");
		for(int i = 0; i < lenght + 1; i++)
		{
			printf(" %d ", B[i]);
		}
	}
	else
		printf("\nЌе найдено возрастающих последовательностей.");
	printf("\n");

	system("pause");
	return 0;
}

#include "stdafx.h"
#include "locale.h"
#include "stdlib.h"
#define N 100

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	int n_A, n_B, n, min_a, max_b, temp;
	int A[N], B[N], C[N];
	do
	{
		do
		{
			printf("¬ведите размерность массива A: ");
			scanf("%d", &n_A);
		}
		while(n_A < 0 || n_A % 5 != 0 || n_A > N);
		do
		{
			printf("¬ведите размерность массива B: ");
			scanf("%d", &n_B);
		}
		while(n_B < 0 || n_B % 4 != 0 || n_A > N);
	}
	while((n_A/5) != (n_B/4));

	printf("Ёлементы массива ј:\n");
	for(int i = 0; i < n_A; i++)
	{
		A[i] = rand()%50 - 25;
		printf(" %d ", A[i]);
	}
	
	printf("\nЁлементы массива B:\n");
	for(int i = 0; i < n_B; i++)
	{
		B[i] = rand()%50 - 25;
		printf(" %d ", B[i]);
	}	
	
	min_a = 0;
	for(int i = 1; i < n_A; i++)
		if(A[i] < A[min_a])
			min_a = i;

	max_b = 0;
	for(int i = 1; i < n_B; i++)
		if(B[i] > B[max_b])
			max_b = i;

	temp = A[min_a];
	A[min_a] = B[max_b];
	B[max_b] = temp;

	printf("\nѕосле замены: \n");
	printf("Ёлементы массива ј:\n");
	for(int i = 0; i < n_A; i++)
	{
		printf(" %d ", A[i]);
	}
	
	printf("\nЁлементы массива B:\n");
	for(int i = 0; i < n_B; i++)
	{
		printf(" %d ", B[i]);
	}	

	n = n_A / 5;
	for(int i = 0; i < n; i ++)
	{
		min_a = 5 * i;
		for(int j = 5 * i; j < 5 * (i + 1); j++)
		{
			if(A[j] < A[min_a])
			min_a = j;
		}
		max_b = 4 * i;
		for(int j = 4 * i; j < 4 * (i + 1); j++)
		{
			if(B[j] > B[max_b])
			max_b = j;
		}
		C[i] = A[min_a] + B[max_b];
	}

	printf("\nЁлементы массива C:\n");
	for(int i = 0; i < n; i++)
	{
		printf(" %d ", C[i]);
	}

	printf("\n");
	system("pause");
	return 0;
}


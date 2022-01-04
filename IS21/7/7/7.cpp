
#include "stdafx.h"
#include "locale.h"
#include <stdlib.h>
#define N 50

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	int n_A, m_A;
	int A[N][N], max;

	do
	{
		printf("������� ���������� ����� ������� A: ");
		scanf("%d", &n_A);
	}
	while(n_A < 0 || n_A > N);
	
	do
	{
		printf("������� ���������� ����� ������� A: ");
		scanf("%d", &m_A);
	}
	while(m_A < 0 || m_A > N);

	for(int i = 0; i < n_A; i++)
	{
		printf("\n");
		for(int j = 0; j < m_A; j++)
		{
			A[i][j] = rand()%20 - 10;
			printf("  %d  ", A[i][j]);
		}
	}

	max = A[0][0];

	for(int i = 0; i < n_A; i++)
		for(int j = 0; j < m_A; j++)
			if(A[i][j] > max)
				max = A[i][j];

	printf("\n\n��������: %d\n", max);
	printf("�������������� ���������, �������� ������� ����� ������������� �������� ���� �������:\n������\t������\n");
	for(int i = 0; i < n_A; i++)
		for(int j = 0; j < m_A; j++)
			if(A[i][j] == max)
				printf("%d\t%d\n", i + 1, j + 1);

	system("pause");
	return 0;
}



#include "stdafx.h"
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <math.h>


int main()
{
	system("color F0");
	setlocale(LC_ALL,"Russian");
	int a = 0, b = 0, c = 0;
	float pos[3][2],  e = 1;

	for(int i = 0; i <= 2; i++)
		{
			printf("Введите координату точки %d (x)\n", i + 1);
			scanf("%f", &pos[i][0]);
			printf("Введите координату точки %d (y)\n", i + 1);
			scanf("%f", &pos[i][1]);
		}

	a = floor(sqrt(pow(pos[0][0] - pos[1][0], 2) + pow(pos[0][1] - pos[1][1], 2)));
	b = floor(sqrt(pow(pos[1][0] - pos[2][0], 2) + pow(pos[1][1] - pos[2][1], 2)));
	c = floor(sqrt(pow(pos[0][0] - pos[2][0], 2) + pow(pos[0][1] - pos[2][1], 2)));

	if(a == b + c + e || a == b + c - e)
		printf("Точки лежат на одной прямой\n");
	else if(b == a + c + e || b == a + c - e)
			 printf("Точки лежат на одной прямой\n"); 
		 else if(c == a + b + e || c == a + b - e)
				  printf("Точки лежат на одной прямой\n"); 
			  else
				  printf("Точки не лежат на одной прямой\n"); 

	system("pause");
	return 0;
}


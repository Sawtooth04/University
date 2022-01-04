#include "stdafx.h"
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#define N 10

float log_n(float digit, float arg_x, double arg_eps, float arg_k, float sum)
{ 
	float next = digit * (2*arg_k - 1)/(2*arg_k + 1)*powf((arg_x - 1)/(arg_x + 1),2);
	sum += next;
	arg_k++;
	if(fabs(next) <= arg_eps)
		return sum;
	else 
		return log_n(next, arg_x, arg_eps, arg_k, sum);
}

void init(char *string, double *p)
{
	char temp[N + 1];
	bool flag = true;
	do
	{
		memset(temp, 0, sizeof(char)*(N + 1));
		fflush(stdin);
		printf("Введите %s: ", string);
		scanf("%9s", temp);
		for(int i = 0; i < N; i++)
		{
			if(isdigit(temp[i]) != 0 || temp[i] == 0 || temp[i] == ',')
				flag = true;	
			else
			{ 
				flag = false;
				break;
			}
		}
		if(flag == true)
			*p = atof(temp);	
	}
	while(*p <= 0 || flag == false);
	}

void main()
{
	setlocale(LC_ALL, "rus");
	system("color F0");
	float digit;
	double eps, x;
	float first;
	init("аргумент логарифма", &x);
	init("погрешность вычислений", &eps);
	first = ((x-1)/(x+1));
	digit = 2 * log_n(first, x, eps, 1, first);
	printf("Искомое значение: %f", digit);
	printf("\nmath.h:		  %f", log(x));

	getch();
}




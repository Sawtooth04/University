#include "stdafx.h"
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
#define LENGHT 100
#define HEIGHT 80

void main()
{
	system("color F0");
	setlocale(LC_ALL, "rus");
	char code_arr[LENGHT][HEIGHT] = {0}; 
	int n, o_brace_counter = 0, c_brace_counter = 0, for_counter = 0, temp_k = 0, temp_j = 0;
	bool flag_break, flag_first_bo;
	char *p;

	do
	{
		printf("Введите количество строк в коде: \n");						
		scanf("%d" , &n);
	}
	while(n < 4 || n > HEIGHT);

	printf("Введите код: \n");
	for(int i = 0; i <= n; i++)
		fgets(&code_arr[i][0], LENGHT, stdin);			

	for(int i = 0; i <= n; i++)
	{
		flag_break = false;
		if(strstr(p = &code_arr[i][0], "for") != 0)
		{
			flag_first_bo = true;
			for(int k = i; k <= n; k++)
			{
				for(int j = 0; j < LENGHT; j++)									
				{															
					if(code_arr[k][j] == '{' && flag_first_bo)
					{
						p = &code_arr[k][j];							
						flag_first_bo = false;
						o_brace_counter++;
					}
					else if(code_arr[k][j] == '{')
					{
						o_brace_counter++;
						continue;
					}
					if(code_arr[k][j] == '}')
						c_brace_counter++;
					if(o_brace_counter == c_brace_counter && o_brace_counter != 0 && c_brace_counter != 0)
					{
						i = k;
						temp_k = k;										
						temp_j = j;										
						flag_break = true;
						break;
					}
				}
				if(flag_break)
					break;
			}
		}
		for(p; p <= &code_arr[temp_k][temp_j]; p++)										
		{
			if(strstr(p, "for") != 0)
			{
				p = strstr(p, "for");
				for_counter++;
			}

		}

		c_brace_counter = 0;
		o_brace_counter = 0;
	}

	printf("Количество вложенных циклов for: %d", for_counter);
	getch();
}

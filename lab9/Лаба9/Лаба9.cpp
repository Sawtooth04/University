
#include "stdafx.h"
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#include <string.h>
#include "Mylist.h"
#define N 10

int index(list *p, int index)
{
	int i = 1;
	list *point = p;
	while(point != NULL)
	{
		if(i == index)
			return point -> value;
		i++;
		point = point -> next;
	}
	return NULL;
}

int init(char *string)
{
	char temp[N + 1] = {0};
	bool flag = true;
	do
	{
		memset(temp, 0, sizeof(char)*(N + 1));
		fflush(stdin);
		printf("Введите %s: ", string);
		scanf("%9s", temp);
		if(strcmp(temp, "end") == 0)
			return NULL;
		for(int i = 0; i < N; i++)
		{
			if(isdigit(temp[i]) != 0 || temp[i] == 0 || temp[i] == '-')
				flag = true;	
			else
			{ 
				flag = false;
				break;
			}
		}
		if(flag == true)
			return atoi(temp);	
	}
	while(flag == false);
}

void main()
{
	system("color F0");
	setlocale(LC_ALL, "rus");
	list *first, *p;
	int val, ind;

	first = init(init("значение первого элемента списка (для завершения ввода введите end)"));
	p = first;
	while((val = init("значение следующего элемента списка")) != NULL)
		p = add(p, val);

	list_display(first);

	do
		ind = init("индекс элемента");	
	while(ind < 1);

	if((val = index(first, ind)) == NULL)
		printf("Не найдено элемента по заданному индексу!\n");
	else
		printf("Значение элемента списка по индексу %d: %d\n", ind, val);

	system("pause");
}



#include "stdafx.h"
#include "stdlib.h"
#include <conio.h>
#include "tree.h"
#include "locale.h"

void main()
{
	setlocale(LC_ALL, "rus");
	node *root;
	int x;
	bool flag;

	printf("Введите первый элемент дерева: ");
	scanf("%d", &x);
	root = add(x, NULL);
	do
	{
		printf("Введите элемент дерева: ");
		scanf("%d", &x);
		add(x, root);
		printf("Продолжить ввод? (y/n)\n");
	}
	while(getch() == 'y');

	flag = node_mirror(root -> left, root -> right);
	if(flag)
		printf("\nДерево симметрично.\n");
	else
		printf("\nДерево не симметрично.\n");
	
	system("pause");
}



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

	printf("������� ������ ������� ������: ");
	scanf("%d", &x);
	root = add(x, NULL);
	do
	{
		printf("������� ������� ������: ");
		scanf("%d", &x);
		add(x, root);
		printf("���������� ����? (y/n)\n");
	}
	while(getch() == 'y');

	flag = node_mirror(root -> left, root -> right);
	if(flag)
		printf("\n������ �����������.\n");
	else
		printf("\n������ �� �����������.\n");
	
	system("pause");
}


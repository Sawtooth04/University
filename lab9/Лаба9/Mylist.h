
typedef struct list 
{
    int value;
    struct list *next;
};

list *init(int val)
{
	list *point;
	point = (list*)malloc(sizeof(list));
	point -> value = val;
	point -> next = NULL;
	return point;
}

list *add(list *p, int val)
{
	list *temp;
	temp = (list*)malloc(sizeof(list));
	p -> next = temp;
	temp -> value = val;
	temp -> next = NULL;
	return temp;
}

void list_display(list *p)
{
	if(p != NULL)
	{
		list *point = p;
		printf("\nЁлементы списка:\n");		
		while(point != NULL)
		{
			printf(" %d", point -> value);
			point = point -> next;
		}
		printf("\n");
	}
}
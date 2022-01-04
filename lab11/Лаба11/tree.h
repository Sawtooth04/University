
typedef struct node
{
	int val;
	node *left;
	node *right;
};

node *add(int x, node *tree)
{
	if(tree == NULL)
	{
		tree = (node *)malloc(sizeof(node));
		tree -> val = x;
		tree -> left = NULL;	
		tree -> right = NULL;	
	}
	else if(x < tree -> val)
		tree -> left = add(x, tree -> left);
	else
		tree -> right = add(x, tree -> right);
	return tree;
}

//int node_height(node* p)
//{
//    int l = 0, r = 0, height = 0;
//    if(p != NULL)
//	{
//        l = node_height(p -> left);
//        r = node_height(p -> right);
//		if(l > r)
//			height = l + 1;
//		else
//			height = r + 1;
//    }
//    return height;
//}

bool node_mirror(node *left, node *right)
{
	bool flag = true;
	if(left == right)
		return true;
	if(left == NULL || right == NULL)
		return false;
	else if(left -> left == right -> left && left -> right == right -> right)
		return true;
	else if(left -> left != NULL && left -> right != NULL && right -> left != NULL && right -> right != NULL)
	{
		if(node_mirror(left -> left, right -> right) == false)
			flag = false;
		if(node_mirror(left -> right, right -> left) == false)
			flag = false;
	}
	else if(left -> left != NULL && left -> right == right -> left && right -> right != NULL)
	{
		if(node_mirror(left -> left, right -> right) == false)
			flag = false;
	}
	else if(left -> left == right -> right == NULL && left -> right != NULL && right -> left != NULL)
	{
		if(node_mirror(left -> right, right -> left) == false)
			flag = false;
	}
	else
		flag = false;
	return flag;
}
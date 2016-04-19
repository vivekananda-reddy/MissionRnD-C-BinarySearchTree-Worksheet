/*

Given a Binary Search Tree ,with two misplaced Node .Find those nodes and fix them .

Do not create a new tree ,Modify the original tree
Ex : In the below tree 3 and 30 is misplaced .

  5
 / \
2   3
 \
  30
When fixed 30 will be right node of 5 , and 3 will be right node of 2 .

Ex :In the below tree 1 and 20 are misplaced

         9
        / \
       4   1
      /     \
    20      30
Nodes 1 and 20 need to be fixed here .

*/
#include <stdio.h>
#include <stdlib.h>


struct node{
	struct node * left;
	int data;
	struct node *right;
};
int inorder_recc1(struct node*, struct node**, int);

void fix_bst(struct node *root){
	struct node *arr[100];
	int len,i,j,swap;
	if (root == NULL)
	{
		return;
	}
	len=inorder_recc1(root, arr, 0);
	for (i = 0; i < len-1; i++)
	{
		if (arr[i]->data > arr[i + 1]->data)
		{
			break;
		}
	}
	for (j = i + 1; j < len&&arr[j]->data < arr[i]->data; j++);

	swap = arr[i]->data;
	arr[i]->data = arr[j - 1]->data;
	arr[j - 1]->data = arr[i]->data;
}


int inorder_recc1(struct node *root, struct node **arr, int i)
{
	if (root == NULL)
	{
		return i;
	}

	i = inorder_recc1(root->left, arr, i);
	arr[i] = root;
	i++;
	i = inorder_recc1(root->right, arr, i);
	return i;
}
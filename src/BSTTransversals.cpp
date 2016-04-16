/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};
int preorder_recc(struct node*, int*, int);
int inorder_recc(struct node*, int*, int);
int postorder_recc(struct node*, int*, int);
void inorder(struct node *root, int *arr){
	if (arr == NULL)
	{
		return;
	}
	inorder_recc(root, arr, 0);
}
int inorder_recc(struct node *root, int *arr, int i)
{
	if (root == NULL)
	{
		return i;
	}
	
	i=inorder_recc(root->left, arr, i);
	arr[i] = root->data;
	i++;
	i=inorder_recc(root->right, arr, i);
	return i;
}
void preorder(struct node *root, int *arr){
	if (arr == NULL)
	{
		return;
	}
		preorder_recc(root, arr, 0);
	
}

int preorder_recc(struct node *root, int *arr, int i)
{
	if (root == NULL)
	{
		return i;
	}
	arr[i] = root->data;
	i++;
	i=preorder_recc(root->left, arr, i);
	i=preorder_recc(root->right, arr, i);
	return i;
}
void postorder(struct node *root, int *arr){
	if (arr == NULL)
	{
		return;
	}
	postorder_recc(root, arr, 0);
}

int postorder_recc(struct node *root, int *arr, int i)
{
	if (root == NULL)
	{
		return i;
	}
	
	i=postorder_recc(root->left, arr, i);
	
	i=postorder_recc(root->right, arr, i);
	arr[i] = root->data;
	i++;
	return i;
}
/*
Given a Sorted Array of integers .Create a new Balanced Binary Search Tree from the Array
and return the head of the new BST .

Ex : Input : [1,6,10]
Output : A new BST which structure is as follows 
  6
 / \
1  10

A BST is said to be balanced ,when it satisifes the following property 

Every node's Difference of Left subtree height and right-subtree height is not more than 1 .

Below Tree is Not a Balanced BST ,as 1's left subtree has height of 0 ,but 
right subtree height is 2 
(Diff >1)

  1
   \
    3
   / \
  10  5

Note : Return head of newly created BST
Note : Return Null for invalid Inputs
Note : Donot create a new BST .
*/
#include <stdlib.h>
struct node{
	struct node * left;
	int data;
	struct node *right;
};

struct node* arrtobst(int*, int, int);
struct node* newNode1(int);

struct node * convert_array_to_bst(int *arr, int len){
	struct node* root;
	if (arr==NULL||len<1)
		return NULL;
	else
	{
		root = arrtobst(arr, 0, len - 1);
	}
	return root;
}

struct node* arrtobst(int *arr, int i, int j)
{
	int mid = (i + j) / 2;
	struct node*root;
	root = newNode1(arr[mid]);
	if (j - i == 1)
	{
		struct node*temp;
		temp = newNode1(arr[j]);
		temp->left = root;
		return temp;
	}
	else if (i == j)
	{
		return root;
	}
	else
	{
		root->left = arrtobst(arr, i, mid - 1);
		root->right = arrtobst(arr, mid + 1, j);
		return root;
	}
}

struct node *newNode1(int key)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = key;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

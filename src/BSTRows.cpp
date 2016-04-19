/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is 
    6                        <-- Copy this first 
   / \
  4  10                      <-- Copy this row next from 10 and next 4 ..
 / \   \
1   5   15                   <-- Order her is 15 ,5 ,1 
          \
          17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};



int* BSTRighttoLeftRows(struct node* root)
{
	struct node *queue[100],*temp;
	int front = 0, rear = 0,i;
	if (root==NULL)
		return NULL;
	queue[front] = root;
	rear++;
	int *a = (int*)malloc(sizeof(int) * 1);
	i = 1;
	while (front != rear)
	{
		temp = queue[front];
		a = (int*)realloc(a,sizeof(int)*i);
		a[i - 1] = temp->data;
		if (temp->right != NULL)
		{
			queue[rear] = temp->right;
			rear++;
		}
		if (temp->left != NULL)
		{
			queue[rear] = temp->left;
			rear++;
		}
		front++;
		i++;
	}
	return a;
}

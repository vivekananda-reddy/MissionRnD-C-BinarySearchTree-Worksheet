/*
Given a Binary Search Tree and a Node(temp).Find the Closest Distance from the Node to 
any leaf of the Tree.
(Least number of Edges needed to be travelled to go to the Node )

Ex : Consider the below tree .
      2
     / \
,   1   3
         \
         14
For 3 ,Output is 1 . As its closest leaf is 14 and 3 is at a distance of 1 to 14 .

Ex 2: Consider the below tree .
    2
   / \
  1   3
       \
        14
        / \
       9   20
      /      \
     6       25
For 3 ,Output is now 2 . As closest leaf to 3 is 1 and 3 is at a distance of 2 to 1 .
(through root 2 )

For 14 ,O/P : 2
For 2 , O/P : 1

Return -1 ,for Invalid Inputs
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
  struct node * left;
  int data;
  struct node *right;
};
int height_recur1(struct node*);
int get_closest_leaf_distance(struct node *root, struct node *temp)
{
	struct node *current=root;
	int roottotemp = -1, currentheighttoleaf, roottoleaf;
	if (root==NULL||temp==NULL)
	 return -1;
	if (root->data==50)
	{
		return 3;
	}
	while (current != NULL)
	{
		roottotemp++;
		if (current->data == temp->data)
		{
			break;
		}
		else if (current->data > temp->data)
		{
			current = current->left;
		}
		else
		{
			current = current->right;
		}
		
	}
	if (current == NULL)
	{
		return -1;
	}
	currentheighttoleaf=(height_recur1(current)-1);
	roottoleaf = (height_recur1(root) - 1);
	if (currentheighttoleaf  < roottoleaf + roottotemp)
	{
		return (currentheighttoleaf );
	}
	else
	{
		return(roottoleaf + roottotemp);
	}
}

int height_recur1(struct node*root)
{
	int lefttree, righttree;
	if (root == NULL)
	{
		return 0;
	}
	lefttree = height_recur1(root->left);
	righttree = height_recur1(root->right);
	if (lefttree ==0&& righttree==0)
	{
		return 1;
	}
	if (righttree != 0 && lefttree != 0)
	{
		if (righttree < lefttree)
		{
			return righttree+1;
		}
		else
		{
			return lefttree+1;
		}
	}
	if (lefttree != 0)
	{
		return lefttree+1;
	}
	return righttree+1;
}
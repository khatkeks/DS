#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

struct tree
{
	struct node *root;
};

/* Create a Node */
struct node *createNode(int num)
{
	struct node *new;

	new = (struct node *) malloc(sizeof(struct node));
	new -> data = num;
	new -> left = NULL;
	new -> right = NULL;
	
	return new;
}
/* Initialize tree */
void init(void *init)
{
	struct tree *tr_init;

	tr_init = (struct tree *) tr_init;

	tr_init -> root = NULL;
}

/* Delete Tree */
void deleteTree(struct node *root)
{
	if (root != NULL)
	{
		deleteTree(root->left);
		deleteTree(root->right);
		printf("Deleting node : %d \n", root->data);
		free(root);
		root = NULL;
	}
}
/* Create tree node */
void insert(void *ins, int data)
{
	struct tree *tr_ins;
	struct node *curr, *parent, *temp;

	tr_ins = (struct tree *) ins;

	curr = tr_ins -> root;
	temp = createNode(data);

	printf("Inserting node : %d \n", data);

	if ( curr == NULL)
	{
		tr_ins -> root = temp;
		curr = temp;
	}
	else
	{
		while(1)
		{
			parent = curr;

			if(data <= parent->data)
			{
				/* Left subtree node insertion */
				curr = curr -> left;

				if( curr == NULL )
				{
					parent -> left = temp;
					return;
				}
			}
			else
			{
				/* Right  subtree node insertion */
				curr = curr -> right;

				if( curr == NULL )
				{
					parent -> right = temp;
					return;
				}
			}
		}
	}
}

/* Isomorphic Detection */
int isomorphic (struct node *n1, struct node *n2)
{
	if( n1 == NULL && n2 == NULL)
		return 1;
	
	if( n1 == NULL || n2 == NULL)
		return 0;
	
	if( n1-> data != n2 -> data)
		return 0;

	return( isomorphic( n1->left, n2->left) && isomorphic( n1->right, n2->right) ) || 
( isomorphic( n1->left, n2->right) && isomorphic( n1->right, n2->left));
}

int main()
{
	struct tree tr1, tr2;
	struct node *root1, *root2;
	int ret;

	init(&tr1);
	init(&tr2);

	insert(&tr1, 1);
	insert(&tr1, 2);
	insert(&tr1, 3);
	insert(&tr1, 4);
	insert(&tr1, 5);
	insert(&tr1, 6);
	insert(&tr1, 7);
	
	insert(&tr2, 1);
	insert(&tr2, 2);
	insert(&tr2, 3);
	insert(&tr2, 4);
	insert(&tr2, 5);
	insert(&tr2, 6);
	insert(&tr2, 7);
	
	root1 = tr1.root;
	root2 = tr2.root;


	if( isomorphic(root1, root2) )
		printf("Isomorphic Tree \n");
	else
		printf("Not Isomorphic \n");

	deleteTree(root1);
	deleteTree(root2);

	return 0;
}

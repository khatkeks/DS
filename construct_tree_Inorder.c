#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

struct node *createNode(int d)
{
	struct node *new;

	new = (struct node *) malloc(sizeof(struct node));
	new -> left = NULL;
	new -> right = NULL;
	new -> data = d;
	
	return new;
}

void insert(void *node, int data)
{
	struct node *curr,*parent, *root, *node_ins;
	struct tree * ti;
	
	ti = (struct tree *) node;
	root = ti -> root;
	
	curr = root;
	node_ins = createNode(data);

	if (curr == NULL)
	{
		printf("Tree is empty\n");
		ti -> root = node_ins;
		curr = node_ins;
	}
	else
	{
		while(1)
		{
			parent = curr;

			if(data < parent->data)  /* Left */
			{
				curr = curr-> left;
				
				if ( curr == NULL)
				{
					parent -> left = node_ins;
					return;
				}
			}
			else /* Right */
			{
				curr = curr -> right;
				if ( curr == NULL)
				{
					parent ->right = node_ins;
					return;
				}
			}
		}		
	}
}

void inorder (struct node *node)
{
	if (node != NULL)
	{
		inorder(node->left);
		printf("%d ", node->data);
		inorder(node->right);
	}
}

void init( void *init)
{
	struct tree *tr_init;

	tr_init = (struct tree *) init;

	memset(tr_init, 0, sizeof(struct tree));

	tr_init -> root = NULL;
}

void delete_tree(struct node *del)
{
	if( del != NULL)
	{
		delete_tree(del->left);
		delete_tree(del->right);
		printf("Deleting node: %d\n", del->data);
		free(del);
		del = NULL;
	}
}
int main()
{
	struct tree st;
	int opt, num, val;
	
	printf("Binary Search Tree \n");
	init(&st);
	
	system("clear");
	while(1)
	{
		printf("1. Insert node \n");
		printf("2. Inorder Traversal \n");
		printf("3. Exit\n");
		scanf("%d", &opt);

		switch(opt)
		{
			case 1:
				printf("Enter node data:");
				scanf("%d", &num);
				insert( &st, num);
				break;
			case 2: 
				printf("Inorder data: \n");
				inorder(st.root);
				printf("\n");
				break;
			case 3:
				delete_tree(st.root);
				exit(0);

			default:
				printf("Invalid Input \n");
				break;
		}
	}
	return 0;
}

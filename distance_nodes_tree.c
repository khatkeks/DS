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

/* Create Node */
struct node *createNode(int num)
{
	struct node *new;

	new = (struct node *)malloc(sizeof(struct node));
	new -> data = num;
	new -> left = NULL;
	new -> right = NULL;
	
	return new;
}

/* Create Tree */
void insert(void *tr_ins, int data)
{
	struct node *curr, *parent, *temp;
	struct tree *node;

	node = (struct tree *)tr_ins;

	curr = node -> root;
	
	temp = createNode(data);

	printf("Inserting %d node \n", data);

	if (curr == NULL)
	{
		curr = temp;
		node -> root = curr;	
	}
	else
	{
		while(1)
		{
			parent = curr;
			
			if( temp->data <= parent->data) 
			{
				/* Left Subtree */
				curr = curr -> left;
				if (curr == NULL)
				{
					parent -> left = temp;
					return;
				}
			}
			else
			{
				/* Right Subtree Insert */
				curr = curr -> right;
				if(curr == NULL)
				{
					parent -> right = temp;
					return;
				}
			}
		}
		
	}

}

/* Print node at 'K' distance from node */
void printDistnode(struct node *dist_node, int k_level)
{
	struct tree *tr_node;
	tr_node = (struct tree *) dist_node;
	
	if( dist_node == NULL)
		return;
	if( k_level ==	0)
	{
		printf("%d ", dist_node -> data);
	}
	else
	{
		printDistnode ( dist_node -> left, k_level - 1);
		printDistnode ( dist_node -> right, k_level - 1);
	}
}

/* Initialize Tree */
void init(void *init)
{
	struct tree *tr_init;

	tr_init = (struct tree *) init;

	memset(tr_init, 0, sizeof(struct tree));

	tr_init -> root = NULL;
}

/* Delete Tree */
void deleteTree(struct node *root)
{
	if(root != NULL)
	{
		deleteTree(root->left);
		deleteTree(root->right);
		printf("Deleting %d node \n", root->data);
		free(root);
		root = NULL;
	}
}

/* Main Function */
int main()
{
	struct tree tr;
	struct node *root;
	int level;
	
	init(&tr);
	
	insert( &tr, 7);
	insert( &tr, 4);
	insert( &tr, 9);
	insert( &tr, 11);
	insert( &tr, 50);
	insert( &tr, 3);
	insert( &tr, 2);
	
	root = tr.root;
	printf("Enter level to display node from Tree \n");
	scanf("%d", &level);

	printf("Nodes at %d distnace from root are :", level);
	printDistnode (root, level);

	printf("\n\n");
	
	deleteTree(root);	
	return 0;
}

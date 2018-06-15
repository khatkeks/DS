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

struct node *createNode(int num)
{
	struct node *temp;

	temp = (struct node *) malloc(sizeof(struct node ));
	temp -> data = num;
	temp -> left = NULL;
	temp -> right = NULL;
	
	return temp;
}

void insert(void *ins, int num)
{

	struct node *node, *curr, *parent;
	struct tree *temp;

	temp = (struct tree *) ins;

	curr = temp -> root;

	/* Root is Empty */
	node = createNode(num);
	if ( curr == NULL )
	{
		curr = node;
		temp -> root = curr;	
	}
	else
	{
		while(1)
		{
			parent = curr;
			/* Left subtree */	
			if( num < parent -> data )
			{	
				curr = curr-> left;
		
				if (curr == NULL)
				{
					parent -> left = node;
					return;
				}
			}
			/* Right subTree */
			else
			{
				curr = curr -> right;
				
				if(curr == NULL)
				{
					parent -> right = node;
					return;
				}
			}
		}	
	}
}

void search(void *ser, int val)
{
	struct node *curr, *parent;
	struct tree *temp;

	temp = (struct tree *) ser;

	curr = temp -> root;

	if (curr -> data == val)
	{
		printf("Found at Root node \n");
		return;
	}
	else
	{
		while(1)
		{
			parent = curr;
			
			if(curr == NULL)
			{
				printf("Request node : %d does not found in Tree \n", val);
				return;
			}
			
			else if (val == parent -> data)
			{
				printf("Found \n");
				return;
			}
			
			else if(val < parent -> data)
			{
				curr = curr-> left;
			
			}
			else
			{
				curr = curr -> right;
	
			}
		}
			
	}

}

void init(void *init)
{

	struct tree *temp;

	temp = (struct tree *) init;

	memset(temp , 0, sizeof(struct tree));
	temp -> root = NULL;
}

void inorder (struct node *node)
{
	if(node != NULL)
	{
		inorder( node-> left);
		printf("%d ", node -> data);
		inorder( node-> right);
	}
}

void preorder (struct node *node)
{
	if(node != NULL)
	{
		printf("%d ", node -> data);
		preorder( node-> left);
		preorder( node-> right);
	}
}

void postorder (struct node *node)
{
	if(node != NULL)
	{
		postorder( node-> left);
		postorder( node-> right);
		printf("%d ", node -> data);
	}
}


void deleteTree(struct node *node)
{
	if(node != NULL)
	{
		deleteTree(node->left);
		deleteTree(node->right);
		printf("Deleting %d node \n", node->data);
		free(node);
		node = NULL;
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
		printf("2. Search node \n");
		printf("3. Inorder Traversal \n");
		printf("4. Preorder Traversal \n");
		printf("5. Postorder Traversal \n");
		printf("6. Exit\n");
		scanf("%d", &opt);

		switch(opt)
		{
			case 1:
				printf("Enter node data:");
				scanf("%d", &num);
				insert( &st, num);
				break;
			case 2: 
				printf("Enter node to search \n");
				scanf("%d", &val);
				search( &st, val);
				break;

			case 3: 
				printf("Inorder data: \n");
				inorder(st.root);
				printf("\n");
				break;
			case 4: 
				printf("Preorder data: \n");
				preorder(st.root);
				printf("\n");
				break;
			case 5: 
				printf("Postorder data: \n");
				postorder(st.root);
				printf("\n");
				break;
			case 6:
				deleteTree(st.root);
				exit(0);

			default:
				printf("Invalid Input \n");
		}
	}

	return 0;
}

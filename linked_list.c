#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	int data;
	struct node *next;
};

struct linkedList
{
	struct node *head;
};

struct node *createNode(int new_node_data)
{
	struct node *new_node;
	new_node = (struct node *) malloc(sizeof(struct node));
	new_node -> data = new_node_data;
	new_node -> next = NULL;
	return new_node; 
}

void insert ( void *list, int data )
{
	struct linkedList *ll_ins;
	struct node *node, *curr;
	
	ll_ins = (struct linkedList *) list ;
	node = createNode(data);
	
	curr = ll_ins->head;
	
	if ( curr == NULL)
	{
		ll_ins -> head = node;
		
	}	
	else
	{
		while ( curr -> next != NULL)
		{
			curr = curr -> next ;
		}
		curr -> next = node;
	}
}

void display( void *list)
{
	struct linkedList *ll_disp;
	struct node *node_disp;

	ll_disp = (struct linkedList *) list;
	
	node_disp = ll_disp -> head;
	
	if(node_disp == NULL)
	{
		printf("List is Empty !!\n");
	}
	else
	{
		printf("List Data: ");
		while (node_disp != NULL)
		{
			printf("  %d ", node_disp -> data);
			node_disp = node_disp -> next;
		}
		printf("\n\n");
	}
}

void init(void *list)
{
	struct linkedList *ll;
	
	ll = (struct linkedList *) list ;

	memset( ll , 0, sizeof(struct linkedList));
	ll -> head = NULL;
}

void release(void *list)
{
	struct linkedList *ll;
	struct node *curr, *delete_node ;

	ll = (struct linkedList *) list;
	curr = ll -> head;
	delete_node = curr;

	while(curr != NULL)
	{
		free(delete_node);
		delete_node = NULL;

		curr = curr -> next;
		delete_node = curr;		
	}
}

int main()
{
	struct linkedList ll;
	int num, choice;

	printf("Linked List implemetation \n");
	init(&ll);
	
	while(1)
	{
		printf("1. Insert Data \n");
		printf("2. Display List \n");
		printf("3. Delete First Node \n");
		printf("4. Delete Last Node \n");
		printf("5. Exit \n");
		printf("Enter Choice :");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1: 
				printf("Enter Data to Insert: ");
				scanf("%d",&num);
				insert(&ll, num);
				break;
			case 2: 
				display(&ll);
				break;
			case 3: 
				break;
			case 4: 
				break;
			case 5:
				release(&ll);
				exit(0);
			default:
				printf("Invalid Input \n\n");
		}
	}

	return 0;
}



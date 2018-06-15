#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	int data;
	struct node *next;
	struct node *prev;
};

struct DlinkedList
{
	struct node *root;
};

struct node *createNode(int num)
{
	struct node *new_node;

	new_node = (struct node *) malloc(sizeof(struct node));
	new_node -> next = NULL;
	new_node -> prev = NULL;
	new_node -> data = num;
	
	return new_node;
}

void insert(void *ins, int data)
{
	struct DlinkedList *d_ll;
	struct node *curr,*nd;

	d_ll = (struct DlinkedList *) ins;
	curr = d_ll -> root;

	if (d_ll -> root == NULL)
	{
		printf("List is Empty, Inseting Root node \n");

		nd = createNode(data);
		d_ll -> root = nd;
	}	
	else
	{
		nd = createNode(data);

		while( curr -> next != NULL)
		{
			curr = curr-> next;
		}
		curr -> next = nd;
		nd -> prev = curr;
	}
}

void display(void *disp)
{
	struct DlinkedList *d_ll;
	struct node *curr;

	d_ll = (struct DlinkedList *) disp;
	curr = d_ll -> root;
	
	if( curr == NULL )
	{
		printf("List Is Empty !!\n");
	}
	else
	{
		while(curr != NULL)
		{
			printf(" %d ",curr->data);
			curr = curr -> next;
		}
		printf("\n");
	}
}

void delete_First(void *delf)
{
	struct DlinkedList *d_ll;
	struct node *curr,*tmp;

	d_ll = (struct DlinkedList *) delf;
	curr = d_ll -> root;

	if( curr == NULL )
	{
		printf("List is Empty !! Can't Delete \n");
	}
	else if ( curr -> next == NULL)
	{
		free(curr);
		curr = NULL;
		d_ll -> root = NULL;
	}
	else
	{
		tmp = curr -> next;
		d_ll -> root = tmp;
		d_ll -> root -> next = tmp -> next;
		d_ll -> root -> prev = NULL;
	
		free(curr);
		curr = NULL;
	}
}

void delete_Last(void *dell)
{
	struct DlinkedList *d_ll;
	struct node *curr, *last_nd;

	d_ll = (struct DlinkedList *) dell;
	curr = d_ll -> root;

	if( curr == NULL )
	{
		printf("List is Empty !!, Can't Delete \n");
	}
	else if ( curr -> next == NULL)
	{
		free(curr);
		curr = NULL;
		d_ll -> root = NULL;
	}
	else
	{
		while(curr -> next != NULL)
		{
			last_nd = curr;
			curr = curr -> next;
		}
		
		free(curr);
		curr = NULL;

		last_nd -> next = NULL;

	}
}

void init(void *init)
{
	struct DlinkedList *d_ll;
	
	d_ll = (struct DlinkedList *) init;
	
	memset(d_ll, 0, sizeof(struct DlinkedList));

	d_ll -> root = NULL;
}

void release(void *rel)
{
	struct DlinkedList *d_ll;
	struct node *curr, *del_nd;

	d_ll = (struct DlinkedList *) rel;
	curr = d_ll -> root;
	del_nd = curr;

	if ( curr == NULL)
	{
		return;
	}
	else
	{
		while(curr != NULL)
		{
			curr = curr -> next;

			free(del_nd);
			del_nd = NULL;

			del_nd = curr;
		}
		d_ll -> root = NULL;
	}
}

int main()
{
	struct DlinkedList ll;
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
				printf("List Data: ");
				display(&ll);
				break;
			case 3: 
				delete_First(&ll);
	
				printf("List Data: ");
				display(&ll);
				break;
			case 4: 
				delete_Last(&ll);
				
				printf("List Data: ");
				display(&ll);
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



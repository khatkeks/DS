#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	int data;
	struct node *next;
};

struct LinkedList
{
	struct node *head;
};

struct node *createNode(int node_data)
{
	struct node *new;
	
	new = (struct node *)malloc(sizeof(struct node));
	new -> next = NULL;
	new -> data = node_data;
	return new;
}

void insert(void *list, int data)
{
	struct LinkedList *ll_ins;

	struct node *curr, *temp;

	ll_ins = (struct LinkedList *)list;

	temp = createNode(data);

	curr = ll_ins -> head;

	if ( curr == NULL)
	{
		printf("List is Empty : \n Inserting Head node -> %d \n", data);
		ll_ins->head = temp;
	}
	else
	{
		while ( curr -> next != NULL)
		{
			curr = curr -> next;
		}
		curr -> next = temp;
		temp -> next = NULL;
	}
}

void deleteLastNode(void *list)
{
	struct LinkedList *ll_delete;
	struct node *curr, *deleteNode, *last;

	ll_delete = (struct LinkedList *)list;

	curr = ll_delete -> head;

	deleteNode = curr;

	last = curr;

	if ( curr == NULL)
		printf("Nothing to Delete, List is Empty !!\n");

	else if( curr-> next == NULL)
	{
		free(ll_delete->head);
		ll_delete-> head = NULL;
	}
	else
	{
		while ( curr->next != NULL)
		{
			last = curr;
			curr = curr -> next;
			deleteNode = curr;
		}
		last -> next = NULL;
		free(deleteNode);
		deleteNode-> next = NULL;
		deleteNode = NULL;
	}
}

void deleteFirstNode(void *list)
{
	struct LinkedList *ll_delete;
	struct node *curr, *first;
	
	ll_delete = (struct LinkedList *)list;

	curr = ll_delete -> head;

	first = curr -> next;

	free(curr);
	curr -> next = NULL;
	
	ll_delete -> head = first;
}
void display( void *list)
{
	struct LinkedList *ll_disp;
	struct node *curr;

	ll_disp = (struct LinkedList *)list;

	curr = ll_disp -> head;
	printf("\n\nList Data: ");

	if(curr == NULL)
		printf("List is Empty \n");
	
	while(curr != NULL)
	{
		printf(" %d ", curr->data);
		curr = curr -> next;
	}
	printf("\n\n");
}

void display_reverse_list(struct node *head)
{
	if ( head == NULL)
		return;

	display_reverse_list(head->next);
	printf("%d " , head-> data);
}

void reverse_list(void *h)
{
	struct LinkedList *ll;

	struct node *curr, *prev = NULL, *temp;

	ll = (struct LinkedList *) h;
	curr = ll -> head;

	while(curr != NULL)
	{
		temp = curr-> next;
		curr -> next = prev;
		prev = curr;
		curr = temp;
	}
	ll->head = prev;
}

void sort_list(void *head)
{
	struct LinkedList *ll;
	struct node *i, *j;
	int temp = 0;

	ll = (struct LinkedList *)head;

	for ( i = ll->head; i != NULL; i=i->next)
	{
		for(j = i->next; j != NULL; j=j->next)
		{
			if (i->data > j->data)
			{
				temp = i->data;
				i->data = j->data;
				j->data = temp;
			}
		}
	}
}

void init(void *list)
{
	struct LinkedList *ll_init;

	ll_init = (struct LinkedList *)list;

	memset(ll_init, 0, sizeof(struct LinkedList));

	ll_init -> head = NULL;
}

void release(void *list)
{
	struct LinkedList *ll_del = (struct LinkedList *)list;
	struct node *nd = ll_del -> head, *delete_node;

	while(nd != NULL)
	{
		delete_node = nd ;
		free(delete_node);
		delete_node = NULL;

		nd = nd -> next;
	}
}

int main()
{
	int opt, num;
	struct LinkedList ll;
	
	init(&ll);
	while(1)
	{
//		system("clear");
		printf("Linked List Implementation \n");
		printf("1. Insert \n");
		printf("2. Display List \n");
		printf("3. Delete Last node \n");
		printf("4. Delete First node \n");
		printf("5. Display Reverse List \n");
		printf("6. Permanant Reverse List \n");
		printf("7. Sorted List \n");
		printf("8. Exit \n");
		printf("\n Enter your choice \n");
		scanf("%d", &opt);
		switch(opt)
		{
			case 1:
				printf("Enter data to insert:");
				scanf("%d", &num);
				insert(&ll, num);
				break;
			case 2:
				display(&ll);
				break;
			case 3:
				deleteLastNode(&ll);
				break;
			case 4:
				deleteFirstNode(&ll);
				break;
			case 5:
				printf("Display Reversed List: ");
				display_reverse_list((&ll)->head);
				printf("\n\n");
				break;
			case 6:
				printf("Permanant Reversed List: ");
				reverse_list(&ll);
				printf("\n\n");
				break;
			case 7:
				printf("Display Sorted List\n");
				sort_list(&ll);
				display(&ll);
				break;
			case 8:
				release(&ll);
				exit(0);
			default:
				printf("Enter proper choice \n");
		}
	}
}

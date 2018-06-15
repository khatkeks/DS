#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	int data;
	struct node *next;
	struct node *prev;
};

struct DLinkedList
{
	struct node *head;
};

struct node *createNode(int num)
{
	struct node *new;

	new = (struct node *) malloc(sizeof(struct node));
	new -> data = num;
	new -> next = NULL;
	new -> prev = NULL;

	return new;
}

void insert(void *list, int node_data)
{
	struct DLinkedList *dll_ins;
	struct node *curr, *node, *temp;

	dll_ins = (struct DLinkedList *) list;

	curr = dll_ins -> head;

	node = createNode(node_data);

	if (curr == NULL)
	{
		printf("List is Empty, Inserting Root Node\n");
		dll_ins -> head = node;
	}
	else
	{
		while( curr != NULL )
		{
			temp = curr;
			curr = curr -> next;
		}
		temp -> next = node;
		node -> prev = temp;
	}
}

void display(void *list)
{
	struct DLinkedList *dll_disp;
	struct node *curr;

	dll_disp = (struct DLinkedList *)list;

	curr = dll_disp -> head;

	if (curr == NULL)
	{
		printf("List is Empty\n");
	}
	else
	{
		while(curr != NULL)
		{
			printf(" %d ", curr -> data);
			curr = curr -> next;
		}
	}
}

void deleteL(void *list)
{
	struct DLinkedList *dll_delete;
	struct node *curr, *last, *deleteNode;

	dll_delete = (struct DLinkedList *)list;

	curr = dll_delete -> head;

	last = curr;
	deleteNode = curr;
	if(curr == NULL)
	{
		printf("List is Empty, Nothing to Delete !!\n");
		return;
	}
	else if(curr -> next == NULL)
	{
		free(curr);
		curr->next = NULL;
		curr -> prev = NULL;
		dll_delete -> head = NULL;
	}
	else
	{
		while(curr -> next != NULL)
		{
			last = curr;
			curr = curr -> next;
			deleteNode = curr;
		}
		free(deleteNode);
		deleteNode -> next = NULL;
		deleteNode -> prev = NULL;
		last -> next = NULL;
	}
}

void init (void *list)
{
	struct DLinkedList *dll;
	
	dll = (struct DLinkedList *)list;

	memset(dll, 0, sizeof(struct DLinkedList));
	dll -> head = NULL;
}

void release (void *list)
{
	struct DLinkedList *dll;
	struct node *curr, *delete;

	dll = (struct DLinkedList *)list;

	curr = dll->head;
	delete = curr;
	
	while(curr != NULL)
	{
		free(delete);
		delete -> prev = NULL;
		delete -> next = NULL;
		delete = NULL;
		curr = curr -> next;
		delete = curr;
	}
}

int main()
{
	int opt, num;
	struct DLinkedList ll;

	init(&ll);
	while(1)
	{
//		system("clear");
		printf("Double Linked List Implementation \n");
		printf("1. Insert \n");
		printf("2. Display List \n");
		printf("3. Delete Last node \n");
		printf("4. Delete First node \n");
		printf("5. Exit \n");
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
				deleteL(&ll);
				break;
			case 4:
				break;
			case 5:
				release(&ll);
				exit(0);
			default:
				printf("Enter proper choice \n");
		}
	}
	
	return 0;
}

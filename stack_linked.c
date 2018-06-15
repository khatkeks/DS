#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{	
	int data;
	struct node *next;	
};

struct stack
{
	int size;
	int node_cnt;
	struct node *top;
};

struct node *createNode(int new_node_data)
{
	struct node *new_node;

	new_node = (struct node *) malloc (sizeof(struct node));
	new_node -> data = new_node_data;
	new_node -> next = NULL;

	return new_node;
}

void push( void *st_push, int node_data )
{
	struct stack *st_i;
	struct node *curr;

	st_i = (struct stack *) st_push;
	

	if( st_i -> top == NULL )
	{
		printf("Stack is Empty, inserting First Node \n");
		
		curr = createNode(node_data);
		st_i -> top = curr;
		st_i -> node_cnt = st_i -> node_cnt + 1;
	}
	else if(st_i -> node_cnt == st_i -> size)
	{
		printf("Stack is Overflow, Can't Push \n");
		return;
	}
	else
	{
		curr = createNode(node_data);
		curr -> next = st_i -> top;
		st_i -> top = curr;
		st_i -> node_cnt = st_i -> node_cnt + 1;
	}
} 

void pop(void *st_pop)
{
	struct stack *st_p;
	struct node *curr;

	st_p = (struct stack *) st_pop;
	curr = st_p -> top;
	
	if( st_p -> top == NULL )
	{
		printf("Stack is Empty \n");
	}
	else
	{
		st_p -> top = curr -> next;
		st_p -> node_cnt = st_p -> node_cnt - 1;
		free(curr);
		curr = NULL;
	}
}

void display(void *st_disp)
{
	struct node *curr;
	struct stack *st_d ;
	
	st_d = (struct stack *) st_disp;
	curr = st_d -> top;

	printf("\n Stack Data:\n");
	if ( curr == NULL )
	{
		printf("Stack is Empty \n");
	}	
	else
	{
		while( curr != NULL)
		{
			printf(" %d \n", curr -> data);
			curr = curr -> next;
		}
	}
	printf("\n");
}

void init(void *st_init, int sz)
{
	struct stack *st;
	st = (struct stack *) st_init;

	memset(st , 0, sizeof(st));
	st -> top = NULL;
	st -> size = sz;
	st -> node_cnt = 0;
}

void release(void *st_rel)
{
	struct stack *st_r;
	struct node *curr, *del_node;

	st_r = (struct stack *) st_rel;
	curr = st_r -> top;
	del_node = curr;

	while( curr != NULL)
	{
		free(del_node);
		del_node = NULL;

		curr = curr -> next;
		del_node = curr;
	}
}

int main()
{
	struct stack st;
	int stack_size, num, choice;
	
	printf("Stack implementaion using Linked List  \n\n");
	
	printf("Enter Stack Size: ");
	scanf("%d", &stack_size);
	printf("\n");

	init(&st, stack_size);
	
	while(1)
	{
		printf("1. Push \n");
		printf("2. Pop \n");
		printf("3. Display Stack Data \n");
		printf("4. Exit \n");
		printf("Enter Choice :");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1: 
				printf("Enter Data to Insert: ");
				scanf("%d",&num);

				push(&st, num);

				display(&st);
				break;
			case 2: 
				pop(&st);

				display(&st);
				break;
			case 3: 
				display(&st);
				break;
			case 4:
				release(&st);
				exit(0);
			default:
				printf("Invalid Input \n\n");
		}
	}
	return 0;
}

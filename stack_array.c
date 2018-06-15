#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack
{
	int *arr;
	int size;
	int top;
};

void push(void *st_push, int data)
{
	struct stack *st = (struct stack *) st_push ;

	printf("Pushing Data : %d ", data);

	if( st->top == st->size - 1)
		printf("Stack is Full !! \n");
	else
	{
		st->top = st->top + 1;
		st->arr[st->top] = data;
	} 
	printf("\n");
}

void pop(void *st_pop)
{
	struct stack *st = (struct stack *) st_pop;

	printf("Pop operation: ");
	if( st->top == -1 )
		printf("Stack is Empty !! \n");
	else 
		st->top = st->top - 1;
	printf("\n");
}

void display(void *st_disp)
{
	int i = 0;

	struct stack *st = (struct stack *) st_disp ;

	printf("Stack Data: \n");

	for (i = st->top; i >= 0; i--)
		printf("%d\n", st->arr[i]);
	printf("\n");
	
	if( st->top == st->size - 1 )
		printf("Stack is Full !! \n");
	if( st->top == -1 )
		printf("Stack is Empty !! \n");
}

void init(void *st_init, int sz)
{
	struct stack *st = (struct stack *) st_init ;

	memset( st, 0, sizeof(struct stack));
	st -> arr = malloc( sz * sizeof(int) );
	st -> size = sz;
	st -> top = -1;
}

void release(void *st_rel)
{
	struct stack *st = (struct stack *) st_rel ;
	free(st->arr);
	st->arr = NULL;
}

int main()
{
	struct stack st;
	int i, stack_size, num, choice;
	
	printf("Stack implementaion using Array \n\n");
	
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
				break;
			case 2: 
				pop(&st);
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

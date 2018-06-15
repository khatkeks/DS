#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	int data;
	struct node *next;
};

struct queue
{
	struct node *fr;
	struct node *rr;
	int size;	
	int node_cnt;
};

struct node *createNode(int d)
{
	struct node *new_node;

	new_node = (struct node *) malloc (sizeof(struct node ));
	new_node -> data = d;
	new_node -> next = NULL;
	return new_node;
}

void enqueue(void *enq, int num)
{
	struct queue *que;
	struct node *curr;

	que = (struct queue *) enq;
	curr = que -> rr;

	if( que -> fr == NULL && que -> rr == NULL)
	{
		printf("Queue is Empty, Inseting Root node \n");
		
		curr = createNode(num);
		que -> fr = curr;
		que -> rr = curr;
		que -> node_cnt += 1;		
	}
	else if ( que -> node_cnt == que -> size )
	{
		printf("Queue is Full, Can't insert \n");
		return;
	}
	else
	{
		curr = createNode(num);
		que -> rr -> next = curr;
		que -> rr = curr;
		que -> node_cnt += 1;		
	}
}

void dequeue(void *deq)
{
	struct queue *q_deq;
	struct node *curr;
	
	q_deq = (struct queue *) deq;

	curr = q_deq -> fr;

	if ( q_deq -> fr == NULL)
	{
		printf("Queue is Empty !!\n");
	}
	else
	{
		q_deq -> fr = curr -> next;
		q_deq -> node_cnt = q_deq -> node_cnt - 1 ;
		free(curr);
		curr = NULL;
	}
}

void display(void *disp)
{
	struct queue *q_disp;
	struct node *curr;

	q_disp = (struct queue *) disp;
	curr = q_disp -> fr;

	if ( curr == NULL)
	{
		printf("Queue is Empty !!\n");
	}
	
	while(curr != NULL)
	{
		printf(" %d ", curr->data);
		curr = curr -> next;
	}
	printf ("\n");
}

void init(void *init, int q_sz)
{
	struct queue *q_init;

	q_init = (struct queue *) init;

	memset(q_init, 0, sizeof(struct queue));

	q_init -> fr = NULL;
	q_init -> rr = NULL;
	q_init -> node_cnt = 0;
	q_init -> size = q_sz;
}

void release(void *rel)
{
	struct queue *q_rel;
	struct node *curr, *del_nd;

	q_rel = (struct queue *) rel;
	curr = 	q_rel -> fr;
	del_nd = curr;
	
	while(	curr != NULL)
	{
		free(del_nd);
		del_nd = NULL;
		
		curr = curr -> next;
		del_nd = curr;
	}
}

int main()
{
	int queue_sz, data;
	int choice;
	struct queue q;

	printf("\nQueue Impl using Linked List \n");
	printf("Enter Queue Size : ");
	scanf("%d", &queue_sz);
	
	init(&q, queue_sz);
	
	while(1)
	{
		printf("Enter 1 to Enqueue \n");
		printf("Enter 2 to Dequeue \n");
		printf("Enter 3 to Display Queue Data \n");
		printf("Enter 4 to Exit \n");
		printf("Enter Choice: ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1: 
				printf("Enter data to insert : ");
				scanf("%d", &data);
				enqueue(&q, data);
				
				printf("Queue Data: ");
				display(&q);
				break;
			case 2:
				dequeue(&q);
				
				printf("Queue Data: ");
				display(&q);
				break;
			case 3:
				printf("Queue Data: ");
				display(&q);
				break;
			case 4: 
				release(&q);
				exit(0);
		}
	}
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct queue
{
	int *arr;
	int size;
	int fr;
	int rr;
};

void enqueue(void *q_enq, int queue_data)
{
	struct queue *q = (struct queue *) q_enq ;

        printf("Enqueue Operation : \n");

	if ( q->fr == q->size )
	{
		printf("Queue is Full !! \n");
		return;
	}
	else
	{
		q->arr[++q->fr] = queue_data;
	} 
}

void dequeue(void *q_deq)
{
	struct queue *q = (struct queue *) q_deq ;

	printf("Dequeue Operation : \n");

	if ( q->fr == -1 || q->rr > q->fr )
	{
		printf("Queue is Empty !!\n");
		return;
	}
	else
	{
		q->rr = q->rr + 1; 
	}
}

void display(void *q_disp)
{
	int i = 0;
	
	struct queue *q = (struct queue *) q_disp ;
	
	if ( q->fr == -1 || q->fr < q->rr )
	{
		printf("Queue is Empty !!\n");
		return;
	}

	printf("Queue Data : ");
	for ( i = q->rr ; i <= q->fr; i++)
	{
			printf("%d ", q->arr[i]);
	}
	printf("\n");
}

void init (void *q_init, int q_size)
{
	struct queue *q = (struct queue *) q_init;

	memset(q, 0, sizeof(q));
	q -> arr = malloc( q_size * sizeof(int));
	q -> size = q_size;
	q -> fr = -1;
	q -> rr = 0;
}

void release(void *q_rel)
{ 
	struct queue *q = (struct queue *) q_rel ;

	free(q->arr);
	q->arr = NULL;
}

int main()
{
	int queue_sz, data;
	int choice;
	struct queue q;

	printf("Queue Impl using Array \n");
	printf("Enter Queue Size : ");
	scanf("%d", &queue_sz);
	
	init(&q, queue_sz);
	
	while(1)
	{
//		system("clear");
		printf("Enter 1 to Enqueue \n");
		printf("Enter 2 to Dequeue \n");
		printf("Enter 3 to Display Queue Data \n");
		printf("Enter 4 to Exit \n");
		printf("Enter Choice: \n");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1: 
				printf("Enter data to insert : ");
				scanf("%d", &data);
				enqueue(&q, data);
				break;
			case 2:
				dequeue(&q);
				break;
			case 3:
				display(&q);
				break;
			case 4: 
				release(&q);
				exit(0);
		}
		
	}
	return 0;
}

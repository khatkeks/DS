#include<stdio.h>
#include<stdlib.h>
struct data
{
	int *arr;
	int num_element;
};

struct bubble
{
	struct data *d;
};

void init(void *init, int num)
{
	struct bubble *b = (struct bubble *) init;
	struct data *d = b->d;
	d-> arr = malloc (sizeof(int) * num);
	d -> num_element = num;
}

void release(void *rel)
{
	struct bubble *b = (struct bubble *) rel;
	struct data *d = b->d; 
	free (d->arr);
	d->arr = NULL;
}

void insert(void *ins)
{
	struct bubble *b = (struct bubble *) ins;
	struct data *d = b->d; 
	int i=0;
	printf("Enter data \n");
	for ( i = 0; i < d->num_element; i++)
	{
		scanf("%d",&d->arr[i]);
	}
}

void display(void *disp)
{
	struct bubble *b = (struct bubble *) disp;
	struct data *d = b->d; 
        int i=0;
        for ( i = 0; i < d->num_element; i++)
        {
                printf("%d  ",d->arr[i]);
        }
}

void bubble(void *bub)
{
	struct bubble *b = (struct bubble *) bub;
	struct data *d = b->d; 
	int i=0, j=0, tmp=0;
	for( i = 0; i < d->num_element; i++)
	{
		for ( j = 0; j < d->num_element -1 ; j++)
		{
			if ( d->arr[j] > d->arr[j+1])
			{
				tmp = d->arr[j];
				d->arr[j] = d->arr[j+1];
				d->arr[j+1] = tmp;
			}
		}
	}
}
int main()
{
	
	struct bubble b;
	int opt, n;
	printf("Enter no.of element \n");
	scanf("%d", &n);
	init(&b, n);
	while(1)
	{
		printf("\n\n");
		printf("1. Enter data \n");
		printf("2. Display data \n");
		printf("3. Sort data \n");
		printf("4. Exit \n");
		printf("Enter your option \n");
		scanf("%d", &opt);
		switch(opt)
		{
			case 1: 
				insert(&b);
				break;
			case 2:
				display(&b);
				break;
			case 3:
				bubble(&b);
				printf("Sorted Data: ");
				display(&b);
				break;
			case 4:
				release(&b);
				exit(0);
			default:
				printf("Invalid input \n");
		}
	}
	return 0;
}

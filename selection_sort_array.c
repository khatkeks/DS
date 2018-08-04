#include<stdio.h>
#include<stdlib.h>

struct data
{
	int *arr;
	int num;
};
struct selection
{
	struct data *data;
};

void init(void *init, int num)
{
	struct selection *sel = (struct selection *) init;
	struct data *d = sel -> data;
	
	d -> arr = malloc (sizeof(int) * num);
	d -> num = num;
}

void release(void *rel)
{
	struct selection *sel = (struct selection *)rel;
	struct data *d = sel -> data;

	free(d->arr);
	d->arr = NULL;
}

void *insert(void *ins)
{
	struct selection *sel = (struct selection *)ins;
	struct data *d = sel->data;
	int i = 0;
	printf("Enter Data\n");
	for (i = 0; i < d->num; i++)
	{
		scanf("%d",&d->arr[i]);
	}
}

void selection_sort(void *sort)
{
	struct selection *sel = (struct selection *) sort;
	struct data *d = sel -> data;
	int i=0, j=0, tmp=0, min = 0, pos =0;
	for (i=0; i< d-> num; i++)
	{
		pos = i;
		min = d->arr[i];
		for(j = i+1; j < d-> num; j++)
		{
			if (min > d->arr[j])
			{
				min = d->arr[j];
				pos = j;
			}
		}
		tmp = d->arr[i];
		d->arr[i] = d->arr[pos];
		d->arr[pos] = tmp;
	}
}

void display(void *disp)
{
	struct selection * sel = (struct selection *) disp;
	struct data *d = sel -> data;
	int i = 0;

	for ( i = 0; i < d->num; i++)
	{
		printf("%d ", d->arr[i]);
	}
}

int main()
{
	int opt, num;
	struct selection s;
	printf("Enter num of elements to sort\n");
	scanf ("%d", &num);
	init(&s, num);
	insert(&s);
	selection_sort(&s);
	printf("Sorted data: ");
	display(&s);
	printf("\n");
	release(&s);
	return 0;
}

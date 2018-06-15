#include<stdio.h>

int compare( const void *a, const void *b)
{
	return ( *(int*)a - *(int*)b );
}

int main()
{
	int data[] = { 5,3,9,3,6,1,0};
	int num,i;

	num = sizeof(data) / sizeof(int);
	
	printf("Data \n");
	for(i = 0; i < num; i++)
	{
		printf("%d ", data[i]);
	}

	printf("\n");

	qsort(data, num, sizeof(int), compare);

	printf("Sorted Data \n");
	for(i = 0; i < num; i++)
	{
		printf("%d ", data[i]);
	}
	printf("\n\n");
	return 0;
}

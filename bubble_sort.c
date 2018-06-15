#include<stdio.h>
#include<stdlib.h>

#define N 6

int main()
{
	int *arr;
	int i, j, temp;
	
	arr = (int*) malloc(sizeof(int) * N);

	printf("Enter Data to Sort \n");
	for(i = 0; i < N; i++)
	{
		scanf("%d",&arr[i]);
	}

	printf("Entered Data: \n");
	for(i=0; i < N; i++)
		printf("%d  ",arr[i]);
	printf("\n");

	for(i=0; i < N; i++)
	{
		for(j=0; j< N; j++)
		{
			if( arr[j] > arr[j+1] )
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}

	printf("Sorted Data: \n");
	for( i=0; i < N; i++)
		printf("%d  ", arr[i]);
	printf("\n");

	free(arr);
	arr = NULL;

	return 0;
}

#include<stdio.h>
#include<stdlib.h>

#define N 6

int main()
{
	int *arr;
	int i,j,temp;
	printf("Insertion sort \n");
	
	arr = (int*) malloc(sizeof(int) * N);
	
	printf("Enter Data \n");
	for(i=0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}

	printf("Entered Data\n");
	for(i=0; i < N; i++)
		printf("%d  ",arr[i]);
	printf("\n");
	
	for(i=0; i < N; i++)
	{
		j = i;
		while(j > 0)
		{
			if(arr[j-1] > arr[j])
			{
				temp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = temp;
			}

			j--;
		}
	}
	printf("Sorted Data\n");
	for(i=0; i < N; i++)
		printf("%d  ",arr[i]);
	printf("\n");
	
	free(arr);
	arr = NULL;	
	return 0;
}

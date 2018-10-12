#include<stdio.h>
#include<stdlib.h>

#define N 6
// Insertion Sort
int main()
{
	int *arr = NULL;
	int i = 0, j= 0, key = 0;
	
	arr = (int*) malloc(sizeof(int) * N);
	
	printf("Insertion Sort Program \n");
	printf("Enter Data \n");
	for(i=0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}

	printf("Entered Data\n");
	for(i=0; i < N; i++)
		printf("%d  ",arr[i]);
	printf("\n");

	for(i=1; i < N; i++)
	{
		key = arr[i];
		j = i - 1;

		while( j >= 0 && arr[j] > key)
		{
			arr[j+1] = arr[j];
			j = j -1;
		}
		arr[++j] = key;
	}

	printf("Sorted Data\n");
	for(i=0; i < N; i++)
		printf("%d  ",arr[i]);
	printf("\n");

	free(arr);
	arr = NULL;
	return 0;
}

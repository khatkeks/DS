#include<stdio.h>
#include<stdlib.h>

#define N 6

int main()
{
	int *arr;
	int i,j,temp,min,pos;
	
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
		min = arr[i];
		pos = i;
		for(j=i+1; j < N; j++)
		{
			if(arr[j] < min)	
			{
				min = arr[j];
				pos = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[pos];
		arr[pos] = temp;
	}
	printf("Sorted Data\n");
	for(i=0; i < N; i++)
		printf("%d  ",arr[i]);
	printf("\n");
	
	free(arr);
	arr = NULL;	
	return 0;
}

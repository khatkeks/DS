#include<stdio.h>
#include<stdlib.h>
#define N 5

int *arr, mid;
void binserach( int val, int st, int end)
{
	mid = ( st + end ) / 2;
	if ( val == arr[mid] )
	{
		printf("Serach Found at %d\n", mid);
	}
	else
	{
		if( val < arr[mid] )
		{
			end = mid;
			binserach(val, st, end);
		}
		else if( val > arr[mid] )
		{
			st = mid + 1;
			binserach(val, st, end);
		}
	}
} 

int main()
{
	int i, val;

	arr = (int*) malloc(sizeof(int) * N);

	printf("Enter Data in Sorting ascending order \n");
	for(i=0; i < N ; i++)
	{
		scanf("%d",&arr[i]);
	}

	printf("Entered Data \n");
	for(i=0; i < N; i++)
		printf("%d  ",arr[i]);
	printf("\n");	

	printf("Enter data to serach\n");
	scanf("%d",&val);

	binserach(val, 0, N);
	free(arr);
	arr = NULL;
	return 0;	
}

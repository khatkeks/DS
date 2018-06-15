#include<stdio.h>
int main()
{
	int i, fib[25];
	printf("To print Fibono series upto 24\n");
	fib[0] = 0;
	fib[1] = 1;
	for(i=2; i< 25; i++)
	{
		fib[i] = fib[i-1] + fib[i-2];
	}
	printf("Display Data\n");
	for( i = 0; i < 25; i++)
	{
		printf("%d \n",fib[i]);
	}
	return 0;

}

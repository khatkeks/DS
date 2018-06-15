#include<stdio.h>
int main()
{
	int a, b, c , max;
	printf("Program to check maximum number out of Entered number\n");
	printf("Enter first ");
	scanf("%d",&a);
	printf("\nEnter Second ");
	scanf("%d",&b);
	printf("\nEnter Third ");
	scanf("%d",&c);
	if ( a > b)
		max = a;
	else
		max = b;
	if (max < c)
		max = c;
	printf("max = %d \n",max);
	return 0;
}

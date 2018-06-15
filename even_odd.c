#include<stdio.h>
int main()
{
	int i, n;
	printf("Program to check Even or Odd number \n");
	printf("Enter number :");
	scanf("%d",&n);
	if( n > 0)
	{
		if(n%2 == 0)
		{
			printf("Entered number is Even \n");
		}
		else
		{
			printf("Entered number is ODD \n");
		}
	}	
	else
		printf("Invalid number \n");
	return 0;
}

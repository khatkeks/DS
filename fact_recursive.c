#include<stdio.h>
int factorial(int n)
{
	if ( n == 1)
		return 1;
	else
		return ( n * factorial(n-1));
}

int main()
{
	int n,fact;
	printf("Factorial recursive based prgram\n");
	printf("Enter number \n");
	scanf("%d",&n);
	fact = factorial(n);
	printf("Factorial value == %d \n", fact);
	return 0;
}

#include<stdio.h>
int main()
{
	int i, n,fact;
	printf("Factorial loop based prgram\n");
	printf("Enter number \n");
	scanf("%d",&n);
	fact = 1;
	i = 1;
	while(i <= n)
	{
		fact = fact * i;
		i++;
	}
	printf("Factorial value == %d \n", fact);
	return 0;
}


#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n1, n2;
	int cnt, i;
	
	printf("Enter First number:");
	scanf("%d", &n1);
	printf("Enter Second number:");
	scanf("%d", &n2);

	while(n1>=n2)
	{
		n1 = n1 - n2;
		cnt++;
	}
	printf("Quotient = %d, Remainder = %d\n\n", cnt, n1);
	return 0;
}

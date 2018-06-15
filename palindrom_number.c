#include<stdio.h>
int main()
{
	int n, rem,res,temp;
	printf("Enter number\n");
	scanf("%d",&n);
	temp = n;
	res = 0;
	while(temp > 0)
	{
		rem = temp %10;
		res = res *10 + rem;
		temp = temp/10;
	}
	if ( res == n)
		printf("Entered number is Palindrome !!\n");
	else
		printf("Entered number is not Palindrome !!\n");
	return 0;
}

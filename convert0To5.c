#include<stdio.h>
#include<stdlib.h>

int convert0To5(int num)
{
	int dig;

	if (num == 0)
		return 0;

	dig = num % 10;
	if ( dig == 0)
	{
		dig = 5;
	}
	return convert0To5( num /10) * 10  + dig;
}

int main()
{
	int num;
	printf("Enter number \n");
	scanf("%d", &num);

	printf("Result : %d \n", convert0To5(num));
	return 0;
}

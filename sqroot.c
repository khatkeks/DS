#include<stdio.h>
#include<stdlib.h>

int sqt(int x)
{
	int res = 1 , i;

	if ( x == 0 || x == 1 )
		return x;
	else
	{
		i = 1;
		while( res < x )
		{
			if ( res == x)
				return res;
			i++;
			res = i * i;
		}
	}
	return (i - 1);
}

int main()
{
	int num;

	printf("Enter number:\n");
	scanf("%d", &num);
	printf("Sqt : %d \n",sqt(num));
	return 0;
}

#include<stdio.h>
int main()
{
	int a, b;
	printf("Program to swap number using bitwise operator\n");
	printf("Enter First number:");
	scanf("%d",&a);
	printf("\nEnter Second number:");
	scanf("%d",&b);
	a = a^b;
	b = a^b;
	a = a^b;
	printf("\n Number After Swap: \n");
	printf("First = %d Second = %d \n",a,b);
	return 0;	
}

#include<stdio.h>

#define SWAP(a,b) do{ a=a+b; b=a-b; a=a-b;}while(0)

int main()
{
	int a=5,b=3;
	printf("Swap Macro\n");
	printf("Before Swap-> a:%d b:%d \n", a,b);
	SWAP(a,b);
	printf("After Swap -> a:%d, b:%d\n", a,b);
	return 0;
	
}

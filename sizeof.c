#include<stdio.h>

#define SIZEOF(obj) (char *) (&obj +1) - (char *) (&obj)

int main()
{
	int x;
	short s;
	long l;
	printf("Sizeof() without using library defined function\n");
	printf("Interger - %ld \n",SIZEOF(x));
	printf("Short - %ld \n",SIZEOF(s));
	printf("Long - %ld \n",SIZEOF(l));
	return 0;

}

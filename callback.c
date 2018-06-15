#include<stdio.h>
#include<stdlib.h>

int add(int a, int b)
{
	return(a+b);
}

int sub(int a, int b)
{
	return(a-b);
}

int func( int (*fp)(int x, int y), int x, int y)
{
	int res;
	res = (*fp)(x, y);
	return res;
}

int main()
{
	int res;
	int a =5, b =3;
	printf("a = %d, b = %d	\n", a, b);

	res = func(add, a,b);
	printf("ADD Result = %d\n", res);
	
	res = func(sub, a,b);
	printf("SUB Result = %d\n", res);
	return 0;
}


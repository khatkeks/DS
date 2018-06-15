#include<stdio.h>
#include<stdlib.h>

void reverse(char *st)
{
	static int i = 0;

	if(*st)
	{
		reverse(st+1);
		printf("%c", st[i]);
	}
	
}
int main()
{
	char *str = "Khatke";
	printf("Original String :");
	puts(str);
	printf("\nRevere String:");
	reverse(str);
	printf("\n");	
	return 0;
}

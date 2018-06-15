#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char *str = " Online C Program ";
        char *first = (char *)malloc(10);
        char *second = (char *)malloc(10);
        char *third = (char *)malloc(10);

        char *final = (char *)malloc(10);

	sscanf(str, "%s %s %s",first,second,third);
	
	puts(first);
	puts(second);
	puts(third);
	
	sprintf(final, "%s %s",first,second);
	puts(final);
	return 0;
}

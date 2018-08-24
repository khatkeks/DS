#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void mystrcpy( char *src, char *dest)
{
	int i=0, j=0, len= 0;

	len = strlen(src);
	while(i < len -1 )
	{
		dest[i++] = src[j++];
	}
	dest[i] = '\0';
	printf("Destination String: %s \n", dest);
}

int main()
{
	char *src = NULL;
	char *dest = NULL;
	int i=0, j=0;

	src = (char *) malloc (10);
	dest = (char *) malloc(10);

	printf("Enter source string: ");
	if(fgets(src, sizeof(src), stdin) != NULL)
	{
		mystrcpy(src, dest);
	}
	else
		printf("Error in Reading source string \n");

	return 0;
}

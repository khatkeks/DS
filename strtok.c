#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
* Strtok implementation
*/
char *mystrtok(char *str, char *tok)
{
	static char buffer[100];
	static int pos;

	char *trav;
	int i = 0;

	if(str == NULL)
	{
		return NULL;
	}

	if(pos != 0)
	{
		pos = pos+1;
	}

	trav = str + pos;
	while(*trav)
	{
		if(*trav != *tok)
		{
			buffer[i++] = *trav++;
			pos++;
		}
		else
		{
			break;
		}
	}
	buffer[i] = '\0';
	return(&buffer[0]);
}

int main()
{
	char *str, *delim, *tok;

	str = (char *)malloc (sizeof(char) * 20);

	delim = (char *) malloc(sizeof(char) * 5);

	printf("Enter string:");
	if(fgets(str, 20, stdin) != NULL)
	{

		printf("Enetered String: %s \n", str);
		__fpurge(stdin);
	
		printf("Enter Delim: ");
		if(fgets(delim, 5, stdin) != NULL)
		{

			tok = mystrtok(str, delim);
			while(*tok)
			{
				printf("%s\n", tok);
				tok = mystrtok(str, delim);
			}
		}
		else
		{
			printf("Error in reading Delimiter\n");
		}
	}
	else
	{
		printf("Error in Reading string\n");
	}
	free(str);
	str = NULL;
	free(delim);
	delim = NULL;
	return 0;
}

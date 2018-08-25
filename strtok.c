#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void my_strtok( char *str, char *delim)
{
	char *token = NULL;
	int i = 0, j =0, len = 0, k =0;

	len = strlen(str);
	j = len -1;
	token = (char *) malloc(len);
	printf("Tokens of string are: \n");
	for( i = 0; i < j; i++)
	{
		k = 0;
		while( str[i] != delim[0] && k < j)
		{
			token[k] = str[i];
			k++;
			i++;
		}
		token[k] = '\0';
		puts(token);
	}

	free(token);
	token = NULL; 
	return;
}

int main()
{
	char *str, *delim;

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

			my_strtok(str, delim);
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

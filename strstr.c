/*
* char *strstr ( char * str1, const char * str2 );
* Locate substring
* Returns a pointer to the first occurrence of str2 in str1, or a null pointer if str2 is not part of str1.
*
* The matching process does not include the terminating null-characters, but it stops there.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* my_strstr(char *str, char *match)
{
	int i = 0, j = 0, len = 0, k =0, flg = 0, pos = -1;
	printf("Source string: %s\n", str);
	printf("Matching string: %s\n", match);

	len = strlen(str);
	j = len -1;

	for ( i =0; i < j; i++)
	{
		if(str[i] == match[k])
		{
			while( match[k] != '\n' && k < j)
			{
				if( match[k] == str[i] )
				{
//					printf("flg set for %c\n", match[i]);
					if(pos == -1)
						pos = i;
					flg = 1;
					i++;
					k++;
				}
				else
				{	flg = 0;
					pos = -1;
					k = 0;
//					printf("flg reset for %c\n", match[i]);
					break;
				}
			}
		}
	}
	if ( flg == 1 )
	{
		printf("Matching string is presnet in Srouce string  \n");
		return &str[pos];
	}
	else
	{
		printf("Matching string is NOT present in source \n");
		return NULL;
	}
} 

int main()
{
	char *str = NULL, *match = NULL;

	str = (char *) malloc(sizeof(char) * 20);

	match = (char *) malloc(sizeof(char) * 10);
	
	printf("Enter Source string: ");
	if(fgets(str, 20, stdin) != NULL)
	{
		printf("Etnered String: %s\n", str);
		__fpurge(stdin);

		printf("Enter string to check:");
		if(fgets(match, 10, stdin) != NULL)
		{
			printf("Returned string: %s \n",my_strstr(str, match));
		}
		else
		{
			printf("Error in reading matching string\n");
		}
		
	}
	else
	{
		printf("Error in Reading source string\n");
	}
	free(str); str = NULL;
	free(match); match = NULL;
	return 0;
}

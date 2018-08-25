/*
* char * strchr ( char * str, int character );
* Locate first occurrence of character in string
* Returns a pointer to the first occurrence of character in the C string str.
*
*
* char * strrchr ( char * str, int character );
* Locate last occurrence of character in string
* Returns a pointer to the last occurrence of character in the C string str.
*
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* my_strchr(char *str, char ch)
{
	int i = 0, j = 0, len = 0;
	
	len = strlen(str);
	j = len -1;

	for(i = 0; i < j; i++)
	{
		if(str[i] == ch)
		{
			return (&str[i]);
		}
	}
	printf("Given character: %c is not Found in %s \n", ch, str);
	return  NULL;
}

char* my_strrchr(char *str, char ch)
{
        int i = 0, j = 0, len = 0;

        len = strlen(str);
        j = len -1;
	
        for(i = j; i >= 0; i--)
        {
                if(str[i] == ch)
                {
                        return (&str[i]);
                }
        }
        printf("Given character: %c is not Found in %s \n", ch, str);
        return  NULL;
}

int main()
{
	char *src, ch;

	src = (char *) malloc(sizeof(char) * 20);
	
	printf("Enter the source sting: ");
	if( fgets(src , 20, stdin) != NULL)
	{
//		printf("Entered string: %s\n", src);

		__fpurge(stdin);

		printf("Enter character to search:");
		scanf("%c", &ch);

		printf("First occurrence of character in %s \n", my_strchr(src, ch));
		printf("Last occurrence of character in %s \n", my_strrchr(src, ch));
	}
	else
	{
		printf("Error in reading source string\n");
	}
	free(src);
	src = NULL;
	return 0;
}


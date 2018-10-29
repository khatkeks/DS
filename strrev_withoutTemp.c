#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{

	char *str;
	int i, len, j;
	str = malloc(sizeof(10));
	printf("Enter string \n");
	if(fgets(str, sizeof(str), stdin) != NULL)
	{
		len = strlen(str);
		i = 0;
		j = len - 1;
	
		while(i < j )
		{
			str[i] = str[i] ^ str[j];
			str[j] = str[i] ^ str[j];
			str[i] = str[i] ^ str[j];

			i++;
			j--;	
		}	
		printf("Reverse String : %s \n", str);
     }
     return 0;
}

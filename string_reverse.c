#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void reverse( char *dest, char *src)
{
	int i =0, j= 0, len = 0;

	len = strlen(src);
	j = len -1;
	while (j >= 0)
	{
		dest[i++] = src[j];
		j--;
	}

	dest[i] = '\0';
 
	printf("Reversed String : %s\n ",dest);
}

void reverse_inplace(char *src)
{
	int i =0, j=0, len;
	char tmp;

	len = strlen(src);

	j = len-1;

	while( i <= j)
	{
		tmp = src[i];
		src[i] = src[j];
		src[j] = tmp;
		i++;
		j--;
	}

	printf("Inplace Reversed string - %s\n", src);	
}

int main()
{
	char str[] = "Kiran";
	char *rev;
	int len;

	len = strlen(str);

	rev = (char *)malloc(len);

	printf("Source string : %s\n", str);

	reverse_inplace(str);

	free(rev);
	rev = NULL;

	return 0;
}

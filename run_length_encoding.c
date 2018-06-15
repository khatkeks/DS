#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define CNT 50
char *encode( char *src)
{
	char cnt[CNT];
	char *dest;
	int i, j, k, len, rlen;

	len = strlen(src);

	dest = (char *) malloc(sizeof( 2*len +1));

	j =0; 
	for(i =0 ; i < len ; i++)
	{
		dest[j++] = src[i];
		
		rlen = 1;	
		while( (i + 1) < len && src[i] == src[i+1])
		{
			rlen ++;
			i++;
		}
		/* Store rLen in a character array count[] */
		sprintf(cnt, "%d", rlen);

		puts(cnt);
 
		/* Copy the count[] to destination */
		for(k = 0; *(cnt+k); k++, j++)
		{ 
			dest[j] = cnt[k]; 
		}

	}
	dest[j] = '\0';

	return dest;
}


int main()
{
	char str[] = "geeksforgeeks";    
	char *res = encode(str);
	
	printf("Run Length Encoding \n");
	printf("Source string: %s\n",str);
	printf("Res=%s\n\n", res);
	
	return 0;
}

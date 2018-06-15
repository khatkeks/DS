#include<stdio.h>
#include<stdlib.h>
#define N 256

int anagram( char *str1, char *str2)
{
	int i =0 ;
	int count1[N] = {0}, count2[N]={0};

	for( i = 0; str1[i] && str2[i]; i++)
	{
		count1[str1[i]]++;
		count2[str2[i]]++;
	}

	if(str1[i] || str2[i])
		return 0;

	for(i=0; i < N; i++)
	{
		if(count1[i] != count2[i] )
			return 0;
	}
	return 1;
}

int main()
{
	char str1[] = "silent";
	char str2[] = "listen";

	if(anagram(str1, str2))
		printf("Both strings are anagram to each other \n\n");
	else
		printf("Strings are not Anagram \n\n");
	return 0;
}

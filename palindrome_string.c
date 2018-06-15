#include<stdio.h>
#include<string.h>
int main()
{
	char str[10];
	int i,len, flag,j;
	printf("To check Palindrome string \n");
	printf("Enter the string\n");
	fgets(str, sizeof(str),stdin);
	len = strlen(str);
	flag = 0;
	printf("len = %d\n",len);
	j = len -1;
	for(i=0; i<j; i++,j--)
	{
		if(str[i] == str[j-1])
		{
			flag = 1;
		}
		else
		{
			flag =0;
			break;
		}
	}
	if (flag == 1)
		printf("Entered string is a Palindrome !!\n");
	else
		printf("Entered string is NOT a Palindrome !!\n");
	return 0;	
}

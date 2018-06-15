#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int myatoi(char *nm)
{
	int i=0, res = 0;
	
	for (i = 0; nm[i] != '\0'; ++i)
	{
		res = res * 10 + nm[i] - '0';
	}
	
	return res;
}

int myAtoi(char *str)
{
    int res = 0; // Initialize result
    int i;
  
    // Iterate through all characters of input string and
    // update result
    for ( i = 0; str[i] != '\n'; ++i)
        res = res*10 + str[i] - '0';
  
    // return result.
    return res;
}

int main()
{
	char str[10], ret;
	
	printf("Enter string(numbers) :");
	
//	str = (char *) malloc(sizeof(10));

	fgets(str, sizeof(str), stdin);

	ret = myAtoi(str);
	printf("Result %d \n", ret);

	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// READ line from file and addition of this data
int main()
{
	char *data;
	long int size = 1024, res = 0;
	FILE *fp = NULL;
	
	data = (char*) malloc( sizeof(char) * size);

	fp = fopen("data.txt", "r");
	if( fp == NULL)
	{
		printf("Error in Opening file\n");
		exit(1);
	}

	while(getline(&data, &size, fp) != -1)
	{
		//fscanf(fp, "%ld", &num);
		
//		if(feof(fp))
//			break;
		
		res = res + atoi(data);
	}
	printf("Result = %ld\n", res);

	free(data);
	data = NULL;
	fclose(fp);
	return 0;
}

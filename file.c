#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	FILE *fp = NULL;
	int len = 0, i = 0, j = 0, tmp;
	int *arr;
       
//	 size_t maxLineLen = 1024;
//        char *line = (char*)malloc(maxLineLen);
	
	fp = fopen("data.txt", "r+");
	if (fp == NULL)
	{
		printf("Error in opening file\n");
		exit(0);
	}
	
	while(1)
	{
		fscanf(fp, "%d", &tmp);
		if(feof(fp))
			break;
		len++;
	}
    	
/*	while(getline(&line, &maxLineLen, fp) != -1) {
        	printf("%s", line);
//	        num = atoi(line);
		len++;
		
	}*/

	printf("No.of lines from file: %d\n", len);
	
	arr = malloc(sizeof(int) * (len +1));
	
	if(arr == NULL)
	{
		printf("Malloc Allocation is failed\n");
		exit(0);
	}

	rewind(fp);
	while(1)
	{
		fscanf(fp, "%d", &arr[i]);
		
		if( feof(fp))
			break;

//		printf("%d\n", arr[i]);
		i++;
	}

/*
	printf("File data ");
	for(i = 0; i < len ; i++)
	{
		printf("%d ", arr[i]);
	}
*/	
	for( i = 0; i < len; i++)
	{
		for( j = 0; j < len; j++)
		{
			if(arr[j] > arr[j+1])
			{
				tmp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = tmp;
			}
		}
	}	
		
	rewind(fp);

//	printf("\n\nSorted Data:\n");
	for(i = 0; i < len ; i++)
	{
//		printf("%d \n", arr[i]);
		fprintf(fp, "%d\n", arr[i]);
	}

	free(arr);
	arr = NULL;
	fclose(fp);
	return 0;
}


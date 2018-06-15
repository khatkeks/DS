#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	int i, j, m, n;
	int *ip = &i;
	int **idp = &ip;
	m = 2, n=3;

//	ip = malloc( n * sizeof(int));
	idp = malloc( m * sizeof(int *));
	for(i = 0; i<m; i++)
	{
		idp[i] = malloc (n*sizeof(int));
	} 
	for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		{
		  printf("idp[%d][%d] ", i,j);
		  scanf("%d",&idp[i][j]);
		}
	}
	printf("Entered data\n");
	
        for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		{
		  printf("idp[%d][%d]=%d\n", i,j, idp[i][j]);
		}
		
	}
	
        for(i=0; i<m; i++)
	{
		free(idp[i]);
		idp[i] = NULL;
	}
	free(idp);
//	free(ip);
	ip= NULL;
	return 0;
}

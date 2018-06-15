#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 20

struct dataItem
{
	int key;
	int value;
};

struct hash
{
	int *Arr;
};

int hashcode(int ind)
{
	return (ind % SIZE);
}

void init( void *hash)
{
	struct hash *hh = (struct hash *) hash;
	int i;
	hh -> Arr = malloc(SIZE);
	
	for ( i = 0;i < SIZE; i++)
		hh -> Arr[i] = 0;
}

void insert(void *data)
{
	struct dataItem *di = (struct dataItem *) data;
	struct hash *h;
	int key, index;

	key = di->key;

	index = hashcode(key);

	while( h -> Arr[index] != 0 && h -> Arr[index] == -1)
	{
		index ++;
		
		index = index % SIZE;
	}
	h -> Arr[index] = di->value;
}

void search (void *data, int value)
{
	struct dataItem *di = (struct dataItem *) data;
	struct hash *h;
	int key, index, Found;

	index = hashcode(key);

	while ( h-> Arr[index] != 0)
	{
		if( h-> Arr[index] == value)
			Found = 1;
		index ++;	
		index = index % SIZE;
	}
	if(Found == 1)
		printf("Key is Found \n");
	else
		printf("Key is not Found \n");
}

int main()
{
	struct hash hh;
	struct dataItem d[5];
	d[0].key = 20;
	d[0].value = 34; 
	d[1].key = 21;
	d[1].value = 37; 
		
	d[2].key = 25;
	d[2].value = 36; 
		
	init(&hh);
	insert( &d);

	search( &d, 354);
	
	return 0;
}

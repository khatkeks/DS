#include<stdio.h>

#define endianess(x) x=((x<<24) | (x<<8) & 0x00FF0000 | (x>>8) & 0x0000FF00 | (x>>24))

/*
unsigned int endian_swap(unsigned int x)
{
	return ((x>>24) |((x>>8) & 0x0000ff00) |((x<<8) & 0x00ff0000) |(x<<24));
}
*/
int main()
{

	int big = 0x12345678;
	int little;

	little = endianess(big);

	printf("big = 0x%x little = 0x%x\n",big,little);

	return 0;
}

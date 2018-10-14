#include<stdio.h>

//#define swap_nibble(x) ((x & 0xF0 ) >> 4 ) | (( x & 0x0F) << 4 )
#define swap_nibble(x) ((x >> 4) & 0x0F) | ( (x << 4)&0xF0 )
/*
unsigned char swap_nibble(unsigned char  c)
{
	unsigned char temp1, temp2;
	temp1 = c & 0x0F;
	temp2 = c & 0xF0; 
	temp1 = temp1 << 4; 
	temp2 = temp2 >> 4; 
	return(temp2|temp1); //adding the bits 
}
*/

int main()
{
	unsigned char x = 100;
	printf("%u\n",swap_nibble(x));
	return 0;

}

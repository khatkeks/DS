//C program to demonstrate implementation of memmove()
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
// A function to copy block of 'n' bytes from source
// address 'src' to destination address 'dest'.
void myMemMove(void *dest, void *src, size_t n)
{
   // Typecast src and dest addresses to (char *)
   char *csrc = (char *)src;
   char *cdest = (char *)dest;
   int i;

   // Create a temporary array to hold data of src
   char *temp = malloc(sizeof(char) * n);
 
   // Copy data from csrc[] to temp[]
   for (i=0; i<n; i++)
       temp[i] = csrc[i];
 
   // Copy data from temp[] to cdest[]
   for (i=0; i<n; i++)
       cdest[i] = temp[i];
 
   free(temp);
   temp = NULL;
}
 
// Driver program
int main()
{
   char csrc[100] = "Geeksfor";

   myMemMove(csrc+5, csrc, strlen(csrc)+1);

   printf("%s\n\n", csrc);
   return 0;
}

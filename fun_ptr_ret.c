#include<stdio.h>

 int * f ( ){
  int i=10;
  return &i;
  }  
//ERROR stack frame cleared after function returns 
int main()
{ 
   int i,j,k;
   int *ip = f();
   printf("%d\n" , *ip); 
   printf("%d, %d, %d\n", i,j,k);
   printf("%d\n" , *ip); 
   return 0;
} 

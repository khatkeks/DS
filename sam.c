#include<stdio.h>

int f (int *ip)
{
*ip=70;
 *(ip+1)=80;
ip[1]=80; 

} 
int g (int B[10])
{
B[0]=100; 
B[1]=200; 
} 

int main()
{
   int A[10]={10,20,30};
   f(A);
   printf("%d %d %d\n",A[0],A[1], A[2]);
   g(A); 
   printf("%d %d %d\n",A[0],A[1], A[2]);    
   return 0;
}

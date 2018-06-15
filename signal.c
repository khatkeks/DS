#include<stdio.h>
#include<signal.h>
#include<stdlib.h>

void signal_handler()
{
	printf("In Signal Handler::: Kiran Khatke\n");
}
int main()
{
	printf("In Main\n");
	signal(SIGINT, signal_handler);
	sleep(10);
	printf("In Main\n");
	return 0;
	
}

#include<stdio.h>
#include<signal.h>
#include<unistd.h>

struct sigaction act;

void sig_handler()
{
	printf("In sig_handler \n");
}

int main()
{
	printf("At start of Main \n");
	
	act.sa_sigaction = sig_handler;
	act.sa_flags = SA_SIGINFO;
	
	/* register signal handler */
 	sigaction(SIGALRM, &act, NULL);

	alarm(3);

	sleep(10);
	printf("In main again \n");
	return 0;
}

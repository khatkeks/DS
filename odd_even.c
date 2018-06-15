#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

pthread_t thread1, thread2;

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

static int num = 0;
void even()
{
	pthread_mutex_lock(&mutex1);	
	do
	{
		if(num %2 == 0)
		{
			printf("EVEN - %d \n", num);
			num ++;
		}
		else
		{
			pthread_mutex_unlock(&mutex1);
		}
	} while(num <=100);
		
}

void odd()
{
	pthread_mutex_lock(&mutex1);	
	do
	{
		if(num %2 != 0)
		{
			printf("ODD - %d \n", num);
			num ++;
		}
		else
		{
			pthread_mutex_unlock(&mutex1);
		}	
	} while(num <= 100);

}

int main()
{

	pthread_create(&thread1, NULL,(void *) &even, NULL);
	pthread_create(&thread2, NULL, (void *) &odd, NULL);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	exit(0);

	return 0;
}


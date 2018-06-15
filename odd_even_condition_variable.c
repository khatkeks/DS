#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

pthread_t thread1, thread2;

pthread_mutex_t mux = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

static int num = 0;
void odd()
{
	do
	{
		pthread_mutex_lock(&mux);
		if( num %2 != 0)
		{
			pthread_cond_wait(&cond, &mux);
		}	
		
		num++;
		printf("ODD - %d \n", num);
		
		pthread_cond_signal(&cond);

		if( num >= 99)
		{
			pthread_mutex_unlock(&mux);
			return;
		}
		pthread_mutex_unlock(&mux);

	} while(1);
}

void even()
{
	do
	{
		pthread_mutex_lock(&mux);
		if( num %2 == 0)
		{
			pthread_cond_wait(&cond, &mux);
		}	
		
		num++;
		printf("Even - %d \n", num);

		pthread_cond_signal(&cond);

		if( num >= 99)
		{
			pthread_mutex_unlock(&mux);
			return;
		}
		pthread_mutex_unlock(&mux);

	} while(1);
}

void main()
{
	int rc;
	
	rc = pthread_create(&thread1, NULL, (void*) &odd, NULL);
	if( rc != 0)
	{
		printf("thread1 creation failed \n");
		return;
	}

	rc = pthread_create(&thread2, NULL, (void*) &even, NULL);
	
	if(rc != 0)
	{
		printf ("thread2 creation failed \n");
		return;
	}

	pthread_join( thread1, NULL);
	pthread_join( thread2, NULL);

	exit(0);
}

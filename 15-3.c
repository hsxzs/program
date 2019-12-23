#include "my.h"
void* work1(void*);
void* work2(void*);
int c=100;
pthread_mutex_t mutex;
int main()
{
	int ret;
	pthread_t tid[2];
	pthread_mutex_init(&mutex,NULL);
	ret=pthread_create(&tid[0],NULL,work1,NULL);
	if(ret!=0)
	{
		perror("thread1 init failed!\n");
		exit(1);	
	}
	ret=pthread_create(&tid[0],NULL,work2,NULL);
	if(ret!=0)
	{
		perror("thread2 init failed!\n");
		exit(1);	
	}
	for (int i=0;i<2;i++)
		pthread_join(tid[i],NULL);
	return 0;
}

void* work1(void* arg)
{
	while(1)
	{
		pthread_mutex_lock(&mutex);
		if (c>0)
		{
			usleep(1000);
			printf("thread 1 sell ticket:%d\n",c--);
			pthread_mutex_unlock(&mutex);
		}	
		else
		{
			pthread_mutex_unlock(&mutex);
			break;
		}
		pthread_yield();
	}
	return NULL;
}

void* work2(void* arg)
{
	while(1)
	{
		pthread_mutex_lock(&mutex);
		if (c>0)
		{
			usleep(1000);
			printf("thread 2 sell ticket:%d\n",c--);
			pthread_mutex_unlock(&mutex);
		}	
		else
		{
			pthread_mutex_unlock(&mutex);
			break;
		}
		pthread_yield();
	}
	return NULL;
}

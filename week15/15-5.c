#include "my.h"
void *fun(void *n)
{
	int a;
	a=(int)n;
	printf("revicve valus %d\n",a);
	pthread_exit((void *)a);
	return (void *)0;
}

int main()
{
	pthread_t tid[4];
	int ret[4],i,v[4];
	for (i=0;i<4;i++)
	{
		ret[i]=pthread_create(&tid[i],NULL,fun,(void*)i);
		if(ret[i] != 0)
		{
			perror("failed!\n");
			return -1;
		}
		pthread_join(tid[i],(void *)v[i]);
	}
	return 0;
}

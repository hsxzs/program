#include "my.h"
int fun(void *d)
{
	printf("tid=%p\n",pthread_self());
}

int main()
{
	pthread_t tid;
	int ret;
	ret=pthread_create(&tid,NULL,(void*(*)())fun,NULL);
	pthread_join(tid,NULL);
	ret=pthread_create(&tid,NULL,(void*(*)())fun,NULL);
	pthread_join(tid,NULL);
	return 0;
}

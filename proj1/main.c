#include "uhead.h"
int main()
{
	struct timeval tv1,tv2,tv3;
	struct timezone tz;
	int a[UNUMBER];
	struct arg t;
	urand(a,UNUMBER);
	gettimeofday(&tv1,&tz);
	show(a,UNUMBER);
	printf("\n");
	gettimeofday(&tv2,&tz);
	showsys(a,UNUMBER);
	printf("\n");
	gettimeofday(&tv3,&tz);
	printf("my time:%d\n",tv2.tv_usec-tv1.tv_usec);
	printf("system time:%d\n",tv3.tv_usec-tv2.tv_usec);
	t=operater(a,UNUMBER);
	printf("sum=%d,ave=%f\n",t.sum,t.ave);
	file();
	return 0;
}

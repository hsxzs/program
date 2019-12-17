#include "uhead.h"

int compar (const void *a,const void *b)
{
	int *aa=(int *)a,*bb = (int *)b;
	if (*aa>*bb) return 1;
	if (*aa==*bb) return 0;
	if (*aa<*bb) return -1;
}
void showsys(int * a,int n)
{
	int i;
	qsort(a,n,sizeof(int),compar);
	for (i=0;i<n;i++)
		printf("a[%d]=%d",i,a[i]);
}

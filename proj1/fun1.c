#include "uhead.h"
void show(int * a,int n)
{
	int i,j,buf;
	for (i=0; i<n-1; ++i)  
    {
        for (j=0; j<n-1-i; ++j)  
        {
            if (a[j] > a[j+1])
            {
                buf = a[j];
                a[j] = a[j+1];
                a[j+1] = buf;
            }
        }
    }
	for (i=0;i<n;++i)
		printf("a[%d]=%d",i,a[i]);
}

void urand(int* a,int n)
{
	int i;
	srand((int)time(0));
	for (i=0;i<n;i++)
		a[i]=1+(int)(1000.0*rand()/(RAND_MAX+1.0));
}


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
	printf("test:pid=%d,ppid=%d\n",getpid(),getppid());
}

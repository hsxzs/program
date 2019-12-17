#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	printf("call:pid=%d,ppid=%d",getpid(),getppid());
	system("/home/rlk/week10/test\n");
	printf("after calling\n");
}

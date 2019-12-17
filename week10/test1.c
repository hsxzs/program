#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
int global1=0;
int global2=1;
int main()
{
	int pid;
	int i=10;
	static int k=20;
	pid = fork();
	if (pid < 0)
	{
		perror("error");
	}
	else if(pid == 0)
	{
	printf("child:pid=%d,ppid=%d,address:i=%p,global1=%p,global2=%p\n",getpid(),getppid(),&i,&global1,&global2);
	global1=999;
	global2=1000;
	i=12;
	k=19;
	sleep(10);	
	printf("child:pid=%d,ppid=%d,address:i=%p,global1=%p,global2=%p\n",getpid(),getppid(),&i,&global1,&global2);
	exit(0);
	}
	else{
		printf("child:pid=%d,ppid=%d,address:i=%p,global1=%p,global2=%p\n",getpid(),getppid(),&i,&global1,&global2);
		sleep(10);
		printf("%d,%d,%d,%d\n",&global1,&global2,&i,&k);
	}
}

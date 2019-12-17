#include "my.h"
void init_daemon(void);
main()
{
	FILE *fp;             
	time_t t;
	init_daemon();           
	while(1)               
	{
 		sleep(60);            
 		if((fp=fopen("test.log","a"))>=0)   
		{
			t=time(0);
			fprintf(fp,"I'm here at %s\n",asctime(localtime(&t)));
			fclose(fp);
		}
	 }
}
void init_daemon(void)
{
	int pid;
	int i;
	if(pid=fork())
		exit(0);                       
	else if(pid<0)         
		exit(1);                       
	setsid();   
	if(pid=fork())
		exit(0);                   
	else if(pid<0)               
		exit(1);                  
	for(i=0;i<NOFILE;i)           
	close(i);
	chdir("/tmp");               
	umask(0);                     
	return ;
}


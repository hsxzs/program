#include "my.h"
int count=0;
int main()
{
	pid_t p1,p2,p3;
	p1=fork();
	int r_num;
	int pipefd[1];
	char buf[4096];
	memset(buf,0,sizeof(buf));
	int s1,s2,s3,r1,r2,r3;
	if(p1<0)
	{
		perror("fork failed.\n");
		return -1;
	}
	else if(p1==0)
	{
		count+=1;
		printf("child pid=%d,ppid=%d,count%d\n",getpid(),getppid(),count);
		close(pipefd[1]);
		if((r_num=read(pipefd[0],buf,100))>0)
			printf("child read from pipe:%s,total=%d\n",buf,r_num);
		close(pipefd[0]);
		exit(0);
		//exit(99);
	}
	else
	{	
		printf("parent fork second time.\n");
		p2=fork();
		if (p2<0)
		{
			perror("fork2 failed.\n");
			return -1;
		}
		else if(p2==0)
		{
			count+=1;
			printf("child pid=%d,ppid=%d,count=%d\n",getpid(),getppid(),count);
			close(pipefd[0]);
			if(write(pipefd[1],"1234657890",10)!=-1)
				printf("parent write ok.\n");
			close(pipefd[1]);
			//return 0;
			if((r_num=read(pipefd[0],buf,100))>0)
				printf("child read from pipe:%s,total=%d\n",buf,r_num);
			close(pipefd[0]);
			exit(34);
		}
		else
		{
			printf("parent fork third time.\n");
			p3=fork();
			if(p3<0)
			{
				perror("fork3 failed.\n");
				return -1;
			}
			else if(p3==0)
			{
				count+=1;
				printf("child pid=%d,ppid=%d,count=%d\n",getpid(),getppid(),count);
				close(pipefd[0]);
				if(write(pipefd[1],"1234657890",10)!=-1)
					printf("parent write ok.\n");
				close(pipefd[1]);
				exit(77);
			}
			else
			{
				printf("parent waiting.\n");
				r1=wait(&s1);
				r2=wait(&s2);
				r3=wait(&s3);
				printf("r1=%d,s1=%d,r2=%d,s2=%d,r3=%d,s3=%d",r1,WEXITSTATUS(s1),r2,WEXITSTATUS(s2),r3,WEXITSTATUS(s3));
				printf("parent pid=%d,count=%d\n",getpid(),getppid());
				return 0;
			}
		}
	}
}

#include "my.h"

int count=0;

int main()
{
	pid_t p1,p2,p3;
	int fd1[2],fd2[2],wn,rn;
	long int x,sum;
	char r_buf[10],w_buf[10];
	memset(w_buf,0,10);
	memset(r_buf,0,10);

	pipe(fd1);
	pipe(fd2);
	sum=0;
	p1=fork();
	int s1,s2,s3,r1,r2,r3;
	if(p1<0)
	{
		perror("fork1 failed.\n");
		return -1;	
	}
	else if(p1==0)
	{	
		close(fd1[0]);
		printf("parent first time.\n");
		count+=1;
		printf("chid pid=%d,ppid=%d,count=%d\n",getpid(),getppid(),count);
		for(int i=1;i<4096;i++)
		{
			sprintf(w_buf,"%d",i);
			write(fd1[1],w_buf,sizeof(w_buf));
		}	
		close(fd1[1]);
		exit(99);	
	}
	else
	{
		p2=fork();
		if(p2<0)
		{
			perror("fork2 failed.\n");
			return -1;	
		}
		else if(p2==0)
		{	
			close(fd1[1]);
			close(fd2[0]);
			printf("parent second time.\n");
			count+=1;
			printf("chid pid=%d,ppid=%d,count=%d\n",getpid(),getppid(),count);
			for(int i=1;i<4096;i++)
			{
				read(fd1[0],r_buf,sizeof(r_buf));
				sscanf(r_buf,"%ld",&x);
				sprintf(w_buf,"%ld",x);
				write(fd2[1],w_buf,sizeof(w_buf));		
			}
			close(fd1[0]);
			close(fd2[1]);
			exit(34);	
		}
		else
		{
			p3=fork();
			if(p3<0)
			{
				perror("fork3 failed.\n");
				return -1;	
			}
			else if(p3==0)
			{	
				close(fd2[1]);
				printf("parent third time.\n");
				count+=1;
				printf("chid pid=%d,ppid=%d,count=%d\n",getpid(),getppid(),count);
				for(int i=1;i<4096;i++)
				{
					read(fd2[0],r_buf,sizeof(r_buf));
					sscanf(r_buf,"%ld",&x);
					printf("%ld\n",x);
					sum=sum+x;
				}
				printf("Result: sum=%ld\n",sum);
				close(fd2[0]);
				exit(77);	
			}
			else
			{
				r1=wait(&s1);
				r2=wait(&s2);
				r3=wait(&s3);
				printf("r1=%d,s1=%d,r2=%d,s2=%d,r3=%d,s3=%d\n",r1,WEXITSTATUS(s1),r2,WEXITSTATUS(s2),r3,WEXITSTATUS(s3));
				printf("parent pid=%d,count=%d\n",getpid(),count);	
			}
			printf("parent is running.\n");
		}
		return 0;
	}
}



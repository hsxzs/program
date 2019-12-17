#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
    pid_t pid;
    int i;
    for(i=0; i<3; i++)
    {
        pid=fork();
        if(pid==0||pid==-1)  //子进程或创建进程失败均退出
        {
            break;
        }
    }
    if(pid==-1)
    {
        perror("fail to fork!\n");
        exit(1);
    }
    else if(pid==0)
    {
        printf("子进程id=%d,对应父进程id=%d\n",getpid(),getppid());
        exit(0);
    }
    else 
    {
        printf("父进程id=%d\n",getpid());
        exit(0);
    }
}

#include"./h.h"

int main()
{
    int a=10;
    int b=20;
    int c=a+b;
    int fd=open("a.txt",O_WRONLY|O_CREAT,0777);
    //根据父进程当前状态，克隆一个新的子进程
    pid_t pid = fork();
    if(pid==0)
    {
        //子进程
        printf("in child,child pid =%d,ppid=%d\n",getpid(),getppid());
        write(fd,"child\n",6);
    }
    else
    {
        //父进程:返回的oid就是子进程的进程ID
        printf("in parent,child pid=%d,ppid=%d\n",pid,getpid());
        write(fd,"parent\n",7);
    }
    close(fd);
    printf("hello world\n");
    return 0;
}

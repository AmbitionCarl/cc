#include<stdio.h>
#include<fcntl.h>

int main()
{
    int fd=open("a.txt",O_WRONLY);
    if(fd<0)
    {
        printf("open error\n");
        return 0;
    }
    //duplicate复制
    int fd2=dup(fd);
    int fd3=fd;
    printf("fd2=%d,fd=%d,fd3=%d\n",fd2,fd,fd3);
    write(fd,"aaa",3);
    write(fd2,"bbb",3);
    while(1)
    {
        sleep(1);
    }
    close(fd);
    close(fd2);
    return 0;
}

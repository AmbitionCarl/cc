#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

int redir(const char*filename)
{
    int fd=dup(1);
    close(1);
    int bkfd=open(filename,O_APPEND|O_WRONLY|O_CREAT,0777);
    return fd;
}
void recorver(int fd)
{
    close(1);
    dup(fd);
}
int main()
{
    int fd=redir("mylog.txt");
    char buf[]="hello world";
    printf("%s\n",buf);
    fflush(stdout);

    recorver(fd);
    printf("hello man \n");
    return 0;
}

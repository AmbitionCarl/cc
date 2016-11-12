#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

int main()
{
    int fd=open("a.txt",O_WRONLY);
    printf("%d\n",fd);

    int fd2=open("b.txt",O_WRONLY|O_CREAT,0777);
    printf("%d\n",fd2);
    close(fd);
    fd=open("a.txt",O_WRONLY);
    printf("%d\n",fd);
    return 0;
}

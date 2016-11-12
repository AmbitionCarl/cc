#include<fcntl.h>
#include<stdio.h>
#include<inttypes.h>
#include<sys/mman.h>
#include<string.h>
#include<unistd.h>

int main()
{
    int pagesize=sysconf(_SC_PAGE_SIZE);
    printf("pagesize is %d\n",pagesize);
    int fd=open("a.txt",O_RDWR);//以读写方式打开
    char* p=(char*)mmap(NULL,1024,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
    close(fd);
    memcpy(p,"world",5);
    munmap(p,1024);

    return 0;
}

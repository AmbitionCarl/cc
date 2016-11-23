#include"./h.h"

int main()
{
    int fd=open("/dev/input/event1",O_RDONLY);
    if(fd<0)
    {
        perror("open");
        return 1;
    }
    while(1)
    {
        char buf[256];
        int ret=read(fd,buf,sizeof(buf));
        printf("ret is %d\n",ret);
    }
}

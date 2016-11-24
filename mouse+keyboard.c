#include"./h.h"

int main()
{
    int fd_mice=open("/dev/input/mice",O_RDONLY|O_NONBLOCK);
    int fd_keyb=open("dev/input/event1",O_RDONLY|O_NONBLOCK);

    char buf_mice[3];
    char buf_keyb[128];

    while(1)
    {
        //非阻塞
        int ret=read(fd_mice,buf_mice,sizeof(buf_mice));
        if(ret<0)
        {
            if(errno==EAGAIN)
                printf("can not read mice\n");
            else
            {

            }
        }

        //非阻塞
        ret=read(fd_keyb,buf_keyb,sizeof(buf_keyb));
        if(ret<0)
        {
            if(errno==EAGAIN)
            printf("can not read keyboard\n");
            else
            {

            }
        }
    }
}

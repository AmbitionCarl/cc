#include"./h.h"

int main()
{
    int readlen;
    char buf[1024];
    int fd_mice=open("/dev/input/mice",O_RDONLY|O_NONBLOCK);
    if(fd_mice<0)
    {
        perror("open err");
        return 0;
    }
    int fd_keyb=open("dev/input/evemt1",O_RDONLY|O_NONBLOCK);
    if(fd_keyb<0)
    {
        perror("open fd_keyb err");
        return 0;
    }
   
    #if 0
    1.  int epoll_create(int size);

    2.  int epoll_ctl(int epfd, int op, int fd, struct epoll_event *event);

    3.  int epoll_wait(int epfd, struct epoll_event *events,int maxevents, int timeout);
    #endif
   //集合
    int epollfd=epoll_create(512);
    //把fd_mice和fd_keyb加入到epollfd中
    struct epoll_event ev;
    ev.events=EPOLLIN;
    ev.data.fd=fd_mice;
    int ret=epoll_ctl(epollfd,EPOLL_CTL_ADD,fd_mice,&ev);
    if(ret<0)
    perror("epoll_ctl mice");

    ev.events=EPOLLIN;
    #if 0
    events可以是以下几个宏的集合：
    EPOLLIN ：表示对应的文件描述符可以读（包括对端SOCKET正常关闭）；
    EPOLLOUT：表示对应的文件描述符可以写；
    EPOLLPRI：表示对应的文件描述符有紧急的数据可读（这里应该表示有带外数据到来）；
    EPOLLERR：表示对应的文件描述符发生错误；
    EPOLLHUP：表示对应的文件描述符被挂断；
    EPOLLET： 将EPOLL设为边缘触发(Edge Triggered)模式，这是相对于水平触发(Level Triggered)来说的。
    EPOLLONESHOT：只监听一次事件，当监听完这次事件之后，如果还需要继续监听这个socket的话，需要再次把这个socket加入到EPOLL队列里
    #endif
    ev.data.fd==fd_keyb;
    ret=epoll_ctl(epoll_create(512),EPOLL_CTL_ADD,fd_keyb,&ev);
    if(ret<0)
    perror("epoll_ctl keyb");

    //select
    struct epoll_event out_events[2];
    while(1)
    {
        int ret=epoll_wait(epollfd,out_events,2,2000);
        printf("epoll_wait return %d\n",ret);
        if(errno==EINTR)
        {
            continue;
        }
        else
        {
            perror("epoll_wait error\n");
            exit(1);
        }
    }
    if(ret==0)
    {
        printf("nothing happened\n");
    }
    else{
        int i;
        for(i=0;i<ret;++i)
        {
            struct epoll_event*p =&out_events[i];
            if(p->data.fd==fd_mice)
            {
                readlen=read(fd_mice,buf,sizeof(buf));
                printf("mouce event");
            }
            else if(p->data.fd==fd_keyb)
            {
                readlen=read(fd_keyb,buf,sizeof(buf));
                printf("keyboard event");
            }
        }
    }
    
}




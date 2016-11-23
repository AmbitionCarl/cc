#include "./h.h"

int main()
{
    int fd=open("a.txt",O_RDWR|O_CREAT,0777);
    //LOCK it
    struct flock l;
    l.l_type=F_WRLCK;
    l.l_whence=SEEK_SET;
    l.l_len=128;
    l.l_start=0;
#if 0
    int fcntl(int fd, int cmd); 
    int fcntl(int fd, int cmd, long arg); 
    int fcntl(int fd, int cmd, struct flock *lock); 
      
      
    参数：   
    fd：文件描述词。 
    cmd：操作命令。 
    arg：供命令使用的参数。 
    lock：同上。 
#endif
    //加锁
    //如果存在其他锁,则调用进程睡眠;如果捕捉到信号则睡眠中断
    int ret=fcntl(fd,F_SETLKW,&l);
    if(ret==0)
    {
        printf("lock success\n");
    }
    else
    {
        printf("lock failure\n");
    }
    getchar();
    //解锁
    l.l_type=F_UNLCK;
    fcntl(fd,F_SETLKW,&l);
}

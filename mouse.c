#include"./h.h"

int main()
{
    int fd=open("/dev/input/mice",O_RDONLY);
    if(fd<0)
    {
        perror("open");
        return 1;
    }
    while(1)
    {
        char buf[8];
        int len =read(fd,buf,sizeof(buf));
        printf("read len = %d\n",len);
        //第一个字节表示鼠标是点击还是移动
        //第二个字节表示x方向的偏移
        //第三个表示y方向的偏移

        char key=buf[0];
        char xoff=buf[1];
        char yoff=buf[2];
        char btype=key & 0x7;
        if(btype==0x00)
        {
            printf("button up\n");
        }
        else if(btype==0x01)
        {
            printf("left button down\n");
        }
        else if(btype == 0x02)
        {
            printf("right button down\n");
        }
    }
    return 0;
}

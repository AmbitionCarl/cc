#include"./h.h"

int main()
{
    char buf[1024];
                    //char * getcwd(char * buf, size_t size);
                    //取得当前工作目录
    printf("%s\n",getcwd(buf,sizeof(buf)));
    int fd=open("a",O_RDONLY);
    printf("fd is %d\n",fd);

      //int chdir(const char * path);
    //用来改变当前工作目录
    chdir("/home/test");
    printf("%s\n",getcwd(buf,sizeof(buf)));
    int fd2=open("a",O_RDONLY);

    printf("fd2=%d\n",fd2);

    return 0;
}

#include"./h.h"

int main()
{
    int fd=open("a.txt",O_WRONLY|O_CREAT,0777);
    //int execlp(const char * file,const char * arg,……);
    execlp("ls","ls",NULL);
    printf("exec end ...\n");
    return 0;
}

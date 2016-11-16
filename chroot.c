#include"./h.h"

int main()
{
    int ret=chroot("/home/test/cc");
    printf("ret=%d\n",ret);
    perror("chroot");
    int fd=open("/a",O_RDONLY);
    printf("fd=%d\n",fd);
}

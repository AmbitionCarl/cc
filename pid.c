#include"./h.h"

int main()
{
    pid_t pid=getpid();//得到当前id
    printf("%d\n",(int )pid);
    while(1)
    {
        sleep(1);
    }
    return 0;
}

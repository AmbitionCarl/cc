#include"./h.h"

int main()
{
    pid_t pid=fork();

    if(pid==0)
    {
        while(1)
        {
            sleep(1);
        }
    }
    else
    {
        pid_t pid=getpid();
        printf("pid=%d\n",(int)pid);
    }
    return 0;
}

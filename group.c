#include"./h.h"

int main()
{
    pid_t pid=fork();
    if(pid==0)
    {
        setsid();
    }

    while(1)
    {
        sleep(1);
    }
    return 0;
}

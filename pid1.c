#include"./h.h"
int main()
{
     pid_t pid=fork();
    if(pid==0)
    {
        sleep(3);
        printf("hello world\n");
        return 0;
    }
    wait(NULL);
}


#include"./h.h"

void handle(int v)
{
    wait(NULL);
    printf("some child something hanppen\n");
}

int main()
{
    //sigchld
    signal(SIGCHLD,handle);

    pid_t pid=fork();
    if(pid==0)
    {
        printf("byebye\n");
        return 0;
    }
    while(1)
    {
        sleep(1);
    }
}

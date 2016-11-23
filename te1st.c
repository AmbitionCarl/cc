#include"./h.h"
void handle(int v)
{
    printf("signal is handle\n");
}

int main()
{
    signal(SIGUSR1,handle);
    pid_t pid=fork();
    if(pid==0)
    {
        sleep(1);
        kill(getppid(),SIGUSR1);
        return 0;
    }

    char buf[10];
    fgets(buf,sizeof(buf),stdin);
    printf("hello world\n");
    return 0;
}

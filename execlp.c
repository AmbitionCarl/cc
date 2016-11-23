#include"./h.h"

int main()
{
    pid_t pid =getpid();
    execl("ps","-aux",NULL);
    printf("%d\n",(int)geteuid());
    return 0;
}

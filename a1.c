#include"stdio.h"
#include"unistd.h"

int main()
{
    execl("/bin/ps","ps","-aux",NULL);
    
    printf("%d\n",getpid()>40000&&getpid()<5000);
    return 0;
}

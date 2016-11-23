#include"./h.h"

int main()
{
    pid_t pid=fork();

    if(pid==0)

    {
        sleep(2);
        return 2;
    }

    else
    {
        int status;
        //等待子进程结束,如果有任何子进程退出,wait就会返回
        //wait是一个阻塞调用
        
        pid_t pid_wait=wait(&status);
        printf("pid %d,pid_wait %d\n",(int)pid,(int)pid_wait);
        #if 0
        WIFEXITED(int status) 
            子进程正常退出（"exit"或"_exit"），此宏返回非0
          WEXOTSTATUS(int status)
            获得子进程exit()返回的结束代码，一般先要用WIFEXITED判断是否正常结束。
          WIFSIGNALED(int status)
            如果子进程是因为信号而结束则此宏值为真
        #endif
        if(WIFEXITED(status))
        {
            int exit_code=WEXITSTATUS(status);
            printf("child exit,%d\n",exit_code);
        }
    }
    return 0;
}

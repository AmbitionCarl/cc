#include<unistd.h>
#include<stdio.h>
#include<sys/stat.h>
#include<errno.h>
#include<string.h>

int main()
{
    struct stat buf;
    stat("..",&buf);
    printf("%d\n",(int)buf.st_size);
    if(S_ISREG(buf.st_mode))
    {
        printf("this is regular file\n");
    }
    else
    {
        printf("this is not regular file\n");
    }
    if(S_ISDIR(buf.st_mode))
    {
        printf("this is dir\n");
    }
    #if 0
    定义函数
    int access(const char * pathname, int mode);
    函数说明
    access()会检查是否可以读/写某一已存在的文件。参数mode有几种情况组合， R_OK，W_OK，X_OK 和F_OK。R_OK，W_OK与X_OK用来检查文件是否具有读取、写入和执行的权限。F_OK则是用来判断该文件是否存在。由于access()只作权限的核查，并不理会文件形态或文件内容，因此，如果一目录表示为“可写入”，表示可以在该目录中建立新文件等操作，而非意味此目录可以被当做文件处理。例如，你会发现DOS的文件都具有“可执行”权限，但用execve()执行时则会失败。
    返回值
    若所有欲查核的权限都通过了检查则返回0值，表示成功，只要有一权限被禁止则返回-1。
    #endif
    int ret=access("a.txt",W_OK);
    printf("ret =%d,err=%s\n",ret,strerror(errno));

    while(1)
    {
        sleep(1);
    }
    return 0;
}


#include<stdio.h>
#include<fcntl.h>

int main()
{
    int fd=open("a.txt",O_WRONLY|O_APPEND);//O_WRONLY 后面追加
    if(fd<0)
    {
        printf("open error\n");
        return 0;
    }
    write(fd,"aaa",3);
#if 0
off_t lseek(int filedes, off_t offset, int whence);
                        返回值：新的偏移量（成功），-1（失败）
    参数 offset 的含义取决于参数 whence：
        1. 如果 whence 是 SEEK_SET，文件偏移量将被设置为 offset。 
        2. 如果 whence 是 SEEK_CUR，文件偏移量将被设置为 cfo 加上 offset， 
           offset 可以为正也可以为负。 
        3. 如果 whence 是 SEEK_END，文件偏移量将被设置为文件长度加上 offset， 
           offset 可以为正也可以为负。
#endif 
    lseek(fd,0,SEEK_SET);
    write(fd,"bbb",3);
    close(fd);
    return 0;
}

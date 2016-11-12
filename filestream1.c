/*************************************************************************
	> File Name: filestream1.c
	> Author:BIN 
	> Mail:503807089@qq.com 
	> Created Time: 2016年11月11日 星期五 20时05分34秒
 ************************************************************************/

#include<stdio.h>
#include<fcntl.h>

int main()
{
    int fd =open("a.txt",O_WRONLY,0777);//O_WRONLY只写
    if(fd<0)
    {
        printf("open error\n");
        return 0;
    }
    write(fd,"aaaa",3);
    while(1)
    {
        sleep(1);
    }
    close(fd);
    return 0;
}



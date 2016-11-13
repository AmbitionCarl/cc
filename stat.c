#include<sys/stat.h>
#include<stdio.h>
#include<errno.h>

#if 0
函数定义:    int stat(const char *file_name, struct stat *buf); 
函数说明:    通过文件名filename获取文件信息，并保存在buf所指的结构体stat中 
返回值:     执行成功则返回0，失败返回-1，错误代码存于errno（需要include <errno.h>）



     errno错误代码: 
         ENOENT         参数file_name指定的文件不存在 
         ENOTDIR        路径中的目录存在但却非真正的目录 
         ELOOP          欲打开的文件有过多符号连接问题，上限为16符号连接 
         EFAULT         参数buf为无效指针，指向无法存在的内存空间 
         EACCESS        存取文件时被拒绝 
         ENOMEM         核心内存不足 
         ENAMETOOLONG   参数file_name的路径名称太长



                                      stat结构体定义:

                                          struct stat { 
                                              dev_t         st_dev; 文件的设备编号 
                                              ino_t         st_ino;         节点 
                                              mode_t        st_mode;文件的类型和存取的权限 
                                              nlink_t       st_nlink;连到该文件的硬连接数目，刚建立的文件值为1 
                                              uid_t         st_uid;用户ID 
                                              gid_t         st_gid;组ID 
                                              dev_t         st_rdev;设备类型)若此文件为设备文件，则为其设备编号 
                                              off_t         st_size;文件字节数(文件大小) 
                                              unsigned long st_blksize;块大小(文件系统的I/O 缓冲区大小) 
                                              unsigned long st_blocks;块数 
                                              time_t        st_atime;最后一次访问时间 
                                              time_t        st_mtime;最后一次修改时间 
                                              time_t        st_ctime;最后一次改变时间(指属性) 
                                          };
#endif




int main()
{
    struct stat buf;
    int ret=stat("a.txt",&buf);
    if(ret)
    {
        printf("stat file fail\n");

        printf("%d\n",errno);
    }
    return 0;
}

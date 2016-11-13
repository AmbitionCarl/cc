#include"./h.h"

int rm(const char* path)
{
    //判断path所否是文件还是目录，如果所文件直接返回
    struct stat stat_buf;
    
    //原型int stat(const char *file_name, struct stat *buf); 
    int ret=stat(path,&stat_buf);
    if(ret<0)
    {
        perror("stat");
        return -1;
    }
    if(!S_ISDIR(stat_buf.st_mode))
    {
        unlink(path);
        return 0;
    }
    //如果path所目录，遍历目录中的所有目录项
    char buf[1024];
    DIR*dir=opendir(path);
    if(dir==NULL)
    
        return -1;
    

    struct dirent*entry=readdir(dir);
    while(entry)
    {
        //得到文件信息
        sprintf(buf,"%s/%s",path,entry->d_name);
        if(entry->d_type==DT_REG||entry->d_type==DT_LNK)
        {
            unlink(buf);
        }
        if(entry->d_type==DT_DIR)
        {
            //忽略.和..目录
            if(strcmp(entry->d_name,".")==0||strcmp(entry->d_name,".."
          //  函数原型：extern int strcmp(char *str1,char * str2)
        // 参数说明：str1为第一个要比较的字符串，str2为第二个要比较的字符串
                                                   )==0)
            {
                entry=readdir(dir);
                continue;
            }
            rm(buf);
        }
        entry=readdir(dir);
    }
    closedir(dir);
    rmdir(path);
    return 0;
}

int main(int argc,char*argv[])
{
    if(argc==1)
    {
        printf("usage:%s[pathnam]\n",argv[0]);
        return 0;
    }
    rm(argv[1]);
    return 0;
}

#include"./h.h"

int main(int argc,char*argv[])
{
    if(argc!=3)
    {
        printf("usage: %s[srcfile][dstfile]\n",argv[0]);
        return 0;
    }

    const char*filesrc=argv[1];
    const char*filedst=argv[2];

    FILE *fp_src=fopen(filesrc,"r");
    FILE*fp_dst=fopen(filedst,"w");

    char buf[2096];
    while(1)
    {
        //定义函数：size_t fread(void * ptr, size_t size, size_t nmemb, FILE * stream);
        int ret=fread(buf,1,sizeof(buf),fp_src);
        if(ret<=0)
        break;
        //   原型为 size_t fwrite(void * buffer, size_t size, size_t count, FILE * stream)
        fwrite(buf,ret,1,fp_dst);
    }
    fclose(fp_src);
    fclose(fp_dst);

    //获取源文件属性
    struct stat src_stat;
    stat(filesrc,&src_stat);

    //修改目标文件时间
    struct utimbuf timbuf;
    timbuf.actime=src_stat.st_atime;
    timbuf.modtime=src_stat.st_mtime;
    utime(filedst,&timbuf);

    //修改权限

    chmod (filedst,src_stat.st_mode);

    //修改所有者

    int ret=chown(filedst,src_stat.st_uid,src_stat.st_gid);
    if(ret<0)
    {
        perror("chown");
         
    }
    return 0;
}

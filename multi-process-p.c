#include"./h.h"

int get_file_length(const char*filenaem)
{
    struct stat buf;
    int ret=stat(filenaem,&buf);
    if(ret==-1)
        return -1;
    return buf.st_size;
}

void process_copy(const char* src_file,const char*dst_file,int pos,int length)
{
    FILE*src=fopen(src_file,"r");
    FILE*dst=fopen(dst_file,"r+");

    char buf[4096];
    int block_size=sizeof(buf);

    fseek(src,pos,SEEK_SET);
    fseek(dst,pos,SEEK_SET);

    while(length)
    {
        int copy_len =length<block_size ? length:block_size;
        int ret=fread(buf,1,copy_len,src);
        fwrite(buf,ret,1,dst);
        length-=ret;
    }
    fclose(src);
    fclose(dst);
}

int main(int argc,char*argv[])
{
    if(argc !=5)
    {
        printf("usage %s -job {process_count} {src_file} {dst_file}\n",argv[0]);
        return 1;
    }
    if (strcmp(argv[1],"-job")!=0)
    {
        printf("unknown options:%s\n",argv[1]);
        return 2;
    }

    int process_count=atoi(argv[2]);
    if(process_count<=0)
    {
        printf("process_count error\n");
        return 3;
    }
    const char*src_file=argv[3];
    const char* dst_file=argv[4];

    //获得文件总长度
    int filelen=get_file_length(src_file);
    if(filelen==-1)
    {
        printf("file not exist\n");
        return 3;
    }
    //保证dst文件存在,并且dst的文件尺寸是src文件一样大
    int fd=open(dst_file,O_CREAT|O_WRONLY,0777);
    close(fd);
    #if 0
    定义函数：int truncate(const char * path, off_t length);

    函数说明：truncate()会将参数path 指定的文件大小改为参数length 指定的大小. 如果原来的文件大小比参数length 大, 则超过的部分会被删去.

    返回值：执行成功则返回0, 失败返回-1, 错误原因存于errno.
    #endif
    truncate(dst_file,filelen);

    int i;
    int average=filelen/process_count;
    //只要创建n-1个子进程,父进程负责最后部分的拷贝
    for(i=0;i<process_count-1;++i)
    {
        pid_t pid=fork();
        if(pid==0)
        {
            //子进程拷贝完成直接结束
            int pos=average*i;
            process_copy(src_file,dst_file,pos,average);
            return 0;
        }
    }
    int pos=average*i;
    process_copy(src_file,dst_file,pos,filelen-pos);
    //wait 一次只wait一个子进程
    for(i=0;i<process_count-1;++i)
    {
        wait(NULL);
    }
    return 0;
}

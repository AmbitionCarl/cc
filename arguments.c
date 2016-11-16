#include"./h.h"

#define mylog(fmt, ...) myprint(__FILE__, __LINE__, fmt, __VA_ARGS__)
void myprint(const char* filename, int line, const char* fmt, ...)
{
    printf("%s,%d,",filename,line);
    va_list ap;
    va_start(ap,fmt);
    vprintf(fmt,ap);
    va_end(ap);
}

int print(const char*a,...)
{
    const char* arg =a;
    va_list args;
    va_start(args,a);
    while(arg)
    {
        printf("%s\n",arg);
        arg=va_arg(args,const char*);
    }

    va_end(args);
}
int add(int count,...)
{
    int i;
    int sum=0;
    va_list args;
   //获得不定参数的首地址
    va_start(args,count);
    for(i=0;i<count;++i)
    {
        //通过va_arg获得参数
        int arg=va_arg(args,int );
        sum+=arg;
    }
    va_end(args);
    return sum;
}

int main()
{
     myprint(__FILE__, __LINE__, "haha%d\n", 100);
    mylog("print in mylog %d\n",100);
    print("hello","world","haha","you are dead",NULL);
    int ret = add(3,5,6,7);
    printf("%d\n",ret);
    return 0;
}

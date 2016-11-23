#include"./h.h"
int main()
{
    printf("clock tick is %ld\n",sysconf(_SC_CLK_TCK));
    clock_t s,e;
    struct tms bufs,bufe;
    s=times(&bufs);

    int i,j;

    for(i=0;i<10000;i++)
    for(j=0;j<10000;j++)
        ;
    for(i=0;i<100;++i)
    printf("hello world");

    e=times(&bufe);
    printf("time is  %d,user time is  %d,sys time =%d\n",
           (int)(e-s),(int)(bufe.tms_utime-bufs.tms_utime),
           (int)(bufe.tms_stime-bufs.tms_stime));
    return 0;
}

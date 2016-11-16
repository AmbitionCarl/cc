#include"./h.h"

int main()
{
    struct utimbuf buf;
    buf.actime=0;
    buf.modtime =0;
    utime("testfile",&buf);

    struct timeval tv[2];
    tv[0].tv_sec=10000;
    tv[0].tv_usec=1000;

    tv[1].tv_sec=100000;
    tv[1].tv_usec=10000;
    utimes("testfile",tv);
}

#include"./h.h"

int main()
{
    struct stat buf;
    stat("file",&buf);

    struct stat buf2;
    lstat("file",&buf2);

    if(S_ISREG(buf.st_mode))
    {
        printf("this is reg file\n");
    }
    if(S_ISLNK(buf2.st_mode))
    {
        printf("this is link\n");
    }
    return 0;
}

#inlcude"./h.h"

//该变量定义在stdlib里
extern char** environ;

int main()
{
    int i;
    for(i=0;;++i)
    {
        if(environ[i]==NULL)
            break;
        printf("%s\n",environ[i]);
    }
    return 0;
}

#include"./h.h"

char g_cmd[4096];
char * g_cmdargs[1024];
int g_args_count=0;

//绝对路径 相对路径 命令
#define PATH_TYPE_A 0
#define PATH_TYPE_R 1
#define PATH_TYPE_C 2

int path_type(char* cmd)
{
    char*slas_pos=strstr(cmd,"/");
    if(slas_pos==cmd)
        return PATH_TYPE_A;
    else if(slas_pos!=NULL)
        return PATH_TYPE_R;

    return PATH_TYPE_C;
}

void get_cmd()
{
    //打印MYSHELL的提示符 PATH$
    char cur_path[1024];
    printf("%s$",getcwd(cur_path,sizeof(cur_path)));

    fgets(g_cmd,sizeof(g_cmd),stdin);
    //去掉
    g_cmd[strlen(g_cmd)-1]=0;
}

//将命令按照空格拆分到g_cmdargs中
void split_cmd()
{
    
    g_args_count=0;
    char *arg=strtok(g_cmd," \t");
    while(1)
    {
        g_cmdargs[g_args_count++]=arg;
        if(arg==NULL)//为了给数组的最后一项赋值为NULL
          break;
        arg=strtok(NULL," \t");
    }
}

void handle_cmd()
{
    //拆分命令
    split_cmd();
    
    //命令是否shell内置命令,如果是shell内置的命令
    //应该特殊处理,无法通过fok+exec来执行
    if(strcmp(g_cmdargs[0],"cd")==0)
    {
        if(g_cmdargs[1] !=NULL)
            chdir(g_cmdargs[1]);
        else
            chdir(getenv("HOME"));
        return;
    }

    //不是内置命令,说明是一个系统的命令系统
    //或者是用户自己写的程序
    pid_t pid=fork();
    if(pid==0)//在子进程中,执行该命令
    {
        //一般来说,在子进程需要成为一个进程组长
        setpgid(0,0);

        //execlp(g_cmd,g_cmd,NULL);
        //int pt=path_type(g_cmdargs[0]);
        //如果g_cmdargs[0]如果没有/,那么回到PATH找文件
        //如果有,相当于execv
        int ret=execvp(g_cmdargs[0],g_cmdargs);
        if(ret<0)
        {
            exit(1);
        }
        #if 0
        if(pt==PATH_TYPE_C)
            execvp(g_cmdargs[0],g_cmdargs);
        else
            execv(g_cmdargs[0],g_cmdargs)
        #endif
        return;
    }
    wait(NULL);
}
int main()
{
    while(1)
    {

        get_cmd();
        //处理命令
        if(strlen(g_cmd)==0)
            continue;
        handle_cmd();
    }
}


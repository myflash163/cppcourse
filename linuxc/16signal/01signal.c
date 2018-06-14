#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <signal.h>

#define ERR_EXIT(m)         \
    do                      \
    {                       \
        perror(m);          \
        exit(EXIT_FAILURE); \
    } while (0)

void handler(int sig);
/**
 * kill -l 查看所有信号
 * SIGINT(ctrl+c)
 * SIGQUIT(ctrl+\)
 */
int main(int argc,char *argv[])
{
    //typedef void (*sighandler_t)(int);
    //sighandler_t oldhandler;
     signal(SIGINT,handler);
     if(oldhandler == SIG_ERR)
    //     ERR_EXIT("signal error");

    // while(getchar() != '\n'){}
    // //关联信号默认操作
    // if(signal(SIGINT,SIG_DFL) == SIG_ERR)
    //     ERR_EXIT("signal error");

    for(;;);
    return 0;
}

void handler(int sig)
{
    printf("recv a sig= %d\n",sig);
}
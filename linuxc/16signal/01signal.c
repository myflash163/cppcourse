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
 * 函数原型 __sighandler_t signal(int __sig, __sighandler_t __handler)
 */
int main(int argc,char *argv[])
{
    __sighandler_t oldhandler;
    oldhandler =signal(SIGINT,handler);
    if(oldhandler == SIG_ERR)
        ERR_EXIT("signal error");

    while(getchar() != '\n'){}
     //关联信号默认操作
    if(signal(SIGINT,SIG_DFL) == SIG_ERR)
         ERR_EXIT("signal error");

    for(;;);
    return 0;
}

void handler(int sig)
{
    printf("recv a sig= %d\n",sig);
}
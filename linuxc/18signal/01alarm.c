#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>


#define ERR_EXIT(m)         \
    do                      \
    {                       \
        perror(m);          \
        exit(EXIT_FAILURE); \
    } while (0)

void handler(int sig);
/*
 * 更多信号发送函数
 * alarm SIGALRM
 * setitimer SIGALRM SIGVTALRLM SIGPROF
 * abort  SIGABRT
 */ 
int main(int argc,char *argv[])
{
    if(signal(SIGALRM,handler) == SIG_ERR)
        ERR_EXIT("signal error");

    alarm(1);
    //可以通过 kill -SIGALRM 21656 发送信号
    //可以通过 kill -ALRM 21656 发送信号
   for(;;)
   {
       pause();
   }

    return 0;
}

void handler(int sig)
{
    printf("recv a sig= %d\n",sig);
    alarm(1);//间接递归
}
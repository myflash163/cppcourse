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
 * pause 将进程置为可中断睡眠状态。然后它调用schedule(),使linux进程调度器找到另一个进程来运行
 * pause 使调用者进程挂起，直到一个信号被捕获
 */ 
int main(int argc,char *argv[])
{
    if(signal(SIGINT,handler) == SIG_ERR)
        ERR_EXIT("signal error");

   for(;;)
   {
       pause();
       printf("pause return\n");
   }

    return 0;
}

void handler(int sig)
{
    printf("recv a sig= %d\n",sig);
    sleep(1);
}
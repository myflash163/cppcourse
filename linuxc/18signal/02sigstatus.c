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
 * 信号集操作函数
 * #include <signal.h>
 * int sigemptyset(sigset_t *set);
 * int sigfillset(sigset_t *set);
 * int sigaddset(sigset_t *set,int signo);
 * int sigdelset(sigset_t *set,int signo);
 * int sigismember(const sigset_t *set,int signo);
 * 
 * //读取或更改进程的信号屏蔽字
 * int sigprocmask(int how,const sigset_t *set,sigset_t *oset) 
 * how SIG_BLOCK  SIG_UNBLOCK SIG_SETMASK
 */ 
int main(int argc,char *argv[])
{
    sigset_t pset;
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
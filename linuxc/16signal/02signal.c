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
 * 信号发送
 * kill(pid,sig)
 * pid>0 信号sig发送给进程号=pid的进程
 * pid=0 信号sig发送给调用者所在组中的每一个进程
 * pid=-1 信号sig发送给调用者有权限发送的每一个进程，除了1号进程之外。
 * 
 * 信号发送安装新版本，发送函数sigqueue() 安装函数sigaction()
 * 
 * raise 给自己发送信号。raise(sig) 等价于kill(getpid(),sig);
 * killpg 给进程组发送信号。killpg(pgrp,sig)等价于kill(-pgrp,sig);
 * sigqueue 给进程 发送信号，支持排队，可以附带信息。
 */ 
int main(int argc,char *argv[])
{
    if(signal(SIGUSR1,handler) == SIG_ERR)
        ERR_EXIT("signal error");

    pid_t pid = fork();//子进程 继承信号
    if (pid == -1)
        ERR_EXIT("fork error");
    
    if(pid == 0)
    {
        //getppid() 父pid
        pid = getpgrp();//组pid
        kill(-pid,SIGUSR1);
        exit(EXIT_SUCCESS);
    }
    int n = 5;
    do{
        n = sleep(n);
    }while(n>0);

    return 0;
}

void handler(int sig)
{
    printf("recv a sig= %d\n",sig);
}
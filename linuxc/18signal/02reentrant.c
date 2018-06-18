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
typedef struct 
{
    int a;
    int b;
} TEST;
TEST g_data;
int main(int argc,char *argv[])
{
    TEST zeros = {0,0};
    TEST ones = {1,1};
    if(signal(SIGALRM,handler) == SIG_ERR)
        ERR_EXIT("signal error");

    g_data = zeros;
    alarm(1);
   for(;;)
   {
       g_data = zeros;
       g_data = ones;
   }

    return 0;
}
/**
 * 满足下列条件的函数多数是不可再入的
 * (1)使用静态的数据结构，如getlogin(),gmtime(),getgrgid(),getgrname(),getpwuid()以及getpwname()等等
 * (2)函数实现时，调用了malloc()或者free()函数
 * (3)实现时，使用了标准I/O函数的
 */ 
void handler(int sig)
{
    printf("%d %d\n",g_data.a,g_data.b);//不可重入函数
    alarm(1);//间接递归
}
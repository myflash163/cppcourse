#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

/* #define ERR_EXIT(m) (prror(m),exit(EXIT_FAILURE)) */
#define ERR_EXIT(m)\
    do\
    {\
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

int main(int argc, char const *argv[])
{
    umask(0);
    int fd;
    fd = open("test.txt", O_WRONLY | O_CREAT | O_EXCL,0666);
    if (fd == -1)
    {
        ERR_EXIT("open_error");
    }
    printf("open_success\n");
    close(fd);
    return 0;
}

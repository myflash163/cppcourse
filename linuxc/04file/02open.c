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
    int fd;
    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        // fprintf(stderr, "open error with errno=%d %s\n", errno, strerror(errno));
        /* perror("open_error");
        exit(EXIT_FAILURE); */
        ERR_EXIT("open_error");
    }
    printf("open_success\n");
    return 0;
}

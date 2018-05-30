#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#define ERR_EXIT(m)         \
    do                      \
    {                       \
        perror(m);          \
        exit(EXIT_FAILURE); \
    } while (0)

int main(int argc, char const *argv[])
{
    int fd;
    fd = open("seek.txt", O_RDONLY);
    if (fd == -1)
    {
        ERR_EXIT("open_error");
    }
    char buf[1024] = {0};
    int ret = read(fd, buf, 5);
    if (ret == -1)
        ERR_EXIT("read_error");
    ret = Lseek(fd, 0, SEEK_CUR);
    if (ret == -1)
        ERR_EXIT("lseek");
    printf("current offset = %d \n", ret);
    return 0;
}

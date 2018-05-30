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
    fd = open("hole.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
        ERR_EXIT("open error");
    write(fd, "ABCDE", 5);
    int ret = lseek(fd, 32, SEEK_CUR);
    if (ret == -1)
        ERR_EXIT("lseek error");
    write(fd, "hello", 5);
    close(fd);
    return 0;
    //od -c hole.txt 查看二进制码
    //du -h hole.txt  查看实际占用磁盘空间
    //ls -lh  hole.txt 查看文件大小
}
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>

#define ERR_EXIT(m)         \
    do                      \
    {                       \
        perror(m);          \
        exit(EXIT_FAILURE); \
    } while (0)

#define MAJOR(a) (int)((unsigned short)a >> 8)
#define MINOR(a) (int)((unsigned short)a & 0xFF)

int filetype(struct stat *buf);

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage %s file\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    struct stat sbuf;

    printf("Filename:%s\n", argv[1]);
    if (stat(argv[1], &sbuf) == -1)
        ERR_EXIT("stat_error");
    printf("File number:major %d,minor %d inode %d\n", MAJOR(sbuf.st_dev), MINOR(sbuf.st_dev), (int)sbuf.st_ino);

    if (filetype(&sbuf))
    {
        printf("Device number:major %d,minor %d inode %d\n", MAJOR(sbuf.st_rdev), MINOR(sbuf.st_dev), (int)sbuf.st_rdev);
    }

    return 0;
}
int filetype(struct stat *buf)
{
    int flag = 0;
    printf("Filetype:");
    mode_t mode;
    mode = buf->st_mode;
    switch (mode & S_IFMT)
    {
    case S_IFSOCK:
        printf("socket\n");
        break;
    case S_IFLNK:
        printf("symbolic link\n");
    case S_IFREG:
        break;
    case S_IFBLK:
        flag = 1;
        printf("block device\n");
    case S_IFDIR:
        printf("directory\n");
    case S_IFCHR:
        printf("character device\n");
    case S_IFIFO:
        printf("FIFO\n");

    default:
        printf("other");
    }
    return flag;
}
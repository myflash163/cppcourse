#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <dirent.h>

#define ERR_EXIT(m)         \
    do                      \
    {                       \
        perror(m);          \
        exit(EXIT_FAILURE); \
    } while (0)

int main(int argc, char const *argv[])
{
    DIR *dir = opendir(".");
    struct dirent *de;
    while ((de = readdir(dir)) != NULL)
    {
        if (strncmp(de->d_name, ".", 1) == 0)
            continue;
        printf("%s\n", de->d_name);
    }
    closedir(dir);
    exit(EXIT_SUCCESS);
}
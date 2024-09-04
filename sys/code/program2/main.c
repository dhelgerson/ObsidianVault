#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    int fd;
    char *data[20];
    fd = open('raw.dat',O_RDONLY);
    read(fd,data,20);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>

int checkError(int val, const char *msg)
{
    if (val == -1)
    {
        perror(msg);
        exit(EXIT_FAILURE);
    }
    return val;
}
int main()
{
    int fd;
    int val;
    int numWr;

    fd = checkError(open("test.dat",O_WRONLY | O_CREAT | O_TRUNC, 0766), "Failed to open file");
    for (val = 1000; val < 2000; val++)
    {
        numWr = checkError(write(fd, &val,sizeof(int)),"write failed");
    }
    fd = open("test.dat",O_RDONLY);
    while (numWr = checkError(read(fd, &val,sizeof(int)),"failed to read") > 0)
    {
        printf("%d ",val);
    }
    close(fd);

    return 0;
}

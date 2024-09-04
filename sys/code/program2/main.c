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
    short s;


    unsigned char bytes[20];
    fd = open("raw.dat",O_RDONLY);
    read(fd,bytes,20);

    for(int i=2; i<20;i+=2) {
        printf("%i\n",i);
    }

    return 0;
}
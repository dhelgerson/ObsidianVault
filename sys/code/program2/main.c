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
    double d;
    unsigned char bytes[20];

    fd = open("raw.dat",O_RDONLY);
    read(fd,bytes,20);

    for(int i=2; i<20;i+=2) {
        s = ((short)bytes[i+1] << 8) | bytes[i];
        d = s / 32768;
        printf("%i ",i);
        printf("%hi %lf\n",s,d);
    }

    return 0;
}
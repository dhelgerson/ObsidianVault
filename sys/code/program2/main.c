#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    int in,out;
    short s;
    double val;
    unsigned char bytes[20];

    in = open("raw.dat",O_RDONLY);
    // read(in,bytes,20);

    while(read(in,bytes,20) > 0)
        for(int i=2; i<20;i+=2) {
            s = ((short)bytes[i+1] << 8) | bytes[i];
            val = s / 32768.0;
            printf("%i %hi %lf\n",i/2,s,val);
        }

    return 0;
}
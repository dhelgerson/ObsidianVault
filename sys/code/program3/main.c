#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    int data,accl,angl,rota;
    short s;
    double val;
    double bytes[9];

    data = open("raw.dat",O_RDONLY);
    accl = open("data.dat",O_WRONLY|O_CREAT|O_TRUNC,0766);
    angl = open("data.dat",O_WRONLY|O_CREAT|O_TRUNC,0766);
    rota = open("data.dat",O_WRONLY|O_CREAT|O_TRUNC,0766);

    while(read(data,bytes,9*sizeof(double)) > 0)
    {
        for(int i=0; i<10;i++) 
        {
            printf("%i",i);
        }
    }
    close(data);
    close(accl);
    close(angl);
    close(rota);

    return 0;
}
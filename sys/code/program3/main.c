#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

int checkErr(int val, const char *msg)
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
    int data,accl,angl,rota;
    short s;
    double val;
    double bytes[9];

    data = checkErr(open("data.dat",O_RDONLY),"failed, open data,dat");
    mkdir("values", 0777);    
    accl = checkErr(open("values/accl.dat",O_WRONLY|O_CREAT|O_TRUNC,0766),"failed, open accl.dat");
    angl = checkErr(open("values/angl.dat",O_WRONLY|O_CREAT|O_TRUNC,0766),"failed, open angl.dat");
    rota = checkErr(open("values/rota.dat",O_WRONLY|O_CREAT|O_TRUNC,0766),"failed, open rota.dat");

    while(checkErr(read(data,bytes,9*sizeof(double)),"failed, read data.dat") > 0)
    {
        write(accl,&bytes[0],3*sizeof(double));
        write(angl,&bytes[3],3*sizeof(double));
        write(rota,&bytes[6],3*sizeof(double));        
    }
    close(data);
    close(accl);
    close(angl);
    close(rota);

    return 0;
}
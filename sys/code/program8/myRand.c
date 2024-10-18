#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>



int main()
{
    // seed rand()
    srand(time(NULL));

    int x = rand() % 256;
    char filename[20];
    sprintf(filename,"data%d.dat",x);
    printf("%s \n",filename);
    int fd = open(filename,O_WRONLY|O_CREAT|O_TRUNC,0744);
    if (fd < 0) { perror("fialed to open"); exit(EXIT_FAILURE); }


    // for loop to make the random values:
    for (int i = 0; i < 60; i++)
    {
        int randomno = rand() % 100;
        write(fd,&randomno,sizeof(int));
    }

    exit(x);
}
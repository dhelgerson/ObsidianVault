#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>



int main()
{
    int cpid,status,fd,numbers[60],sum;
    char filename[20];
    sum = 0;

    cpid = fork();
    if (cpid == 0)
    {
        // the child process
        execl("./myRand","myRand",(char*)NULL);
    }

    // figure out the returned status to find the filename
    waitpid(cpid,&status,0);
    sprintf(filename,"data%d.dat",WEXITSTATUS(status));
    // open file and check for errors
    fd = open(filename,O_RDONLY); if (fd < 0) { perror("error opening file");exit(EXIT_FAILURE); }
    // store numbers from file into an array
    read(fd,&numbers,60*sizeof(int));
    // go ahead and unlink the file since we already read it
    unlink(filename);    
    // print and sum the numbers
    for (int i = 0; i < 60; i++)
    {
        printf("%i ",numbers[i]);
        sum += numbers[i];
    }
    printf("\navg: %i\n",sum / 60);

    return 0;
}
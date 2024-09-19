#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/types.h>
#include <signal.h>
#include <math.h>

#include "globals.h"

int checkErr(int val, const char *msg)
{
    if (val == -1)
    {
        perror(msg);
        exit(EXIT_FAILURE);
    }
    return val;
}

void iRead()
{
    double angles[3];
    if (checkErr(read(angl,&angles,3*sizeof(double)),"reading file") == 0)
    {
	    exit(0);
    }
    for (int i = 0;i < 3;i++)
    {
        printf("%lf",angles[i]);
        if (fabs(angles[i]) > 20)
        {
            printf("*");
        }
        printf(" ");
    }
    printf("\n");
}

void sigHndl(int sig)
{
    if (sig == SIGUSR1)
    {
        const char *msg = "Handling SIGUSR1\n";
        write(STDOUT_FILENO, msg,strlen(msg));
    }
    if (sig == SIGALRM)
    {
        // printf("timer went off\n");
        iRead();
    }
}

int main()
{
    printf("Roll, Pitch, Yaw: values outside -20,20 have '*'\n");
    angl = checkErr(open("angl.dat",O_RDONLY),"opening file");

    iRead();

    // signal handler setup(pls don't kill me mr linux sir UwU)
    struct sigaction sa;
    sa.sa_handler = sigHndl;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGALRM,&sa,NULL);
    
    //timer setup
    struct itimerval it_val = {1,0,1,0}; // interval(s), interval(us),value(s),values(us)
    checkErr(setitimer(ITIMER_REAL,&it_val, NULL),"failed to set timern");
    
    while(1) { pause(); }

    return 0;
}

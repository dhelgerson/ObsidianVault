#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <dirent.h>
#include <signal.h>
#include <sys/types.h>

int checkerr(int val, const char *msg)
{
    if (val == -1)
    {
        perror(msg);
        exit(EXIT_FAILURE);
    }
    return val;
}

void sigHndl(int sig)
{
    if (sig == SIGUSR1)
    {
        const char *msg = "Handling SIGUSR1\n";
        write(STDOUT_FILENO, msg,strlen(msg));
    }
}

int main()
{
    struct sigaction sa;
    sa.sa_handler = sigHndl;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    

    pid_t pid;

    pid = getpid();

    pid_t cpid = checkerr(fork(),"fork");

    if (cpid == 0)
    {
        sigaction(SIGUSR1,&sa,NULL);
        printf("Child: parent has pid of %d\n",pid);
        printf("Child: Pausing\n");
        pause();
        printf("Child: Stopping\n");
    }
    else
    {
        printf("parent: process id is %d\n",pid);
        printf("parent: child pid is %d\n",cpid);
        sleep(1);
        kill(cpid,SIGUSR1);
    }

    printf("both run this\n");

    return 0;
}
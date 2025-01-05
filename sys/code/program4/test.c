#include <sys/types.h>
#include <stdlib.h>
#include <signal.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int sigHndlr(int sig)
{
    if (sig == SIGINT)
    {
        const char *msg = "Are you sure you'd like to exit?: (Y/n)";
        write(STDOUT_FILENO, msg, strlen(msg));
        char ans = NULL;
        read(STDIN_FILENO,ans,sizeof(char));
        if (ans == 'n')
        {
            return;
        }
        exit(EXIT_SUCCESS);
    }
}
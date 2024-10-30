#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <wait.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <dirent.h>

int main()
{
    int fd[2];
    const int BSIZE = 100;
    char buf[BSIZE];
    ssize_t nbytes;
    int status;

    status = pipe(fd);
    if (status == -1) { perror("err creating pipe"); exit(EXIT_FAILURE); }

    pid_t parentPid,childPid;

    return 0;
}
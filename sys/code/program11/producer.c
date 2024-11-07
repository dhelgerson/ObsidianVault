#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// #include <signal.h>
// #include <wait.h>
#include <string.h>
#include <fcntl.h>
// #include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
// #include <dirent.h>

#include "readline.h"

int main()
{
    // variables
    char *msg;
    const char *prompt = "Please enter text at the producer: ";
    int status,fifo_fd;
    // setup
    status = mkfifo("./stream",0600);
    // execution
    status = write(STDOUT_FILENO,prompt,strlen(prompt));
        if (status == -1){ perror("write prompt"); exit(EXIT_FAILURE);}
    msg = readline(STDIN_FILENO);
    fifo_fd = open("./stream",O_WRONLY);
        if (fifo_fd == -1){ perror("open ./stream"); exit(EXIT_FAILURE);}
    write(fifo_fd,msg,strlen(msg));


    // cleanup
    unlink("./stream");

    return 0;
}
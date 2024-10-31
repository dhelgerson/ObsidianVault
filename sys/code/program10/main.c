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

char *readline(int fd)
{
    char *output,*tmp;
    output = (char*)malloc(1);
    output[0] = '\0';
    int index = 0;
    char chr;
    size_t size;
    while (read(fd,&chr,1))
    {
        // printf("%c",chr); // debugging
        if (chr == '\n') { break; }
        if (errno == EINTR) { errno = 0; break; }
        size = strlen(output);
        tmp = (char*)malloc(size+2);
        tmp[size+1] = '\0';
        strcpy(tmp,output);
        free(output);
        tmp[size] = chr;
        output = tmp;
        chr = '~';
    }
    return output;
}

int main()
{
    int fd[2];
    const int BSIZE = 100;
    char buf[BSIZE];
    ssize_t nbytes;
    int status;
    pid_t cpid;
    char *msg = (char*)malloc(1000);

    status = pipe(fd);
    if (status == -1) { perror("err creating pipe"); exit(EXIT_FAILURE); }

    cpid = fork();

    if (cpid == 0)
    {
        // Child's code
        close(fd[1]); // close write side of pipe

        const char *prompt = "child: ";
        status = read(fd[0],msg,1000);
        if (status == -1) { perror("child reading pipe"); exit(EXIT_FAILURE); }
        write(STDOUT_FILENO,prompt,strlen(prompt));
        write(STDOUT_FILENO,msg,strlen(msg));
        write(STDOUT_FILENO,"\n",1);
        
        return 0;
    }

    // Parent's code
    close(fd[0]); // close read side

    const char *prompt = "parent: ";
    status = write(STDOUT_FILENO,prompt,strlen(prompt)); // parent's prompt
    if (status == -1) { perror("parent writing pipe"); exit(EXIT_FAILURE); }
    msg = readline(STDIN_FILENO);
    write(fd[1],msg,strlen(msg));
    
    wait(NULL);
    return 0;
}
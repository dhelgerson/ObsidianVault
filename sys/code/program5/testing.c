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
#include <string.h>

int checkErr(int val, const char *msg)
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
    if (sig == SIGALRM)
    {
        // what do when timer go off
    }
    if (sig == SIGINT)
    {
        const char *msg = "are you sure you want to quit? (y/N)\n";
        char *ans = (char*)malloc(50);
        write(STDOUT_FILENO,msg,sizeof(msg));
        read(STDIN_FILENO,ans,50);
    }
}

char *readline(int fd)
{
    char *output,*tmp;
    output = (char*)malloc(1);
    output[0] = '\0';
    int index = 0;
    char chr;
    size_t size;
    while (checkErr(read(fd,&chr,1),"reading"))
    {
        // printf("%c",chr); // debugging
        if (chr == '\n') { break; }
        size = strlen(output);
        tmp = (char*)malloc(size+2);
        tmp[size+1] = '\0';
        strcpy(tmp,output);
        free(output);
        tmp[size] = chr;
        output = tmp;
    }
    return output;
}

int main()
{
    int fd = open("afile.txt",O_RDONLY);
    char *oneline = readline(fd);
    if (!oneline[0]) { printf("false"); }
    printf("-%c-\n",oneline[0]);

    return 0;
}

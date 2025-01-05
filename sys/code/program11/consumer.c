#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#include "readline.h"

int main()
{
    int fd;
    const char *msg;
    const char *prompt = "consumer: ";
    fd = open("./stream",O_RDONLY);
    msg = readline(fd);
    write(STDOUT_FILENO,prompt,strlen(prompt));
    write(STDOUT_FILENO,msg,strlen(msg));
    write(STDOUT_FILENO,"\n",1);

    return 0;    
}
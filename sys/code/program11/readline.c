#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

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


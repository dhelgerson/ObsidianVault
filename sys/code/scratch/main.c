#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <dirent.h>

int checkerr(int val, const char *msg)
{
    if (val == -1)
    {
        perror(msg);
        exit(EXIT_FAILURE);
    }
    return val;
}

int main()
{
    DIR *dir;
    struct dirent *d;

    dir = opendir(".");
    if (dir == NULL)
    {
        perror("opendir failed :(");
        exit(EXIT_FAILURE);
    }
    
    while (1)
    {
        d = readdir(dir);
        if (d == NULL) {break;}
        printf("%s\n",d->d_name);
    }

    closedir(dir);
    return 0;
}
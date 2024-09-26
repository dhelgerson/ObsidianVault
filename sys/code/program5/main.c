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
        if (errno == EINTR) { break; }
        // if (chr == '�') { break; }
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
        printf("\nTime has elapsed, moving on\n");
    }
    if (sig == SIGINT)
    {
        const char *msg = "are you sure you want to quit? (y/N)\n";
        write(STDOUT_FILENO,msg,sizeof(msg));
        char *ans = readline(STDIN_FILENO);
        if (ans == "y") { exit(EXIT_SUCCESS); }
    }
}

int main()
{
    // signal handler setup(pls don't kill me mr kernel sir UwU)
    struct sigaction sa;
    sa.sa_handler = sigHndl;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGALRM,&sa,NULL);

    // open files
    int questions = checkErr(open("quest.txt",O_RDONLY),"opening questions");
    int answers = checkErr(open("ans.txt",O_RDONLY),"opening answers");
    int pts,total;
    pts = 0;
    total = 0;
    char *question,*answer,*response;
    
    
    //let the user know what's going on before it begins
    printf("You're about to take a timed quiz. You will have 15seconds to answer each question. THIS QUIZ DOES NOT ALLOW TYPOS (Ctrl+C to exit)\nare you ready? (Y/n)\n");

    answer = (char*)malloc(20);
    read(STDIN_FILENO,answer,1);
    // printf("-%s-",answer);
    if (answer[0] == 'n') { perror("exiting, coward"); exit(EXIT_FAILURE); }
    free(answer);

    printf("beginning:\n");
    
    //timer setup
    struct itimerval it_val = {0,0,5,0}; // interval(s), interval(us),value(s),values(us)
    checkErr(setitimer(ITIMER_REAL,&it_val, NULL),"failed to set timer");

    //main quiz loop:
    
    while(1) 
    {
        question = readline(questions);
        if (!question[0]) { break; }
        answer = readline(answers);
        printf("%s\n",question);
        response = readline(STDIN_FILENO);
        printf("-%s-\n",response);
        printf("%d\n",strcmp(answer,response));

        if (strcmp(answer,response) == 0) { pts++; }
        total++;

        free(question);
        free(answer);
    }

    printf("score: %d/%d\n",pts,total);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <wait.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

pid_t child_pid;

void handle_sigchld(int sig) 
{
    int saved_errno = errno;
    pid_t pid;
    
    while ((pid = waitpid(-1, NULL, WNOHANG)) > 0) 
    {
        if (pid == child_pid) 
        {
            printf("Child process terminated.\n");
            child_pid = 0; // Reset child PID
        }
    }
    
    if (pid == 0) 
    {
        printf("No children remaining.\n");
        // exit(EXIT_SUCCESS);
    }

    errno = saved_errno; // Restore errno
}

void handle_sigint(int sig) 
{
    char response;
    printf("Exit: Are you sure (Y/n)?\n");
    response = getchar();
    if (response == 'Y' || response == 'y') 
    {
        if (child_pid > 0) 
        {
            kill(child_pid, SIGTERM); // Send SIGTERM to child
        }
        exit(0);
    }
}

void handle_sigusr1(int sig) { printf("Warning! Roll outside of bounds\n"); }
void handle_sigusr2(int sig) { printf("Warning! Pitch outside of bounds\n"); }

void setup_signal_handlers() 
{
    struct sigaction sa;

    sa.sa_handler = handle_sigchld;
    sa.sa_flags = SA_RESTART | SA_NOCLDSTOP;
    sigaction(SIGCHLD, &sa, NULL);

    sa.sa_handler = handle_sigint;
    sigaction(SIGINT, &sa, NULL);

    sa.sa_handler = handle_sigusr1;
    sigaction(SIGUSR1, &sa, NULL);

    sa.sa_handler = handle_sigusr2;
    sigaction(SIGUSR2, &sa, NULL);
}

int checkError(int val, const char *msg)
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
    setup_signal_handlers();

    child_pid = fork();
    if (child_pid < 0) 
    {
        perror("Fork");
        exit(EXIT_FAILURE);
    }

    // Child process
    if (child_pid == 0) 
    {
        sigset_t mask;
        sigemptyset(&mask);
        sigaddset(&mask, SIGINT);
        sigprocmask(SIG_BLOCK, &mask, NULL);

        int file = checkError(open("angl.dat", O_RDONLY), "Failed to open");
        double data[3];
        int numread;
        while (checkError(numread = read(file, data, 3 * sizeof(double)), "Failed to read") > 0) 
        {
            if (data[0] < -20.0 || data[0] > 20.0) 
            {
                kill(getppid(), SIGUSR1);
            }
            if (data[1] < -20.0 || data[1] > 20.0) 
            {
                kill(getppid(), SIGUSR2);
            }
            sleep(1); // Read a triple every second
        }

        close(file);
        exit(0);
    }

    // Parent process
    // Wait for signals
    while (1) 
    { 
        pause(); 
    }

    return 0;
}
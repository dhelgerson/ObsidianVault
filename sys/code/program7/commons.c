#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int checkerr(int val, const char *msg) { if (val == -1){ perror(msg); exit(EXIT_FAILURE); } }

void handlersetup(void *handler)
{
    struct sigaction sa;
    sa.sa_handler = handler;
    // sa.sa_flags = SA_RESTART | SA_NOCLDSTOP;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    sigaction(SIGKILL, &sa, NULL);
    sigaction(SIGINT, &sa, NULL);
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <wait.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

// #pragma once
#include "globals.h"
#include "commons.h"
#include "players.h"
#include "handlers.h"

pid_t ref_pid, player1_pid, player2_pid;

int main()
{
    ref_pid = getpid();
    player1_pid, player2_pid = 0,0;
    pid_t pid = fork();
    if (pid == 0)
    {
        // player1 code
        struct sigaction sa;
        sa.sa_handler = player2sighandler;
        sa.sa_flags = 0;
        sigemptyset(&sa.sa_mask);
        sigaction(SIGUSR1, &sa, NULL);
        sigaction(SIGUSR2, &sa, NULL);
        sigaction(SIGKILL, &sa, NULL);
        sigaction(SIGINT, &sa, NULL);
        player1();
        printf("player1 lives\n");
        exit(EXIT_SUCCESS);
    }
    player1_pid = pid;
    pid = fork();
    if (pid == 0)
    {
        // player2 code
        struct sigaction sa;
        sa.sa_handler = player1sighandler;
        sa.sa_flags = 0;
        sigemptyset(&sa.sa_mask);
        sigaction(SIGUSR1, &sa, NULL);
        sigaction(SIGUSR2, &sa, NULL);
        sigaction(SIGKILL, &sa, NULL);
        sigaction(SIGINT, &sa, NULL);
        player2();
        printf("player2 lives\n");
        exit(EXIT_SUCCESS);
    }
    player2_pid = pid;
    // at this point player1 and 2 should be forked and running their functions
    printf("setup done\n");
    // setting up the parent's signal handlers
    struct sigaction sa;
    sa.sa_handler = parentsighandler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    sigaction(SIGKILL, &sa, NULL);
    sigaction(SIGINT, &sa, NULL);
    // from here we should be doing everything with signals, 
    // so we'll wait for those
    while (1) { pause(); }
    printf("parent pid: %i, player1 pid: %i, player2 pid %i\n", ref_pid, player1_pid, player2_pid); // for debug purposes

    return 0;
}
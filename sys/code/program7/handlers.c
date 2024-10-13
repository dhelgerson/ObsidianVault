#include <stdlib.h>
#include <signal.h>
#include <wait.h>
#include <errno.h>
#include <stdio.h>

// #pragma once
#include "globals.h"
#include "players.h"

void parentsighandler(int sig)
{
    pid_t pid;

    if (sig == SIGCHLD)
    {
        int serrno = errno;
        pid_t pid = waitpid(-1,NULL,WNOHANG);
        if (pid == 0) { printf("SIGCHLD handed but no child reaped"); exit(EXIT_SUCCESS); }
        errno = serrno;
    }
    if (sig == SIGUSR1)
    {
        if (player1_status == -1 && player2_status == -1) { kill(-1,SIGINT); return; }
        if (player1_status < NUM) { kill(player1_pid,SIGUSR1); return; }
        if (player1_status > NUM) { kill(player1_pid,SIGUSR2); return; }
        if (player1_status == NUM) { printf("player1 wins\n"); kill(ref_pid,SIGINT); }
        return;
    }
    if (sig == SIGUSR2)
    {
        if (player1_status == -1 && player2_status == -1) { kill(-1,SIGINT); return; }
        if (player2_status < NUM) { kill(player2_pid,SIGUSR1); return; }
        if (player2_status > NUM) { kill(player2_pid,SIGUSR2); return; }
        if (player2_status == NUM) { printf("player2 wins\n"); kill (ref_pid,SIGINT); }
        return;
    }
    if (sig == SIGINT)
    {
        kill(player1_pid,SIGINT);
        kill(player2_pid,SIGINT);
    }

}

void player1sighandler(int sig)
{
    pid_t pid;

    if (sig == SIGUSR1)
    {
        // handles low guess
        player1_response = -1;
    }
    if (sig == SIGUSR2)
    {
        // handles high guess
        player1_response = 1;
    }
    if (sig == SIGTERM){ exit(EXIT_SUCCESS); }
    if (sig == SIGINT)
    {
        //(re)start guessing
        player1_status, player2_status = 0,0;
    }

}
void player2sighandler(int sig)
{
    pid_t pid;

    if (sig == SIGUSR1)
    {
        // handles low guess
        player2_response = -1;
    }
    if (sig == SIGUSR2)
    {
        // handles high guess
        player2_response = 1;
    }
    if (sig == SIGTERM){ exit(EXIT_SUCCESS); }
    if (sig == SIGINT)
    {
        //(re)start guessing
        player2_status, player2_status = 0,0;
    }

}

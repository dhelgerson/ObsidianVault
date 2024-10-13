#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>

#include "globals.h"
#include "players.h"

int player1_status, player2_status;
int player1_response, player2_response;

void player1()
{
    int min = 0;
    int max = 100;
    int guess;

    // ready:
    player1_status = -1;
    // give the ref time to get setup
    sleep(1);
    // inform ref
    kill(ref_pid,SIGUSR1);
    // wait for response
    pause();
    while (1)
    {
        // store guess in the status
        guess = (max - min) / 2;
        // printf("player1 guessing: %i\n", guess);
        player1_status = guess;
        // inform the ref
        kill(ref_pid,SIGUSR1);
        // wait for reponse
        pause();
        if (player1_response == -1)
        {
            min = guess;
            player1_response = 0;
        }
        if (player1_response == 1)
        {
            max = guess;
            player1_response = 0;
        }
        if (player1_status == 0)
        {
            min = 0;
            max = 100;
            player1_status = -1;
        }
    }
}

void player2()
{
    int min = 0;
    int max = 100;
    int guess;

    player1_status = -1;
    // give the ref time to get setup
    sleep(1);
    kill(ref_pid,SIGUSR2);
    pause();
    while (1)
    {
        // random guess between min and max
        guess = (rand() % (max - min)) + min;
        // printf("player2 guessing: %i\n",guess);
        // inform the ref
        kill(ref_pid,SIGUSR2);
        // wait for a response
        pause();
        if (player2_response == -1) 
        {
            min = player2_status;
            player2_response = 0;
        }
        if (player2_response == 1)
        {
            max = player2_status;
            player2_response = 0;
        }
        if (player2_status == 0)
        {
            min = 0;
            max = 100;
            player2_status = -1;
        }
    }
}
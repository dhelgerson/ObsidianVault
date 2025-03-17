#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_array(int array[], int size) 
{   printf("%d",array[0]);
    for (int i = 1; i < size; ++i)
    { printf(", %d",array[i]); }
    printf("\n");
}

void fill_random(int array[], int size)
{   // seed the RNG: leave commented for testing
    srand(time(NULL));
    // loop through array, writing random number to each index
    for (int i = 0; i < size; ++i)
    { array[i] = rand() % size; }
    return;
}

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <time.h>

void fill_random(int array[], unsigned int size)
{
    // seed the RNG: leave commented for testing
    srand(time(NULL));
    // loop through array, writing random number to each index
    for (int i = 0; i < size; ++i)
    { array[i] = rand() % size; }
    return;
}

int main(int argc, char **argv)
{
    // we'll use argv[1] as the size of the matrix to sort:
    unsigned int n = atoi(argv[1]);

    // declare array of size n
    int array[n];
    // fill w/ random numbers 0 < x < n
    fill_random(array,n);



    return 0;
}
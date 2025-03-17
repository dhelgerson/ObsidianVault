#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <time.h>

#include "insertionsort.h"
#include "mergesort.h"

#define BILLION 1000000000L

void fill_random(int array[], int size)
{   // seed the RNG: leave commented for testing
    srand(time(NULL));
    // loop through array, writing random number to each index
    for (int i = 0; i < size; ++i)
    { array[i] = rand() % size; }
    return;
}

void print_array(int array[], int size) 
{   printf("%d",array[0]);
    for (int i = 1; i < size; ++i)
    { printf(", %d",array[i]); }
    printf("\n");
}

int main(int argc, char **argv)
{
    // we'll use argv[1] as the size of the matrix to sort:
    // check if arguments were supplied:
    if (argc < 2) { printf("argument size requried\n"); exit(1); }
    int size = atoi(argv[1]);

    // declare array w/ given size
    int array[size];
    // fill w/ random numbers 0 < x < n
    fill_random(array,size);
    // show random array before sorting:
    // print_array(array,size);
    
    // start timer
    struct timespec start, stop;
    clock_gettime(CLOCK_MONOTONIC, &start);
    // sort the array
    mergeSort(array,0,size);
    // stop timer
    clock_gettime(CLOCK_MONOTONIC, &stop);
    printf("%d,%llu,",size,BILLION * (stop.tv_sec - start.tv_sec) + stop.tv_nsec - start.tv_nsec);

    fill_random(array,size);
    // start timer
    clock_gettime(CLOCK_MONOTONIC, &start);
    // sort the array
    insertion_sort(array,size);
    // stop timer
    clock_gettime(CLOCK_MONOTONIC, &stop);
    printf("%llu\n",BILLION * (stop.tv_sec - start.tv_sec) + stop.tv_nsec - start.tv_nsec);

    return 0;
}
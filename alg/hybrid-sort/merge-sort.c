#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <time.h>

#include "libcommon.h"
#include "libmerge.h"

#define BILLION 1000000000L

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
    printf("merge-sort,%d,%llu\n",size,BILLION * (stop.tv_sec - start.tv_sec) + stop.tv_nsec - start.tv_nsec);

    return 0;
}
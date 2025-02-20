#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// checks if array is sorted
int is_sorted(int array[], size_t size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        if (array[i] > array[i+1]) { return 0; }
    }
    return 1;
}

// swap first element with second
void swap(int array[],int first,int second)
{
    int tmp = array[first];
    array[first] = array[second];
    array[second] = tmp;
}

// swaps each element w/ a random other element
void randomize(int array[], size_t size)
{
    for(int i = size - 1;  i > 0; --i) { 
        swap(array, i, rand() % (i+1)); 
    } 
}

void print_array(int array[],size_t size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d ",array[i]);
    }
    printf("\n");
}

int *random_array(int array[],size_t len)
{
    for (int i = 0; i < len; ++i)
    {
        array[i] = rand() % len + 1;
    }

    return array;
}

int main(int argc, char **argv)
{
    if (argc < 2) { printf("specify array len\n"); exit(1); }
    size_t len = atoi(argv[1]);
    int array[len];
    random_array(array,len);
    srand(time(NULL));

    while (is_sorted(array,len) != 1)
    {
       randomize(array,len); 
    }
    printf("sorted: ");
    print_array(array,len);

    return 0;
}
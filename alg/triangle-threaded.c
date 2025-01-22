#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// #define NUMTHREADS 96

int triangle(int n)
{
    int sum = 0;
    for (int j = 0; j <= n; j++)
    {
        sum += j;
    }
    return sum;
}

int divisible(int dividen, int divisor)
{
    if (dividen % divisor == 0) return 1;
    return 0;
}

struct args {
    int thread;
    int threads;
};

int best = 0;

void *run(void *input)
{
    struct args *args = (struct args *) input;
    int thread = args->thread;
    int threads = args->threads;

    int i = thread;
    int tri,divisors;

    // while(1)
    while(i < 20000)
    {
        divisors = 0;
        tri = triangle(i);

        for (int divisor = 1; divisor <= tri; divisor++)
        {
            if (divisible(tri,divisor) == 1)
            {
                divisors ++;
                continue;
            }
        }

        if (divisors > best)
        {
            best = divisors;
            printf("%i: %i\n",tri,divisors);
        }

        if (divisors > 500) exit(0);

        i += threads;
    }
        return 0;
}

int main(int argc, char *argv[])
{
        if (argc <= 1)
        {
                printf("incorrect num arguments");
        }
        int num_threads = atoi(argv[1]);
    pthread_t threads[num_threads];
    struct args *args[num_threads];

    for (int i = 0; i < num_threads; i++)
    {
        args[i] = (struct args *)malloc(sizeof(struct args));
        args[i]->thread = i + 1;
        args[i]->threads = num_threads;
        pthread_create(&threads[i], NULL, run, (void *)args[i]);
    }

    for (int i = 0; i < num_threads; i++)
    {
    pthread_join(threads[i], NULL);
    free(args[i]);
    }

    return 0;
}


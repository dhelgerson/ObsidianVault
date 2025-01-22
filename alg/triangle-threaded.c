#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define NUMTHREADS 16

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
                divisors++;
                continue;
            }
        }

        if (divisors > best)
        {
            best = divisors;
            printf("%i: %i\n",tri,divisors);
        }

        if (divisors > 500) break;

        i += threads;
    }
}

int main()
{
    pthread_t threads[NUMTHREADS];
    struct args *args[NUMTHREADS];

    for (int i = 0; i < NUMTHREADS; i++)
    {
        args[i] = (struct args *)malloc(sizeof(struct args));
        args[i]->thread = i + 1;
        args[i]->threads = NUMTHREADS;
        pthread_create(&threads[i], NULL, run, (void *)args[i]);
    }

    for (int i = 0; i < NUMTHREADS; i++)
    {
    pthread_join(threads[i], NULL);
    free(args[i]);
    }

    return 0;
}

#include <stdio.h>

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

int main()
{
    int i = 1;
    int best = 0;
    int tri,divisors;
    // printf("triangle(3): %i\n",triangle(3));
    // printf("divisible(3,3): %i\n",divisible(3,3));

    while(1)
    {
        divisors = 0;
        tri = triangle(i);
        // printf("%i: ",tri);
        for (int divisor = 1; divisor <= tri; divisor++)
        {
            // printf("%i %i\n", tri, divisor);
            if (divisible(tri,divisor) == 1)
            {
                divisors++;
                // printf("%i ",divisor);
                continue;
            }
        }
        // printf("= %i\n\n",divisors);
        if (divisors > best)
        {
            best = divisors;
            printf("%i: %i\n",tri,divisors);
        }

        if (divisors > 500) break;

        i++;
    }
}

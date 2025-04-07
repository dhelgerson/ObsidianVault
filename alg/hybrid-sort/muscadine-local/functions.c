#include <math.h>

int triangle(int n)
{
    int sum = 0;
    for (int j = 0; j <= n; j++)
    {
        sum += j;
    }
    return sum;
}

int divisors(int tri)
{
    int divisors = 0;
    for (int div = 1; div <= sqrt(tri); div++)
    {
        if (tri % div != 0) { continue; }
        if (div * div == tri)
        {
            divisors++;
            continue;
        }
        divisors += 2;
    }
    return divisors;
}

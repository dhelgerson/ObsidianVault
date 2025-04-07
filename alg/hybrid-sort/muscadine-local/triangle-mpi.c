#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <mpi.h>

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

int main (int argc, char** argv)
{
    int recv;
	//printf("testing\n");
    int processRank, clusterSize;
    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD, &clusterSize);
    MPI_Comm_rank(MPI_COMM_WORLD, &processRank);

    printf("I'm Rank %i of %i\n",processRank,clusterSize);

	MPI_Barrier(MPI_COMM_WORLD);

    if (processRank == 0)
    {
        // control process
        int range[] = {1,clusterSize};
        int *tasks[] = (int*)malloc(clusterSize * sizeof(int));
        for ( int i = range[0];i <= range[1]; i++)
        { tasks[i] = i; }
        // inform workers which roots to check
        MPI_Scatter(tasks,1,MPI_INT,&recv,1,MPI_INT,
        // wait for an answer from worker processes

        MPI_Finalize();
        return 0;
    }
    
    int i = processRank;
    while (1)
    {
        results[0] = triangle(i);
        results[1] = divisors(results[0]);
        // if (results[1] > 500)
        if (results[1] > atoi(argv[1]))
        {
            MPI_Send(&results[0],2,MPI_INT,0,0,MPI_COMM_WORLD);
            break;
        }
        i += clusterSize;
    }

    MPI_Finalize();
    return 0;
}

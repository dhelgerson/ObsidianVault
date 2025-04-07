#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#include "functions.h"

int main (int argc, char** argv)
{
    if (argc < 2)
    {
        printf("num divisors not specified, quitting\n");
        exit(1);
    }
    int processRank,clusterSize;
    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD,&clusterSize);
    MPI_Comm_rank(MPI_COMM_WORLD,&processRank);
    // printf("processRank: %i\n",processRank);
    // printf("clusterSize: %i\n",clusterSize);

    int i = 1;
    int recv;
    int kill = 0;
    int result[2];
    int *tasks,*results;
    if (processRank == 0)
    {
        tasks = (int*)malloc(clusterSize * sizeof(int));
        results = (int*)malloc(clusterSize * 2 * sizeof(int));
    }
    while (1)
    // while (i < 500)
    {
        if (processRank == 0)
        {
            if (kill == 1)
            { for (int task = 0;task < clusterSize; task++) { tasks[task] = 0; } }
            else
            { for (int task = 0;task < clusterSize; task++) { tasks[task] = i + task; } }
        }
        // distribute the work
        MPI_Scatter(tasks,1,MPI_INT,&recv,1,MPI_INT,0,MPI_COMM_WORLD);

        // check if the answer was found:
        if (recv == 0) { break; }

        // do the work
        result[0] = triangle(recv);
        result[1] = divisors(result[0]);
        // printf("%i %i %i\n",recv,result[0],result[1]);

        // gather the work
        MPI_Gather(&result,2,MPI_INT,results,2,MPI_INT,0,MPI_COMM_WORLD);

        if (processRank == 0)
        {
            // check for the answer
            for (int answer = 0; answer < clusterSize; answer++)
            {
                // printf("%i %i\n", results[answer * 2], results[answer * 2 + 1]);
                if (results[answer * 2 + 1] > atoi(argv[1]))
                {
                    printf("triangle number %i has %i divisors\n",results[answer*2],results[answer*2+1]);
                    kill = 1;
                }
            }
        }

        i+= clusterSize;
    }

    MPI_Finalize();
    
    return 0;
}
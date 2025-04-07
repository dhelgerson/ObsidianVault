#!/bin/sh
#SBATCH -o slurm.out --open-mode append
#SBATCH --cpus-per-task 96 --threads-per-core 2
# Note: command-line specified arguments override these values

hostname
#echo time ./triangle-threaded 1
#time ./triangle-threaded 1
echo time ./triangle-threaded ${SLURM_CPUS_PER_TASK}
time ./triangle-threaded ${SLURM_CPUS_PER_TASK}

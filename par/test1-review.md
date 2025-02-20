What is the command to login to ptolemy?
- `ssh tah568@ptolemy-login-1.arc.msstate.edu`
copying a file:
- `cp -r /some/source /some/dest`
vi:
- exit w/out save: `:q!`
- exit w/ save: `:wq`
load modules:
- `ml load spack-managed-x86_64-v3 openmpi`
compile:
	- `mpicc input.c -o output`
way to run a parallel job
- interactively - `srun`
- batch - `sbatch`
- remember `--account class-cse4163`
van noiman arch
- sequential
- cpu
- memory
- IO
- bus
- instructions and data in a shared memory
pipe-lining
- taking jobs and spreading them across hardware
caches
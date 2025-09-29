# Background
- `QP` - a queue pair, the bottom-most underlying construct for RDMA sends and receives
- `RC` - Reliable Connection, the original infiniband model for transports. sets up a connection between every individual rank in the communicator, leading to"$N-choose-2$ or $N\choose{2}$ connections where $N$ is the amount of ranks in the communicator. e.g. 1000 nodes w/ 40 ranks per node results in $799*10^6$ active connections over the fabric
- `DC` - Dynamic Connection, a mellanox-introduced transport layer on top of QP that uses pools of ranks in order to severely reduce the amount of active connections
# Problem
## Infiniband Protocol Spec
- The Mellanox ConnectX-6 (MT_0000000296) in Hercules-V1 nodes supports the infiniband specification version 1.4
- The Mellanox ConnectX-7 (DEL0000000050) in Hercules-V2 nodes supports the infiniband specification version 1.5
- A key difference between these specs is the `DC` implementation
# Workaround
With UCX, it's possible to disable the use of `DC`, this avoids the mismatch in implementation between the two cards
```bash
export UCX_TLS=rc,self,sm
```
I've read that it's possible to force UCX to use a `DC` implementation that's safe for both cards with:
```bash
export UCX_DC_MLX5_NUM_DCI=1
```
but I have not tested this
# Performance Implications
UCX chooses between RC and DC depending on the amount of ranks. This explains why the issue isn't present with few nodes. UCX makes this decision due to the trade-off in performance between the two, where RC has less latency, but more overhead, and DC has more latency, but less overhead. For very large jobs, such as the HPL hero run, this most likely contributes to a measurable decrease in performance.
# Other Transport Libraries
libfabric seems to be affected differently by this bug. with my current, limited knowledge of libfabric, I am unable to provide a workaround if one is needed.
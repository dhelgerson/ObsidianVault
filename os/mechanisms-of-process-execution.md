# Process Execution
- OS allocates memory
	- code and data
	- stack and heap
- points CPU program counter to current instruction
	- Other registers may store operands, return values, etc

## A function Call
- function calls translate to jump instruction
- a new stack frame is pushed
- position of PC is pushed to stack and moved to new position
## How is a syscall different?

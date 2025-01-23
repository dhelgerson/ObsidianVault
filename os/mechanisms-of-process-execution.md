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
- when a syscall must be made, a special trap instruction is run (usually by libc)
- trap instruction execution
	- move cpu to higher privilege level
	- switch to kernel stack
	- look up address in Interrupt descriptor table (IDT) and jump to trap handler function in OS code
- A #Context-Switch is when the OS saves the contents of the CPU registers to the stack of a precess and then sets up the registers for another process
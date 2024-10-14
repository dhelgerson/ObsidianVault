# Basic Architecture
## Early Computers
- mechanical calculators
- very limited
- used mechanical attributes to do things like add, subtract, multiply, and integrate
## Modern Computers
- of course we can do anything w/ modern computers
## Our Architecture
- Memory:
	- program code
	- working data
- CPU
	- ALU
	- registers:
		- data
		- address
	- PC
### Busses
We're going to tie all these together w/ **BUS's**
- control bus
	- handles which operation to execute
	- is controlled by the PC counter
- address bus
	- determines which part of memory is being looked at.
- data bus
	- where data is transported
- In any case, we use an assortment of MUX's and D'MUX's to correlate a binary integer with the correct operation (location in memory, instruction, etc; depending on bus)
- 
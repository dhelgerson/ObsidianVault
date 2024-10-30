// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)
//
// This program only needs to handle arguments that satisfy
// R0 >= 0, R1 >= 0, and R0*R1 < 32768.

// Put your code here.
@counter
M=0
@R2
M=0


// add r0 to r2, r1 times

(For)
@R1
D=M
@counter
D=D-M
@Done
D;JLE
@R0
D=M
@R2
M=M+D
@counter
M=M+1
@For
0;JMP

(Done)
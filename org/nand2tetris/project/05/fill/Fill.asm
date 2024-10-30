// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

@SCREEN
D=A
@screenStart
M=D

// Selects KBD (24576) and creates a variable
// based on the ending location of the screen
// NOTE: End of screen is 1 register before the KBD.
@KBD
D=A-1
@screenEnd
M=D


// Put your code here.

// variable last keeb input
@KBLast
M=0

@While
0;JMP

(FILL_INIT)
    @screenStart
    D=M 
    @currentLoc
    M=D

// Beginning of FILL loop
(FILL)
    // Sets our current location in memory 
    // based on our location variable
    // NOTE: This is pointer notation
    @currentLoc
    A=M
    M=-1 // fills the entire register

    // Checks if our current location is
    // at the end of the screen. Jumps to
    // CHECK_KEYBOARD if so
    @currentLoc
    D=M
    @screenEnd
    D=M-D
    @While
    D;JLE

    // Increments our current location
    // in the screen and restarts the 
    // FILL loop
	@currentLoc
	M=M+1
	@FILL
	0;JMP

(CLEAR_INIT)
    @screenStart
    D=M 
    @currentLoc
    M=D

(CLEAR)
    @currentLoc
    A=M
    M=0 // clears the entire register

    // Checks if our current location is
    // at the end of the screen. Jumps to
    // CHECK_KEYBOARD if so
    @currentLoc
    D=M
    @screenEnd
    D=M-D
    @While
    D;JLE

    // Increments our current location
    // in the screen and restarts the 
    // CLEAR loop
    @currentLoc
    M=M+1
    @CLEAR
    0;JMP
    

(While)
// while true:
//     read keyboard
    @KBD
    D=M    

//     if keeb state matches last keeb state:
//         continue
    @KBLast
    D=D-M
    @While
    D;JEQ

//     if keeb key false:
//         black screen function
    @KBD
    D=M
    @KBLast
    M=D
    @CLEAR_INIT
    D;JEQ

//     else (keeb key true):
//         white screen function
    @FILL_INIT
    D;JGT
//         continue
// import sys
// from os.path import exists as file_exists
const fs = require("fs");


// ### How to run the code ###

// # 1. Ensure that NodeJS is setup on your system (the code would need to changed for Deno or Bun)
// #   Run node --version to check

// #   python --version Output
// #       v23.1.0


// # 2. Go to the directory where your files are located 
// # You can check if your files are there by running "ls" in the terminal

// # 3. Run the following
// # node ./disassembler.js ./Add.hack



// # Check if appropriate file extension
var inFile = process.argv[2];
if (inFile.includes(".hack"))
{
    // Check if file exists
    if (fs.existsSync(inFile))
    {
        const Lines = fs.readFileSync(inFile, "utf8").split("\n");

        // List to be used for storing HACK instructions
        const hackList = []

        // Computation Dictionary
        let compTable = {
            "0101010": "0",
            "0111111": "1",
            "0111010": "-1",
            "0001100": "D",
            "0110000": "A",
            "1110000": "M",
            "0001101": "!D",
            "0110001": "!A",
            "1110001": "!M",
            "0001111": "-D",
            "0110011": "-A",
            "1110011": "-M",
            "0011111": "D+1",
            "0110111": "A+1",
            "1110111": "M+1",
            "0001110": "D-1",
            "0110010": "A-1",
            "1110010": "M-1",
            "0000010": "D+A",
            "1000010": "D+M",
            "0010011": "D-A",
            "1010011": "D-M",
            "0000111": "A-D",
            "1000111": "M-D",
            "0000000": "D&A",
            "1000000": "D&M",
            "0010101": "D|A",
            "1010101": "D|M"
        };

        // Destination Dictionary
        let destTable = {
            "000": "",
            "001": "M=",
            "010": "D=",
            "011": "DM=",
            "100": "A=",
            "101": "AM=",
            "110": "AD=",
            "111": "ADM="
        };

        // Jump Dictionary
        let jumpTable = {
            "000": "",
            "001": ";JGT",
            "010": ";JEQ",
            "011": ";JGE",
            "100": ";JLT",
            "101": ";JNE",
            "110": ";JLE",
            "111": ";JMP"
        };

        // Loop through all assembly lines in the HACK file
        for (const line of Lines)
        {
            // A Instruction
            // if - Check instruction op-code (the first char in the string)
                // Get the remaining substring and convert to decimal 
                // Conversion  (just uncomment)
                // var value = parseInt(line.substring(1, 16), 2);

                // Construct the appropriate HACK instruction
                // https://masteringjs.io/tutorials/fundamentals/string-concat

                // Append to hackList
                // https://daily.dev/blog/add-to-list-javascript-array-manipulation-basics

            // C Instruction
            // elif - Check instruction op-code (the first char in the string)
            
                // Create strings from the appropriate substrings
                // cBit, dBit, jBit
                // https://www.w3schools.com/jsref/jsref_substring.asp

                // Return HACK destination string from destTable using dBit
                // https://www.makeuseof.com/javascript-dictionaries-create-use/

                // Return HACK computation string from compTable using cBit

                // Return HACK jump string from jumpTable using jBit

                // Construct the appropriate HACK instruction

                // Append to hackList
        }

        // Write to file
        var outFile = inFile.replace(".hack", ".asm");
        fs.writeFileSync(outFile, hackList.join("\n"));
    }
}
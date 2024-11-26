import sys
from os.path import exists as file_exists


### How to run the code ###

# 1. Ensure that Python is setup on your system (Python 3)
# Run python --version to check

# python --version Output
#     Python 3.13.0


# 2. Go to the directory where your files are located 
# You can check if your files are there by running 'ls' in the terminal

# 3. Run the following
# python ./disassembler.py ./Add.hack

# You may need to change python to python3 if it fails for macOS or Ubuntu
# Windows sometimes needs py instead



# Check if appropriate file extension
if ".hack" not in sys.argv[1]:
    exit(ValueError)

# Check if file exists
if not file_exists(sys.argv[1]):
    exit(FileNotFoundError)

file = open(sys.argv[1], 'r')
Lines = file.readlines()

# List to be used for storing HACK instructions
hackList = []

# Computation Dictionary
compTable = {
    '0101010' : '0',
    '0111111' : '1',
    '0111010' : '-1',
    '0001100' : 'D',
    '0110000' : 'A',
    '1110000' : 'M',
    '0001101' : '!D',
    '0110001' : '!A',
    '1110001' : '!M',
    '0001111' : '-D',
    '0110011' : '-A',
    '1110011' : '-M',
    '0011111' : 'D+1',
    '0110111' : 'A+1',
    '1110111' : 'M+1',
    '0001110' : 'D-1',
    '0110010' : 'A-1',
    '1110010' : 'M-1',
    '0000010' : 'D+A',
    '1000010' : 'D+M',
    '0010011' : 'D-A',
    '1010011' : 'D-M',
    '0000111' : 'A-D',
    '1000111' : 'M-D',
    '0000000' : 'D&A',
    '1000000' : 'D&M',
    '0010101' : 'D|A',
    '1010101' : 'D|M'
}

# Destination Dictionary
destTable = {
    '000' : '',
    '001' : 'M=',
    '010' : 'D=',
    '011' : 'DM=',
    '100' : 'A=',
    '101' : 'AM=',
    '110' : 'AD=',
    '111' : 'ADM='
}

# Jump Dictionary
jumpTable = {
    '000' : '',
    '001' : ';JGT',
    '010' : ';JEQ',
    '011' : ';JGE',
    '100' : ';JLT',
    '101' : ';JNE',
    '110' : ';JLE',
    '111' : ';JMP'
}

# Loop through all assembly lines in the HACK file
for line in Lines:
    print(line)

    # A Instruction
        
    # if - Check instruction op-code (the first char in the string)
    if line[0] == '0':

        # Get the remaining substring and convert to decimal 
        # Conversion (just uncomment)
        value = int(line[1:16], 2)
        print(f"@{value}")
        hackList.append(f"@{value}\n")
        continue
        # Construct the appropriate HACK instruction
        # https://www.geeksforgeeks.org/python-string-concatenation/

        # Append to hackList
        # https://www.geeksforgeeks.org/python-list-append-method/

    # C Instruction
    # elif - Check instruction op-code (the first char in the string)
    line = (f"{destTable[line[10:13]]}{compTable[line[3:10]]}{jumpTable[line[13:16]]}\n")
    print(line.rstrip())
    hackList.append(line)
    # print(f"{line[13:16]}\n")
        
        # Create strings from the appropriate substrings
        # cBit, dBit, jBit
        # https://www.geeksforgeeks.org/string-slicing-in-python/

        # Return HACK destination string from destTable using dBit
        # https://www.geeksforgeeks.org/python-dictionary/?ref=lbp

        # Return HACK computation string from compTable using cBit

        # Return HACK jump string from jumpTable using jBit

        # Construct the appropriate HACK instruction

        # Append to hackList

# Write to file
file = open(sys.argv[1].replace('.hack', '.asm'), 'w')
file.writelines(hackList)
file.close()

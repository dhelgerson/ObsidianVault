#!/usr/bin/env bash
date
echo "Compiling intro_tah568.cpp..."
g++ intro_tah568.cpp -o intro_tah568
echo "Running program first time..."
./intro_tah568
echo "Running program second time, saving output..."
./intro_tah568 > my.out
echo "Comparing with expected..."
diff -y expected.out my.out
echo "Current user is: $(whoami)"

animal: animal.o main.o
    g++ animal.o main.o -o animal

animal.o: animal.cpp animal.h
    g++ -c animal.cpp

main.o: main.cpp animal.h
    g++ -c main.cpp


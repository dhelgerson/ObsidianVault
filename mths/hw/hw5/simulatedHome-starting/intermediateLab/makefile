animal: main.o animal.o
	g++ main.o animal.o -o animal

animal.o: animal.cpp animal.h
	g++ -c animal.cpp

main.o: main.cpp animal.h
	g++ -c main.cpp

clean:
	rm *.o animal

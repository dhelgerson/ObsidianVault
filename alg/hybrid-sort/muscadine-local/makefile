CFLAGS+=-lm
triangle: rewrite.o functions.o
	mpicc $^ $(CFLAGS) -o $@

%.o: %.c
	mpicc $^ $(CFLAGS) -c

clean:
	rm -f *.o triangle
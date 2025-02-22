####################################################
# Compile all .c files into "executible" w/ cflags #
####################################################

# name of executible:
executible = hybrid-sort

# get objects needed
objects = $(patsubst %.c, %.o, $(wildcard *.c))

$(executible): $(objects)
	gcc $(CFLAGS) $(LDFLAGS) $^ -o $@

%.o: %.c
	gcc $(CFLAGS) $^ -c

clean: 
	rm -r *.o hybrid-sort
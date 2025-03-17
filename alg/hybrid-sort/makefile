####################################################
# Compile all .c files into "executible" w/ cflags #
####################################################

all: hybrid-sort merge-sort instertion-sort

merge-sort: merge-sort.o libmerge.o libcommon.o
	gcc $(CFLAGS) $(LDFLAGS) $^ -o $@

insertion-sort: insertion-sort.o libsort.o libcommon.o
	gcc $(CFLAGS) $(LDFLAGS) $^ -o $@

hybrid-sort: hybrid-sort.o libmerge.o libsort.o libcommon.o
	gcc $(CFLAGS) $(LDFLAGS) $^ -o $@

%.o: %.c
	gcc $(CFLAGS) $^ -c

clean: 
	rm -r *.o merge-sort insertion-sort hybrid-sort &> /dev/null; true
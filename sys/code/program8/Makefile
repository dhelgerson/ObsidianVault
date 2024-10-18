SRCS := $(wildcard *.c)
PRGS := $(patsubst %.c,%,${SRCS})

all: ${PRGS}

%: %.c
	gcc $< -o $@

list:
	echo ${SRCS}

clean:
	rm -rf ${PRGS}

run: all
	./program8
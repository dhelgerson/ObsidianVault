program_name = program10

MAKEFLAGS="-j 16"

SRCS := $(wildcard *.c)
HDRS := $(wildcard *.h)
OBJS := $(patsubst %.c,%.o,$(SRCS))

${program_name}: $(OBJS) $(HDRS)
	cc ${OBJS} -o ${program_name}

%.o: %.c
	cc -c $< -o $@

run: ${program_name}
	./${program_name}

list:
	echo ${OBJS}
	echo ${HDRS}

clean:
	rm -rf ${program_name} *.o
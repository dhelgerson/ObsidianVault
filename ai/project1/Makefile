program_name = nqueens

MAKEFLAGS="-j 16"

CC = g++

DEBUG = '-g'

SRCS := $(wildcard *.cpp)
HDRS := $(wildcard *.h)
OBJS := $(patsubst %.cpp,%.o,$(SRCS))

${program_name}: $(OBJS) $(HDRS)
	${CC} ${OBJS} ${DEBUG} -o ${program_name}

%.o: %.cpp
	${CC} ${DEBUG} -c $< -o $@

run: ${program_name}
	./${program_name}

list:
	echo ${OBJS}
	echo ${HDRS}

clean:
	rm -rf ${program_name} *.o
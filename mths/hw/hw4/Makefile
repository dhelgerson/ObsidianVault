program_name = main

MAKEFLAGS=-j8

CXX = g++

# SRCS := $(wildcard *.cpp)
SRCS := greeting.cpp main.cpp
HDRS := $(wildcard *.h)
OBJS := $(patsubst %.cpp,%.o,$(SRCS))

${program_name}: $(OBJS) $(HDRS)
	${CXX} ${OBJS} -o ${program_name}

%.o: %.cpp
	${CXX} -c $< -o $@

run: ${program_name}
	./${program_name}

list:
	echo ${OBJS}
	echo ${HDRS}

clean:
	rm -rf ${program_name} *.o

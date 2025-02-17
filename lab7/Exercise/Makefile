# compile with gcc
CC=gcc

# Compiler options:
#
# -pg is used for profiling (gprof)
CFLAGS = -g -Wall -Werror

# Linker options:
#
# -lm: link with the math library
LDFLAGS += -lm

# set the name of the executable file to compile here
PROGRAM = main
LAB = test

OBJS = main.o avl.o
LAB_OBJS = avl.o avl_test.o

$(PROGRAM): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(PROGRAM)

$(LAB): $(LAB_OBJS)
	$(CC) $(CFLAGS) $(LAB_OBJS) $(LDFLAGS) -o $(LAB)

clean:
	rm -f $(PROGRAM) $(OBJS) $(LAB) $(LAB_OBJS)

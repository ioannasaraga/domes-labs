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
SWAP = swap
REV = reverse

OBJS = main.o bloom_filter.o ./customer/customer.o
LAB_OBJS = bloom_filter.o ./customer/customer.o bloom_filter_test.o
SWAP_OBJ = swap.o
REV_OBJ = reverse.o


$(PROGRAM): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(PROGRAM)

$(LAB): $(LAB_OBJS)
	$(CC) $(CFLAGS) $(LAB_OBJS) $(LDFLAGS) -o $(LAB)

$(SWAP): $(SWAP_OBJ)
	$(CC) $(CFLAGS) $(SWAP_OBJ) $(LDFLAGS) -o $(SWAP)

$(REV): $(REV_OBJ)
	$(CC) $(CFLAGS) $(REV_OBJ) $(LDFLAGS) -o $(REV)

clean:
	rm -f $(PROGRAM) $(OBJS) $(LAB) $(LAB_OBJS) $(SWAP) $(REV) $(SWAP_OBJ) $(REV_OBJ)

CC = g++
CCFLAGS = -Wall -Wextra -std=c++2a -g -O3 -Wno-unused-parameter -Wno-unused-variable
LIBFLAGS = -lcurl
SRC = $(wildcard *.cc)
HEADERS = $(wildcard *.h)
OBJ = $(SRC:%.cc=%.o)

a.out: $(OBJ)
	$(CC) $(CCFLAGS) $^ $(LIBFLAGS)

%.o: %.cc
	$(CC) $(CCFLAGS) -c $<

clean:
	rm -f a.out *.o

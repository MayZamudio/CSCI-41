CC = g++
CCFLAGS = -Wall -Wextra -std=c++2a -g -O3

a.out: main.cc queue.h ll.h
	$(CC) $(CCFLAGS) main.cc

clean:
	rm -f *.o core a.out generator

generator: generator.cc
	$(CC) $(CCFLAGS) -o generator generator.cc

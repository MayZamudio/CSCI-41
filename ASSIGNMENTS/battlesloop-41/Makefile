
CC = g++
CCFLAGS = -Wall -Wextra -std=c++2a -g -O3 -lzmq -lncursesw

all: server client main

main: main.cc
	 $(CC) $(CCFLAGS) -o main main.cc 


server: server.cc
	 $(CC) $(CCFLAGS) -o server server.cc 

client: client.cc
	 $(CC) $(CCFLAGS) -o client client.cc

clean:
	rm -f *.o core a.out server client

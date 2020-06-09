CC = g++
CCFLAGS = -Wall -Wextra -std=c++2a -g -O3 -lzmq -lncursesw

all: server client blockingclient

server: server.cc
	 $(CC) $(CCFLAGS) -o server server.cc 

client: client.cc
	 $(CC) $(CCFLAGS) -o client client.cc

blockingclient: blockingclient.cc
	 $(CC) $(CCFLAGS) -o blockingclient blockingclient.cc

clean:
	rm -f *.o core a.out server client

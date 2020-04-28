a.out: main.o ll.h
	g++ -g -Wall -std=c++17 main.o -fsanitize=address

main.o: main.cc ll.h
	g++ -g -Wall -std=c++17 -c main.cc

clean:
	rm -f a.out core *.o

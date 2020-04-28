a.out: main.o you.o 
	g++-9 -pthread -std=c++2a main.o you.o 

main.o: main.cc
	g++-9 -pthread -std=c++2a -c main.cc

you.o: you.cc
	g++-9 -pthread -std=c++2a -c you.cc

clean:
	rm -f a.out *.o core

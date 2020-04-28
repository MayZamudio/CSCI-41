a.out: stack.o main.o
	g++ -g -fsanitize=address -std=c++17 stack.o main.o

main.o: main.cc stack.h
	gcc -g -c -fsanitize=address -std=c++17 -fPIC main.cc

stack.o: stack.cc stack.h
	gcc -g -c -fsanitize=address -std=c++17 -fPIC stack.cc

clean:
	rm -f *.o a.out core

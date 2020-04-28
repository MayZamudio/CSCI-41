a.out: main.o complex.o imaginary.o
	g++ main.o complex.o imaginary.o

main.o: main.cc complex.h
	g++ -c main.cc

complex.o: complex.cc complex.h imaginary.h
	g++ -c complex.cc

imaginary.o: imaginary.h imaginary.cc
	g++ -c imaginary.cc

clean: 
	rm -f *.o core a.out


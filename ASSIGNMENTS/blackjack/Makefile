a.out: main.o card.o deck.o hand.o player.o
	g++ main.o card.o deck.o hand.o player.o
main.o: main.cc player.h hand.h deck.h 
	g++ -c main.cc
card.o: card.cc card.h
	g++ -c card.cc
deck.o: deck.cc card.h deck.h
	g++ -c deck.cc
hand.o: hand.cc card.h hand.h deck.h
	g++ -c hand.cc
player.o: player.cc player.h hand.h card.h
	g++ -c player.cc
clean:
	rm -f a.out *.o core

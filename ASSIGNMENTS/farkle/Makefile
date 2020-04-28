a.out: main.o menu.o die.o player.o table.o
	g++ main.o menu.o die.o player.o table.o

main.o: main.cc die.h player.h table.h
	g++ -c main.cc

menu.o: menu.cc menu.h
	g++ -c menu.cc

die.o: die.cc die.h
	g++ -c die.cc

player.o: player.cc player.h
	g++ -c player.cc

table.o: table.cc table.h
	g++ -c table.cc

clean:
	rm -f *.o a.out core

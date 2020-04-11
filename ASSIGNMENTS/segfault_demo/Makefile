a.out: segfault.cc
	g++ -w -g -fpermissive segfault.cc
	#g++ -w -g -fpermissive  -fsanitize=address segfault.cc

clean:
	rm a.out core outfile.txt

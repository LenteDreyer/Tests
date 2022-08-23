CC=g++ -std=c++11 -Wall -O3
map.o: map.cc map.hh
	$(CC) -o $@ -c $<
main: main.cc map.o
	$(CC) -o $@ $^
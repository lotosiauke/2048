./bin/2048 : main.o board.o
	g++ -g -I inc -std=c++11 main.o board.o -o ./bin/2048

main.o : src/main.cpp
	g++ -g -I inc -std=c++11 -c src/main.cpp

board.o: src/board.cpp inc/board.h
	g++ -g -I inc -std=c++11 -c src/board.cpp

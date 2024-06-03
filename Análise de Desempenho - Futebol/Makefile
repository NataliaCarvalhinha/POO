all: main.o funcoes.o 
	g++ -Wall -std=c++11 main.o funcoes.o -o programa
	
main.o: main.cpp
	g++ -Wall -std=c++11 -c main.cpp

funcoes.o: funcoes.cpp
	g++ -Wall -std=c++11 -c funcoes.cpp
	
clean: 
	rm -f *.o programa

run: all
	./programa
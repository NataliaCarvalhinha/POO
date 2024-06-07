all: ./programa
	g++ -o programa vertice.cpp aresta.cpp grafo.cpp main.cpp  && ./programa input.txt
	
clean: 
	rm -f *.o programa

run: all
	./programa input.txt
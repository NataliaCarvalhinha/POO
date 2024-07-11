all:
	g++ -std=c++11 main.cpp produto.cpp produtoComDesconto.cpp sistema.cpp conexao.cpp -o programa -I/usr/include/python3.10 -lpython3.10

run:
	./programa
	
clean: 
	rm -f *.o programa

run: all
	./programa
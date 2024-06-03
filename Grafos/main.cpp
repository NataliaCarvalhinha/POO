#include <iostream>

#include "grafo.h"

using namespace std;

int main () {
    Vertice vertice1 = Vertice("Ana");
    Vertice vertice2 = Vertice("Bruno");
    Vertice vertice3 = Vertice("Carlos");
    Vertice vertice4 = Vertice("Daniela");
    Vertice vertice5 = Vertice("Eduardo");
    Vertice vertice6 = Vertice("Fernanda");
    Vertice vertice7 = Vertice("Gabriel");
    Vertice vertice8 = Vertice("Helena");
    Aresta* aresta1  = new Aresta(&vertice1, &vertice2, 5);
    Aresta* aresta2  = new Aresta(&vertice1, &vertice3, 1);
    Aresta* aresta3  = new Aresta(&vertice2, &vertice3, 3);
    Aresta* aresta4  = new Aresta(&vertice4, &vertice5, 6);
    Aresta* aresta5  = new Aresta(&vertice3, &vertice5, 2);
    Aresta* aresta6  = new Aresta(&vertice7, &vertice8, 4);
    Aresta* aresta7  = new Aresta(&vertice2, &vertice6, 5);
    Aresta* aresta8  = new Aresta(&vertice1, &vertice5, 3);
    Aresta* aresta9  = new Aresta(&vertice3, &vertice7, 2);
    Aresta* aresta10 = new Aresta(&vertice1, &vertice3, 6);
    Aresta* aresta11 = new Aresta(&vertice1, &vertice4, 1);
    Aresta* aresta12 = new Aresta(&vertice5, &vertice6, 3);
    Aresta* aresta13 = new Aresta(&vertice7, &vertice5, 4);
    Aresta* aresta14 = new Aresta(&vertice6, &vertice8, 5);
    Aresta* aresta15 = new Aresta(&vertice2, &vertice7, 2);
    Aresta* aresta16 = new Aresta(&vertice3, &vertice8, 6);

    Grafo* grafo = new Grafo();

    grafo->incluirAresta(aresta1);
    grafo->incluirAresta(aresta2);
    grafo->incluirAresta(aresta3);
    grafo->incluirAresta(aresta4);
    grafo->incluirAresta(aresta5);
    grafo->incluirAresta(aresta6);
    grafo->incluirAresta(aresta7);
    grafo->incluirAresta(aresta8);
    grafo->incluirAresta(aresta9);
    grafo->incluirAresta(aresta10);
    grafo->incluirAresta(aresta11);
    grafo->incluirAresta(aresta12);
    grafo->incluirAresta(aresta13);
    grafo->incluirAresta(aresta14);
    grafo->incluirAresta(aresta15);
    grafo->incluirAresta(aresta16);


    int escolha;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Exibir a lista de enlaces e respectivos pesos existentes no grafo\n";
        cout << "2. Exibir a densidade do grafo\n";
        cout << "3. Exibir o vértice com maior centralidade de grau\n";
        cout << "4. Exibir (Algoritmo de Dijkstra)\n";
        cout << "5. Exibir o vértice com maior centralidade de proximidade\n";
        cout << "0. Sair\n";
        cout << "Digite sua escolha: ";
        cin >> escolha;

        switch (escolha) {
            case 0:
                cout << endl << "Saindo..." << endl << endl;
                return 0;
            case 1:
                cout << endl << "Lista de enlaces e pesos:  ";
                grafo->imprimir();
                cout << endl;
                break;
            case 2:
                cout << endl << "Densidade: ";
                grafo->imprimeDensidade();
                break;
            case 3:
                cout << endl << "Vertice com maior Centralidade de Grau: ";
                grafo->imprimeVerticeMaiorCentralidadeDeGrau();
                break;
            default:
                cout << endl << "Opção inválida!\n";
        }
        cout << endl;

    }
    return 0;

}


#include <iostream>

#include "grafo.h"

using namespace std;

int main () {
    Vertice vertice1 = Vertice("A");
    Vertice vertice2 = Vertice("B");
    Vertice vertice3 = Vertice("C");
    Aresta* aresta1 = new Aresta(&vertice1, &vertice2, 5.1);
    Aresta* aresta2 = new Aresta(&vertice1, &vertice3, 1);
    Grafo* grafo = new Grafo();

    grafo->incluirAresta(aresta1);
    grafo->incluirAresta(aresta2);


    grafo->imprimir();

    cout<<endl<<"Densidade: "<<grafo->getDensidade()<<endl;

    return 0;
}


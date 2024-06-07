#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <limits>
#include <queue>
#include <stack>


#include "aresta.h"

using namespace std;

class Grafo {

    public:
        Grafo();
        void incluirAresta(Aresta* aresta);
        void imprimir();
        void imprimeDensidade();
        void imprimeVerticeMaiorCentralidadeDeGrau();
        void imprimirCustoECaminho();
        void imprimeVerticeMaiorCentralidadeDeProximidade();

    private:
        vector<Aresta*> _arestas;
        set<Vertice*> _vertices;
        double calcularDensidade();
        double calcularCentralidadeDeGrau(Vertice* vertice);
        bool existeVertice(Vertice* vertice);
        Grafo* calcularMenorCaminhoComDijkstra(Vertice* origem, unordered_map<Vertice*, Aresta*>& arestaPredecessoras);

};

#endif // GRAFO_H

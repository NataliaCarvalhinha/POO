#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

#include "aresta.h"

using namespace std;

class Grafo {

    public:
        Grafo();
        void incluirAresta(Aresta* aresta);
        void imprimir();
        void imprimeDensidade();
        void imprimeVerticeMaiorCentralidadeDeGrau();

    private:
        vector<Aresta*> _arestas;
        set<Vertice*> _vertices;
        double calcularDensidade();
        double calcularCentralidadeDeGrau(Vertice* vertice);
};

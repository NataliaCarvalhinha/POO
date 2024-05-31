#include <iostream>
#include <vector>
#include <set>

#include "aresta.h"

using namespace std;

class Grafo {

    public:
        Grafo();
        void incluirAresta(Aresta* aresta);
        void imprimir();
        double getDensidade();

    private:
        vector<Aresta*> _arestas;
};

#include <iostream>
#include <string>
#include "vertice.h"

using namespace std;

class Aresta {

    public:
        Aresta(Vertice* vertice1, Vertice* vertice2, double peso);
        Vertice* getVertice1();
        Vertice* getVertice2();
        double getPeso();
        void imprimir();

    private:
        Vertice* _vertice1;
        Vertice* _vertice2;
        double _peso;

};

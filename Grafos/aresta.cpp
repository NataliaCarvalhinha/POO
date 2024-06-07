#include "aresta.h"

Aresta::Aresta(Vertice* vertice1, Vertice* vertice2, double peso){
    _vertice1 = vertice1;
    _vertice2 = vertice2;
    _peso = peso;
}
Vertice* Aresta::getVertice1(){
    return _vertice1;
}
Vertice* Aresta::getVertice2(){
    return _vertice2;
}
double Aresta::getPeso(){
    return _peso;
}
void Aresta::imprimir(){
    cout<<"<"<<(*_vertice1).getId()<<";"<<(*_vertice2).getId()<<">: "<<_peso;
}

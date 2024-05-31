#include "grafo.h"

Grafo::Grafo(){}

void Grafo::incluirAresta(Aresta* aresta){
    _arestas.push_back(aresta);
}

void Grafo::imprimir(){
    int tamanho = _arestas.size();
    cout<<"(";
    if(tamanho==0){
        cout<<"Grafo vazio";
    }
    for(int i = 0; i < tamanho; i++){
        (*_arestas[i]).imprimir();
        if(i < tamanho - 1){
            cout<<"; ";
        } 
    }
    cout<<")";
}

double Grafo::getDensidade(){
    set<Vertice*> vertices;
    for (const auto& aresta : _arestas) {
        vertices.insert(aresta->getVertice1());
        vertices.insert(aresta->getVertice2());
    }

    int totalVertices = vertices.size();
    double maximoArestas = (totalVertices*(totalVertices-1))/2;
    int totalArestas = _arestas.size();
    
    return totalArestas/maximoArestas;
}
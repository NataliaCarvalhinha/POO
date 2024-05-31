#include "grafo.h"

Grafo::Grafo(){}

void Grafo::incluirAresta(Aresta* aresta){
    _arestas.push_back(aresta);
    _vertices.insert(aresta->getVertice1());
    _vertices.insert(aresta->getVertice2());
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

double Grafo::calcularDensidade(){
    int totalVertices = _vertices.size();
    double maximoArestas = (totalVertices*(totalVertices-1))/2;
    int totalArestas = _arestas.size();
    
    return totalArestas/maximoArestas;
}

double Grafo::calcularCentralidadeDeGrau(Vertice* vertice) {
    double somaCentralidade = 0;
    for (auto& aresta : _arestas) {
        Vertice* vertice1 = aresta->getVertice1();
        Vertice* vertice2 = aresta->getVertice2();
        if (vertice1 == vertice) {
            somaCentralidade += aresta->getPeso();
        }
        // O else garante que o peso não será comado 2x caso o vertice aponte para ele mesmo
        else if (vertice2 == vertice) { 
            somaCentralidade += aresta->getPeso();
        }
    }
    return somaCentralidade;
}

void Grafo::imprimeDensidade() {
    cout << calcularDensidade();
}

void Grafo::imprimeVerticeMaiorCentralidadeDeGrau(){
    double maxCentralidade = 0.0;
    Vertice* maxCentralidadeVertice = NULL;
    bool primeiro = true;
    for (const auto& vertice : _vertices) {
        double centralidade = calcularCentralidadeDeGrau(vertice);
        if (centralidade > maxCentralidade || primeiro){
            primeiro = false;
            maxCentralidade = centralidade;
            maxCentralidadeVertice = vertice;
        }
    }
    cout << maxCentralidadeVertice->getId() << " (" << maxCentralidade << ")";
}
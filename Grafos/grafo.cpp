#include "grafo.h"


// Métodos públicos -------------------------------------------------------------------


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

void Grafo::imprimirCustoECaminho() {
    cout << "Digite o nome do vértice de origem: ";
    string nomeOrigem;
    cin >> nomeOrigem;

    cout << "Digite o nome do vértice de destino: ";
    string nomeDestino;
    cin >> nomeDestino;

    Vertice* origem = nullptr;
    Vertice* destino = nullptr;

    for (Vertice* vertice : _vertices) {
        if (vertice->getId() == nomeOrigem) {
            origem = vertice;
        }
        if (vertice->getId() == nomeDestino) {
            destino = vertice;
        }
    }

    if (origem == nullptr || destino == nullptr) {
        cout << "Um ou ambos os vértices não foram encontrados." << endl;
        return;
    }

    unordered_map<Vertice*, Aresta*> arestaPredecessoras;
    Grafo* menorCaminho = calcularMenorCaminhoComDijkstra(origem, arestaPredecessoras);

    if (!menorCaminho->existeVertice(destino)) {
        cout << "Não há caminho entre os vértices." << endl;
        delete menorCaminho;
        return;
    }

    double custoTotal = 0;
    stack<Vertice*> caminho;
    Vertice* verticeAtual = destino;

    while (verticeAtual != origem) {
        Aresta* arestaPredecessora = arestaPredecessoras[verticeAtual];
        caminho.push(verticeAtual);
        custoTotal += arestaPredecessora->getPeso();
        verticeAtual = (arestaPredecessora->getVertice1() == verticeAtual) ? arestaPredecessora->getVertice2() : arestaPredecessora->getVertice1();
    }
    caminho.push(origem);

    cout << "Custo entre " << origem->getId() << " e " << destino->getId() << ": " << custoTotal << endl;
    cout << "Caminho: ";
    while (!caminho.empty()) {
        cout << caminho.top()->getId() << " ";
        caminho.pop();
    }
    cout << endl;

    delete menorCaminho;
}

void Grafo::imprimeVerticeMaiorCentralidadeDeProximidade() {
    double maxCentralidade = 0.0;
    Vertice* verticeMaxCentralidade = nullptr;

    for (auto& vertice : _vertices) {
        unordered_map<Vertice*, double> distancias;
        priority_queue<pair<double, Vertice*>, vector<pair<double, Vertice*>>, greater<pair<double, Vertice*>>> distanciaEntreVertices;

        for (auto& v : _vertices) {
            distancias[v] = numeric_limits<double>::infinity();
        }

        distancias[vertice] = 0;
        distanciaEntreVertices.push({0, vertice});

        while (!distanciaEntreVertices.empty()) {
            Vertice* u = distanciaEntreVertices.top().second;
            distanciaEntreVertices.pop();

            for (auto& aresta : _arestas) {
                Vertice* vizinho = nullptr;

                if (aresta->getVertice1() == u) {
                    vizinho = aresta->getVertice2();
                } else if (aresta->getVertice2() == u) {
                    vizinho = aresta->getVertice1();
                }

                if (vizinho) {
                    double novaDistancia = distancias[u] + aresta->getPeso();
                    if (novaDistancia < distancias[vizinho]) {
                        distancias[vizinho] = novaDistancia;
                        distanciaEntreVertices.push({novaDistancia, vizinho});
                    }
                }
            }
        }

        double somaDistancias = 0.0;
        for (auto& [v, distancia] : distancias) {
            if (distancia < numeric_limits<double>::infinity()) {
                somaDistancias += distancia;
            }
        }

        double centralidade = (somaDistancias > 0) ? (1.0 / somaDistancias) : 0.0;

        if (centralidade > maxCentralidade) {
            maxCentralidade = centralidade;
            verticeMaxCentralidade = vertice;
        }
    }

    if (verticeMaxCentralidade) {
        cout << "Vértice com maior centralidade de proximidade: " << verticeMaxCentralidade->getId()
                  << " (Centralidade: " << maxCentralidade << ")" << endl;
    } else {
        cout << "Não foi possível determinar a centralidade de proximidade." << endl;
    }
}




// Métodos privados -------------------------------------------------------------------

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

bool Grafo::existeVertice(Vertice* procurado){
    for (const auto& vertice : _vertices){
        if (vertice == procurado){
            return true;
        }
    }
    return false;
}

Grafo* Grafo::calcularMenorCaminhoComDijkstra(Vertice* origem, unordered_map<Vertice*, Aresta*>& arestaPredecessoras) {
    unordered_map<Vertice*, double> distancia;
    set<Vertice*> verticesVisitados;
    priority_queue<pair<double, Vertice*>, vector<pair<double, Vertice*>>, greater<pair<double, Vertice*>>> distanciaEntreVertices;

    for (auto vertice : _vertices) {
        distancia[vertice] = numeric_limits<double>::infinity();
    }
    distancia[origem] = 0;
    distanciaEntreVertices.push(make_pair(0, origem));

    while (!distanciaEntreVertices.empty()) {
        Vertice* verticeAtual = distanciaEntreVertices.top().second;
        distanciaEntreVertices.pop();

        if (verticesVisitados.find(verticeAtual) != verticesVisitados.end()) {
            continue;
        }
        verticesVisitados.insert(verticeAtual);

        for (auto aresta : _arestas) {
            Vertice* verticeVizinho = nullptr;
            if (aresta->getVertice1() == verticeAtual) {
                verticeVizinho = aresta->getVertice2();
            } else if (aresta->getVertice2() == verticeAtual) {
                verticeVizinho = aresta->getVertice1();
            }

            if (verticeVizinho && verticesVisitados.find(verticeVizinho) == verticesVisitados.end()) {
                double novaDistancia = distancia[verticeAtual] + aresta->getPeso();

                if (novaDistancia < distancia[verticeVizinho]) {
                    distancia[verticeVizinho] = novaDistancia;
                    arestaPredecessoras[verticeVizinho] = aresta;
                    distanciaEntreVertices.push(make_pair(novaDistancia, verticeVizinho));
                }
            }
        }
    }

    Grafo* dijkstraResult = new Grafo();
    for (const auto& [vertice, aresta] : arestaPredecessoras) {
        if (aresta) {
            dijkstraResult->incluirAresta(new Aresta(aresta->getVertice1(), aresta->getVertice2(), aresta->getPeso()));
            dijkstraResult->imprimir();
        }
    }

    return dijkstraResult;
}

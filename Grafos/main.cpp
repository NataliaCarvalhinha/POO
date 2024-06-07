#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include "grafo.h"

using namespace std;

void lerCSV(const string& nomeArquivo, Grafo* grafo, unordered_map<string, Vertice*>& mapaVertices) {
    ifstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo " << nomeArquivo << endl;
        return;
    }

    string linha;
    while (getline(arquivo, linha)) {
        stringstream ss(linha);
        string vertice1, vertice2;
        double peso;

        ss >> vertice1 >> vertice2 >> peso;

        if (mapaVertices.find(vertice1) == mapaVertices.end()) {
            mapaVertices[vertice1] = new Vertice(vertice1);
        }
        if (mapaVertices.find(vertice2) == mapaVertices.end()) {
            mapaVertices[vertice2] = new Vertice(vertice2);
        }

        Aresta* aresta = new Aresta(mapaVertices[vertice1], mapaVertices[vertice2], peso);
        grafo->incluirAresta(aresta);
    }

    arquivo.close();
}

void exibirMenu() {
    cout << "\nMenu:\n";
    cout << "1. Exibir a lista de enlaces e respectivos pesos existentes no grafo\n";
    cout << "2. Exibir a densidade do grafo\n";
    cout << "3. Exibir o vértice com maior centralidade de grau\n";
    cout << "4. Exibir (Algoritmo de Dijkstra)\n";
    cout << "5. Exibir o vértice com maior centralidade de proximidade\n";
    cout << "0. Sair\n";
    cout << "Digite sua escolha: ";
}

void processarComando(Grafo* grafo, unordered_map<string, Vertice*>& mapaVertices, int escolha) {
    switch (escolha) {
        case 0:
            cout << endl << "Saindo..." << endl << endl;
            // Libera a memória alocada
            for (auto& par : mapaVertices) {
                delete par.second;
            }
            delete grafo;
            exit(0);
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
        case 4:
            cout << endl;
            grafo->imprimirCustoECaminho();
            cout << endl;
            break;
        case 5:
            cout << endl;
            grafo->imprimeVerticeMaiorCentralidadeDeProximidade();
            cout << endl;
            break;
        default:
            cout << endl << "Opção inválida!\n";
    }
}

int main(int argc, char* argv[]) {
    unordered_map<string, Vertice*> mapaVertices;
    Grafo* grafo = new Grafo();

    if (argc < 2) {
        cout << "Uso: " << argv[0] << " <nomeArquivoCSV> [comando]\n";
        cout << "Comandos (opcional):\n";
        cout << "  1 - Exibir a lista de enlaces e respectivos pesos existentes no grafo\n";
        cout << "  2 - Exibir a densidade do grafo\n";
        cout << "  3 - Exibir o vértice com maior centralidade de grau\n";
        cout << "  4 - Exibir (Algoritmo de Dijkstra)\n";
        cout << "  5 - Exibir o vértice com maior centralidade de proximidade\n";
        cout << "  0 - Sair\n";

        string nomeArquivo;
        cout << "Digite o nome do arquivo CSV: ";
        cin >> nomeArquivo;
        lerCSV(nomeArquivo, grafo, mapaVertices);

        int escolha;
        while (true) {
            exibirMenu();
            cin >> escolha;
            processarComando(grafo, mapaVertices, escolha);
        }
    } else {
        string nomeArquivo = argv[1];
        lerCSV(nomeArquivo, grafo, mapaVertices);

        if (argc == 3) {
            int escolha = atoi(argv[2]);
            processarComando(grafo, mapaVertices, escolha);
        } else {
            int escolha;
            while (true) {
                exibirMenu();
                cin >> escolha;
                processarComando(grafo, mapaVertices, escolha);
            }
        }
    }

    for (auto& par : mapaVertices) {
        delete par.second;
    }
    delete grafo;

    return 0;
}


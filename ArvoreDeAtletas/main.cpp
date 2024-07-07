#include "sistema.h"
#include "arvore.h"
#include "atleta.h"
#include "atletaTenis.h"
#include "atletaVolei.h"
#include <iostream>
#include <limits>

using namespace std;

void limpaBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    Sistema sistema;
    int opcao = 0;

    while (opcao != 5) {
        cout << "\n### Menu ###\n";
        cout << "1. Inserir Atleta\n";
        cout << "2. Buscar Atleta\n";
        cout << "3. Remover Atleta\n";
        cout << "4. Imprimir Atletas\n";
        cout << "5. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1: {
                string nome;
                cout << "Digite o nome do atleta: ";
                cin >> nome;
                limpaBuffer();

                int idade;
                cout << "Digite a idade do atleta: ";
                cin >> idade;
                limpaBuffer();

                int tipo;
                cout << "Escolha o tipo de atleta (0 - Padrão, 1 - Tênis, 2 - Vôlei): ";
                cin >> tipo;
                limpaBuffer();

                if (tipo == 1) {
                    int ranking;
                    cout << "Digite o ranking do jogador de tênis: ";
                    cin >> ranking;
                    limpaBuffer();

                    string estilo;
                    cout << "Digite o estilo de jogo do jogador de tênis (Fundo de quadra, Saque-voleio, Quadra-toda, Fundo de quadra agressivo): ";
                    cin >> estilo;
                    limpaBuffer();

                    sistema.insere(new AtletaTenis(nome, idade, ranking, estilo));

                } else if (tipo == 2) {
                    string posicao;
                    cout << "Digite a posição do jogador de vôlei (Libero, Oposto, Ponteiro, Central, Levantador): ";
                    cin >> posicao;
                    limpaBuffer();

                    sistema.insere(new AtletaVolei(nome, idade, posicao));
                    
                } else if (tipo == 0) {
                    sistema.insere(new Atleta(nome, idade));

                } else {
                    cout << "Opção inválida!" << endl;

                }

                break;
            }
            case 2: {
                string nome;
                cout << "Digite o nome do atleta a buscar: ";
                cin >> nome;
                limpaBuffer();

                Atleta* atletaAux = sistema.busca(nome);

                if (atletaAux != nullptr) {
                    cout << endl << "Atleta " << nome << " encontrado." << *atletaAux << endl;
                } else {
                    cout << endl << "Atleta " << nome << " não encontrado." << endl;
                }
                break;
            }
            case 3: {
                string nome;
                cout << "Digite o nome do atleta a remover: ";
                cin >> nome;
                limpaBuffer();

                sistema.remove(new Atleta(nome, 0));
                break;
            }
            case 4:
                cout << endl << "Lista de Atletas:" << endl;
                cout << sistema;
                break;
            case 5:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opção inválida!" << endl;
        }
    }

    return 0;
}

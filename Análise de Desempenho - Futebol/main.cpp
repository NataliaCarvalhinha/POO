#include <iostream>
#include <vector>

#include "lib.h"

using namespace std;


int main() {
    const int ANOS = 6;
    const int CAMPEONATOS = 2;
    const int N = 3; // Média móvel de 3 anos

    Time time1("Time A", 
        {{27, 22}, {16, 23}, {28, 21}, {20, 18}, {32, 19}, {19, 27}}, 
        {{22, 25}, {17, 27}, {16, 26}, {24, 17}, {23, 22}, {21, 20}});

    Time time2("Time B", 
        {{26, 30}, {20, 31}, {18, 25}, {23, 22}, {19, 26}, {30, 24}}, 
        {{31, 21}, {18, 31}, {33, 15}, {20, 23}, {28, 16}, {30, 23}});

    Time time3("Time C", 
        {{33, 21}, {16, 31}, {18, 27}, {29, 24}, {24, 21}, {29, 22}}, 
        {{33, 23}, {23, 16}, {31, 18}, {18, 17}, {24, 26}, {23, 15}});



    // Adicionar dados de outros campeonatos e para os outros times...

    Liga liga(ANOS, CAMPEONATOS, {time1, time2, time3});

    int escolha;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Exibir Evolução de Médias Móveis dos Times\n";
        cout << "2. Avaliar Desempenho dos Times\n";
        cout << "3. Exibir Time com Maior Evolução no Último Ano\n";
        cout << "4. Exibir Time com Maior Saldo de Gols por Campeonato\n";
        cout << "5. Mostrar Time com Maior Evolução no Último Ano\n";
        cout << "0. Sair\n";
        cout << "Digite sua escolha: ";
        cin >> escolha;

        switch (escolha) {
            case 1:
                liga.calcularMediasMoveis(N);
                break;
            case 2:
                liga.avaliarDesempenhoTimeNosCampeonatos(N);
                break;
            case 3:
                liga.avaliarDesempenhoTimeNoUltimoAno(N);
                break;
            case 4:
                liga.exibirTimeComMaiorSaldoDeGolsPorCampeonato();
                break;
            case 5:
                liga.mostrarTimeMaiorEvolucaoUltimoAno(N);
                break;
            case 0:
                cout << "Saindo...\n";
                return 0;
            default:
                cout << "Opção inválida!\n";
        }
    }

    return 0;
}
#include <iostream>
#include "historico.h"

using namespace std;

void exibirMenu() {
    cout << "\n--- Menu ---\n"
              << "1. Adicionar disciplina\n"
              << "2. Adicionar disciplinas em lote\n"
              << "3. Remover disciplina\n"
              << "4. Buscar disciplinas por período\n"
              << "5. Editar nota de disciplina\n"
              << "6. Calcular CRA\n"
              << "7. Imprimir histórico\n"
              << "8. Sair\n"
              << "Escolha uma opção: ";
}

int main(int argc, char* argv[]) {
    Historico historico(10);
    string nomeArquivo = "disciplinas.txt";

    historico.carregarDisciplinas(nomeArquivo);

    int opcao;
    do {
        exibirMenu();
        cin >> opcao;

        switch (opcao) {
            case 1: {
                Disciplina disciplina;
                cout << endl;
                cin >> disciplina;
                historico += disciplina;
                cout << endl;

                break;
            }
            case 2: {
                vector<Disciplina> novasDisciplinas;
                int quantidade;
                cout << endl;
                cout << "Quantas disciplinas deseja adicionar? ";
                cin >> quantidade;
                for (int i = 0; i < quantidade; ++i) {
                    Disciplina disciplina;
                    cin >> disciplina;
                    novasDisciplinas.push_back(disciplina);
                }
                historico += novasDisciplinas;
                cout << endl;
                break;
            }
            case 3: {
                string nomeDisciplina;
                cout << endl;
                cout << "Digite o nome da disciplina a ser removida: ";
                cin >> nomeDisciplina;
                historico -= nomeDisciplina;
                cout << endl;
                break;
            }
            case 4: {
                string periodo;
                cout << endl;
                cout << "Digite o período para busca: ";
                cin >> periodo;
                vector<Disciplina> disciplinasPeriodo = historico(periodo);
                cout << "Disciplinas do período " << periodo << ":\n";
                for (const auto& disciplina : disciplinasPeriodo) {
                    cout << disciplina << "\n";
                }
                cout << endl;
                break;
            }
            case 5: {
                string nomeDisciplina;
                cout << endl;
                cout << "Digite o nome da disciplina: ";
                cin >> nomeDisciplina;
                double& nota = historico[nomeDisciplina];
                if (nota != -1) {
                    cout << "Digite a nova nota: ";
                    cin >> nota;
                } else {
                    cout << "Disciplina '" << nomeDisciplina << "' não encontrada.\n";
                }
                cout << endl;
                break;
            }
            case 6: {
                double cra = 0.0;
                historico >> cra;
                cout << endl;
                cout << "CRA: " << cra << "\n";
                cout << endl;
                break;
            }
            case 7: {
                cout << historico;
                cout << endl;
                break;
            }
            case 8: {
                historico.salvarDisciplinas(nomeArquivo);
                cout << "Saindo...\n";
                break;
            }
            default: {
                cout << "Opção inválida! Tente novamente.\n";
                break;
            }
        }
    } while (opcao != 8);

    return 0;
}

#include <iostream>
#include <limits>
#include "sistema.h"
#include "produto.h"

using namespace std;

void limpaBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void menu() {
    cout << endl << endl;
    cout << "1. Inserir Produto" << endl;
    cout << "2. Remover Produto" << endl;
    cout << "3. Atualizar Produto" << endl;
    cout << "4. Buscar Produto por ID" << endl;
    cout << "5. Buscar Produto por Nome" << endl;
    cout << "6. Listar Produtos" << endl;
    cout << "0. Sair" << endl;
}

int main() {
    Sistema sistema;
    int opcao;
    Produto* produto;
    int id;
    string nome;
    int quantidade;
    double valor;
    int codigo;

    do {
        menu();
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "Digite o nome do produto: ";
                cin >> nome;
                limpaBuffer();
                cout << "Digite a quantidade: ";
                cin >> quantidade;
                cout << "Digite o valor: ";
                cin >> valor;
                produto = new Produto(nome, quantidade, valor, 0);
                sistema.inserir(produto);
                delete produto;
                break;
            case 2:
                cout << "Digite o nome do produto a ser removido: ";
                cin >> nome;
                limpaBuffer();
                produto = sistema.buscar(nome);
                if (produto != nullptr) {
                    sistema.remover(produto);
                    delete produto;
                } else {
                    cout << "Produto não encontrado." << endl;
                }
                break;
            case 3:
                cout << "Digite o código do produto a ser atualizado: ";
                cin >> codigo;
                produto = sistema.buscar(codigo);
                if (produto != nullptr) {
                    cout << "Digite o novo nome do produto: ";
                    cin >> nome;
                    limpaBuffer();
                    cout << "Digite a nova quantidade: ";
                    cin >> quantidade;
                    cout << "Digite o novo valor: ";
                    cin >> valor;
                    Produto* produtoAtualizado = new Produto(nome, quantidade, valor, codigo);
                    sistema.atualizar(produtoAtualizado);
                    delete produtoAtualizado;
                    delete produto;
                } else {
                    cout << "Produto não encontrado." << endl;
                }
                break;
            case 4:
                cout << "Digite o ID do produto: ";
                cin >> id;
                produto = sistema.buscar(id);
                if (produto != nullptr) {
                    produto->imprime(cout);
                    delete produto;
                } else {
                    cout << "Produto não encontrado." << endl;
                }
                break;
            case 5:
                cout << "Digite o nome do produto: ";
                cin >> nome;
                limpaBuffer();
                produto = sistema.buscar(nome);
                if (produto != nullptr) {
                    produto->imprime(cout);
                    delete produto;
                } else {
                    cout << "Produto não encontrado." << endl;
                }
                break;
            case 6:
                sistema.listar();
                break;
            case 0:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opção inválida!" << endl;
                break;
        }
    } while (opcao != 0);

    return 0;
}

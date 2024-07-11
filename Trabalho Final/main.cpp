#include <iostream>
#include <limits>
#include "sistema.h"
#include "produto.h"
#include "produtoComDesconto.h"

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
    cout << "4. Buscar Produto por codigo" << endl;
    cout << "5. Adicionar Desconto ao Produto" << endl;
    cout << "6. Remover Desconto por codigo" << endl;
    cout << "7. Listar Produtos" << endl;
    cout << "0. Sair" << endl;
}

int main() {
    Sistema* sistema = new Sistema();
    int opcao;
    Produto* produto;
    int codigo;
    string nome;
    int quantidade;
    double valor;
    char tipoProduto;
    double desconto;

    do {
        menu();
        cout << "Escolha uma opção: ";
        cin >> opcao;
        limpaBuffer();

        switch (opcao) {
            case 1:
                cout << endl << "Digite o tipo do produto (s - simples, d - com desconto): ";
                cin >> tipoProduto;
                limpaBuffer();
                cout << "Digite o nome do produto: ";
                cin >> nome;
                limpaBuffer();
                cout << "Digite a quantidade: ";
                cin >> quantidade;
                limpaBuffer();
                cout << "Digite o valor: ";
                cin >> valor;
                limpaBuffer();

                if (tipoProduto == 'd') {
                    cout << "Digite o desconto (%): ";
                    cin >> desconto;
                    limpaBuffer();
                    produto = new ProdutoComDesconto(nome, quantidade, valor, 0, desconto);
                } else {
                    produto = new Produto(nome, quantidade, valor, 0);
                }
                sistema->inserir(produto);
                delete produto;
                break;
            case 2:
                cout << endl << "Digite o código do produto a ser removido: ";
                cin >> codigo;
                limpaBuffer();
                sistema->remover(codigo);
                delete produto;
                break;
            case 3:
                cout << endl << "Digite o código do produto a ser atualizado: ";
                cin >> codigo;
                limpaBuffer();
                produto = sistema->buscar(codigo);
                if (produto != nullptr) {
                    cout << "Digite o novo nome do produto: ";
                    cin >> nome;
                    limpaBuffer();
                    cout << "Digite a nova quantidade: ";
                    cin >> quantidade;
                    limpaBuffer();
                    cout << "Digite o novo valor: ";
                    cin >> valor;
                    limpaBuffer();
                    Produto* produtoAtualizado = new Produto(nome, quantidade, valor, codigo);
                    sistema->atualizar(produtoAtualizado);
                    delete produtoAtualizado;
                    delete produto;
                    cout << endl << "Produto atualizado!" << endl;
                } else {
                    cout << endl << "Produto não encontrado." << endl;
                }
                break;
            case 4:
                cout << endl << "Digite o codigo do produto: ";
                cin >> codigo;
                limpaBuffer();
                produto = sistema->buscar(codigo);
                if (produto != nullptr) {
                    cout << *produto;
                    delete produto;
                }
                break;
            case 5:
                cout << endl << "Digite o código do produto a obter desconto: ";
                cin >> codigo;
                limpaBuffer();
                produto = sistema->buscar(codigo);
                if (produto != nullptr) {
                    cout << "Digite o desconto: ";
                    cin >> desconto;
                    limpaBuffer();
                    produto = new ProdutoComDesconto(produto->getNome(), produto->getQuantidade(), produto->getValor(), codigo, desconto);
                    sistema->inserirDesconto(dynamic_cast<ProdutoComDesconto*>(produto));
                    cout << endl << "Desconto do produto atualizado!" << endl;
                    delete produto;
                } else {
                    cout << endl << "Produto não encontrado." << endl;
                }
                break;
            case 6:
                cout << endl << "Digite o código do produto com o desconto a ser removido: ";
                cin >> codigo;
                limpaBuffer();
                sistema->removerDesconto(codigo);
                break;
            case 7:
                sistema->listar();
                break;
            case 0:
                cout << endl << "Saindo..." << endl;
                break;
            default:
                cout << endl << "Opção inválida!" << endl;
                break;
        }
    } while (opcao != 0);
    
    delete sistema;
    return 0;
}

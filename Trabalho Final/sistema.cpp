#include "sistema.h"

Sistema::Sistema(){
    conexao = new Conexao();
}

Sistema::~Sistema(){
    if (conexao != nullptr){
        delete conexao;
    }
}

void Sistema::inserir(Produto* produto){
    conexao->inserir(produto);
    if (dynamic_cast<ProdutoComDesconto*>(produto)){
        Produto* produtoAux = conexao->buscar(produto->getNome());
        ProdutoComDesconto* produtoAux2 = new ProdutoComDesconto(produtoAux, dynamic_cast<ProdutoComDesconto*>(produto)->getDesconto());
        conexao->inserirDesconto(produtoAux2);
        delete produtoAux2;
        delete produtoAux;
    }
    cout << endl << "Produto inserido!" << endl;
}

void Sistema::inserirDesconto(ProdutoComDesconto* produto){
    conexao->inserirDesconto(produto);
    cout << endl << "Desconto inserido!" << endl;
}

void Sistema::remover(int codigo){
    Produto* produto = conexao->buscar(codigo);
    if (produto != nullptr) {
        conexao->remover(codigo);
        cout << endl << "Produto removido!" << endl;
    }
}

void Sistema::removerDesconto(int codigo){
    Produto* produto = conexao->buscar(codigo);
    if (produto != nullptr) {
        conexao->removerDesconto(codigo);
        cout << endl << "Desconto do produto removido!" << endl;
    }
}

void Sistema::atualizar(Produto* produto){
    conexao->atualizar(produto);
}

Produto* Sistema::buscar(int codigo){
    return conexao->buscar(codigo);
}

void Sistema::listar(){
    conexao->listar();
}
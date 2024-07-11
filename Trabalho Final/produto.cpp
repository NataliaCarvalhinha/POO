#include "produto.h"

Produto::Produto(const string& nome, int quantidade, double valor, int codigo)
    : nome(nome), quantidade(quantidade), valor(valor), codigo(codigo) {}

string Produto::getNome() const {
    return nome;
}

int Produto::getQuantidade() const {
    return quantidade;
}

double Produto::getValor() const {
    return valor;
}

int Produto::getCodigo() const {
    return codigo;
}

ostream& operator<<(ostream& os, const Produto& produto) {
    os << endl << "---------------------" << endl 
       << "Nome: " << produto.getNome() << ", " 
       << endl << "Quantidade: " << produto.getQuantidade()
       << endl << "Valor: " << produto.getValor()
       << endl << "Codigo: " << produto.getCodigo();
    return os;
}

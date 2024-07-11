#include "produto.h"

Produto::Produto(const string& nome, int quantidade, double valor, int codigo)
    : nome(nome), quantidade(quantidade), valor(valor), codigo(codigo) {}

Produto::~Produto() {}

const string& Produto::getNome() const {
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
    produto.imprime(os);
    return os;
}
void Produto::imprime(ostream& os) const {
    os << endl << "---------------------" << endl 
       << "Nome: " << getNome() << ", " 
       << endl << "Quantidade: " << getQuantidade()
       << endl << "Valor: " << getValor()
       << endl << "Codigo: " << getCodigo();
}

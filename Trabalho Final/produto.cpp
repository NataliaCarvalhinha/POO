#include "produto.h"

Produto::Produto(string& nome, int quantidade, double valor, int codigo)
    : nome(nome), quantidade(quantidade), valor(valor), codigo(codigo) {}


string Produto::getNome(){
    return nome;
}

int Produto::getQuantidade(){
    return quantidade;
}

double Produto::getValor(){
    return valor;
}

int Produto::getCodigo(){
    return codigo;
}

void Produto::imprime(ostream& os){
    os << endl << "---------------------" << endl 
    << "Nome: " << nome << ", " 
    << endl << "Quantidade: " << quantidade
    << endl << "Valor: " << valor
    << endl << "Codigo: " << codigo;
}

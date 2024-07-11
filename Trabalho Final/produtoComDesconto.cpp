#include "produtoComDesconto.h"

ProdutoComDesconto::ProdutoComDesconto(const std::string& nome, int quantidade, double valor, int codigo, double desconto)
    : Produto(nome, quantidade, valor, codigo), desconto(desconto) {}

ProdutoComDesconto::ProdutoComDesconto(Produto* produto, double desconto) 
     : Produto(produto->getNome(), produto->getQuantidade(), produto->getValor(), produto->getCodigo()), desconto(desconto) {}


double ProdutoComDesconto::getDesconto() const {
    return desconto;
}

double ProdutoComDesconto::getValorComDesconto() const {
    return valor - (valor * desconto);
}


void ProdutoComDesconto::imprime(ostream& os) const{
    os << endl << "---------------------" << endl 
       << "Nome: " << getNome() << ", " 
       << endl << "Quantidade: " << getQuantidade()
       << endl << "Valor: " << getValor()
       << endl << "Desconto: " << getDesconto()
       << endl << "Valor com desconto: " << getValorComDesconto()
       << endl << "Codigo: " << getCodigo();
}

#ifndef PRODUTO_H
#define PRODUTO_H

#include <string>
#include <iostream>

using namespace std;

class Produto {
    public:
        Produto(const string& nome, int quantidade, double valor, int codigo);
        string getNome() const;
        int getQuantidade() const;
        double getValor() const;
        int getCodigo() const;
        friend ostream& operator<<(ostream& os, const Produto& produto);

    protected:
        string nome;
        int quantidade;
        double valor;
        int codigo;
};

#endif
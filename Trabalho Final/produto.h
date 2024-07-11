#ifndef PRODUTO_H
#define PRODUTO_H

#include <string>
#include <iostream>

using namespace std;

class Produto {
    public:
        Produto(string& nome, int quantidade, double valor, int codigo);
        string getNome();
        int getQuantidade();
        double getValor();
        int getCodigo();
        void imprime(ostream& os);

    private:
        string nome;
        int quantidade;
        double valor;
        int codigo;

};

#endif
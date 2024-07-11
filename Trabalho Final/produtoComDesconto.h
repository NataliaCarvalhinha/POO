#ifndef PRODUTOCOMDESCONTO_H
#define PRODUTOCOMDESCONTO_H

#include <string>
#include <iostream>
#include "produto.h"

using namespace std;

class ProdutoComDesconto : public Produto {

    public:
        ProdutoComDesconto(const string& nome, int quantidade, double valor, int codigo, double desconto);
        ProdutoComDesconto(Produto* produto, double desconto);
        double getDesconto() const;
        double getValorComDesconto() const;
        void imprime(ostream& os) const override;

    private:
        double desconto;
};

#endif

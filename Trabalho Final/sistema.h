#ifndef SISTEMA_H
#define SISTEMA_H

#include <string.h>
#include "produto.h"
#include "produtoComDesconto.h"
#include "conexao.h"

class Sistema {
    public:
        Sistema();
        ~Sistema();
        void inserir(Produto* produto);
        void inserirDesconto(ProdutoComDesconto* produto);
        void remover(int codigo);
        void removerDesconto(int codigo);
        void atualizar(Produto* produto);
        Produto* buscar(int codigo);
        void listar();
        Conexao* conexao = nullptr;
};

#endif
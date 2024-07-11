#ifndef SISTEMA_H
#define SISTEMA_H

#include <string.h>
#include "produto.h"
#include "conexao.h"

class Sistema {
    public:
        Sistema();
        void inserir(Produto* produto);
        void remover(Produto* produto);
        void atualizar(Produto* produto);
        Produto* buscar(int id);
        Produto* buscar(string& nome);
        void listar();
        Conexao conexao;
};

#endif
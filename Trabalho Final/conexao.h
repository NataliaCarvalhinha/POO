#ifndef CONEXAO_H
#define CONEXAO_H

#include <Python.h>
#include <string>
#include <boost/python.hpp>
#include "produto.h"
#include "produtoComDesconto.h"

using namespace std;

class Conexao {
    public:
        Conexao();
        ~Conexao();
        void inserir(Produto* produto);
        void inserirDesconto(ProdutoComDesconto* produto);
        void remover(int codigo);
        void removerDesconto(int codigo);
        void atualizar(Produto* produto);
        Produto* buscar(int codigo);
        Produto* buscar(const string& nome);
        void listar();
    private:
        PyObject *pModule = nullptr;
};

#endif
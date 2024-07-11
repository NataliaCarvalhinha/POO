#ifndef CONEXAO_H
#define CONEXAO_H

#include <Python.h>
#include <string>
#include <boost/python.hpp>
#include "produto.h"

using namespace std;

class Conexao {
    public:
        Conexao();
        ~Conexao();
        void inserir(Produto* produto);
        void remover(Produto* produto);
        void atualizar(Produto* produto);
        Produto* buscar(int id);
        Produto* buscar(string& nome);
        void listar();
        PyObject *pModule = nullptr;
};

#endif
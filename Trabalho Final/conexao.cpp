#include "conexao.h"

PyObject* iniciar(){
    Py_Initialize();
    PySys_SetPath(L".");
    PyRun_SimpleString( "import sys\nsys.path.append(\"/usr/lib/python310.zip\")\nsys.path.append(\"/usr/lib/python3.10\")\nsys.path.append(\"/usr/lib/python3.10/lib-dynload\")\nsys.path.append(\"/home/natalia/.local/lib/python3.10/site-packages\")\nsys.path.append(\"/usr/local/lib/python3.10/dist-packages\")\nsys.path.append(\"/usr/lib/python3/dist-packages\")\n" );    
    PyObject *pModule = PyImport_ImportModule("conector");
    return pModule;
}

Conexao::Conexao() {
    pModule = iniciar();
}
Conexao::~Conexao(){
    Py_DECREF(pModule);
    Py_Finalize();
}

void Conexao::inserir(Produto* produto) {
    if (pModule != nullptr) {
        PyObject *pFuncInserir = PyObject_GetAttrString(pModule, "inserirProduto");

        if (pFuncInserir && PyCallable_Check(pFuncInserir)) {
            PyObject *pArgs = PyTuple_New(3);
            PyTuple_SetItem(pArgs, 0, PyUnicode_FromString(produto->getNome().c_str()));
            PyTuple_SetItem(pArgs, 1, PyLong_FromLong(produto->getQuantidade()));
            PyTuple_SetItem(pArgs, 2, PyFloat_FromDouble(produto->getValor()));

            PyObject *pResultInserir = PyObject_CallObject(pFuncInserir, pArgs);
            if (pResultInserir != nullptr) {
                Py_DECREF(pResultInserir);
            } else {
                PyErr_Print();
            }
            Py_DECREF(pArgs);
            Py_DECREF(pFuncInserir);
        } else {
            if (PyErr_Occurred()) PyErr_Print();
        }
        cout << "Produto inserido." << endl;
    } else {
        PyErr_Print();
    }

    
}

void Conexao::remover(Produto* produto) {
    if (pModule != nullptr) {
        PyObject *pFuncRemover = PyObject_GetAttrString(pModule, "deletarProduto");

        if (pFuncRemover && PyCallable_Check(pFuncRemover)) {
            PyObject *pArgs = PyTuple_New(1);
            PyTuple_SetItem(pArgs, 0, PyUnicode_FromString(produto->getNome().c_str()));
            PyObject *pResultRemover = PyObject_CallObject(pFuncRemover, pArgs);
            if (pResultRemover != nullptr) {
                Py_DECREF(pResultRemover);
            } else {
                PyErr_Print();
            }
            Py_DECREF(pArgs);
            Py_DECREF(pFuncRemover);
        } else {
            if (PyErr_Occurred()) PyErr_Print();
        }
    } else {
        PyErr_Print();
    }

    cout << "Produto removido." << endl;
}

void Conexao::atualizar(Produto* produto) {
    if (pModule != nullptr) {
        PyObject *pFuncAtualizar = PyObject_GetAttrString(pModule, "atualizarProduto");

        if (pFuncAtualizar && PyCallable_Check(pFuncAtualizar)) {
            PyObject *pArgs = PyTuple_New(4);
            PyTuple_SetItem(pArgs, 0, PyLong_FromLong(produto->getCodigo()));
            PyTuple_SetItem(pArgs, 1, PyUnicode_FromString(produto->getNome().c_str()));
            PyTuple_SetItem(pArgs, 2, PyLong_FromLong(produto->getQuantidade()));
            PyTuple_SetItem(pArgs, 3, PyFloat_FromDouble(produto->getValor()));

            PyObject *pResultAtualizar = PyObject_CallObject(pFuncAtualizar, pArgs);
            if (pResultAtualizar != nullptr) {
                Py_DECREF(pResultAtualizar);
            } else {
                PyErr_Print();
            }
            Py_DECREF(pArgs);
            Py_DECREF(pFuncAtualizar);
        } else {
            if (PyErr_Occurred()) PyErr_Print();
        }
    } else {
        PyErr_Print();
    }

    cout << "Produto atualizado." << endl;
}

Produto* Conexao::buscar(int id) {
    Produto* produto = nullptr;
    if (pModule != nullptr) {
        PyObject *pFuncBuscar = PyObject_GetAttrString(pModule, "buscarProduto");
        if (pFuncBuscar && PyCallable_Check(pFuncBuscar)) {
            PyObject *pArgs = PyTuple_New(1);
            PyTuple_SetItem(pArgs, 0, PyLong_FromLong(id));
            PyObject *pResultBuscar = PyObject_CallObject(pFuncBuscar, pArgs);
            if (pResultBuscar != nullptr) {
                PyObject *pNome = PyTuple_GetItem(pResultBuscar, 1);
                PyObject *pQuantidade = PyTuple_GetItem(pResultBuscar, 2);
                PyObject *pValor = PyTuple_GetItem(pResultBuscar, 3);
                string nome = PyUnicode_AsUTF8(pNome);
                int quantidade = PyLong_AsLong(pQuantidade);
                double valor = PyFloat_AsDouble(pValor);
                produto = new Produto(nome, quantidade, valor, id);
                Py_DECREF(pResultBuscar);

            } else {
                PyErr_Print();
            }
            Py_DECREF(pArgs);
            Py_DECREF(pFuncBuscar);
        } else {
            if (PyErr_Occurred()) PyErr_Print();
        }
    } else {
        PyErr_Print();
    }

    return produto;
}

Produto* Conexao::buscar(string& nome) {
    Produto* produto = nullptr;
    if (pModule != nullptr) {
        PyObject *pFuncBuscar = PyObject_GetAttrString(pModule, "buscarProdutoNome");
        if (pFuncBuscar && PyCallable_Check(pFuncBuscar)) {
            PyObject *pArgs = PyTuple_New(1);
            PyTuple_SetItem(pArgs, 0, PyUnicode_FromString(nome.c_str()));

            PyObject *pResultBuscar = PyObject_CallObject(pFuncBuscar, pArgs);
            if (pResultBuscar != nullptr) {
                PyObject *pId = PyTuple_GetItem(pResultBuscar, 0);
                PyObject *pQuantidade = PyTuple_GetItem(pResultBuscar, 2);
                PyObject *pValor = PyTuple_GetItem(pResultBuscar, 3);
                int id = PyLong_AsLong(pId);
                int quantidade = PyLong_AsLong(pQuantidade);
                double valor = PyFloat_AsDouble(pValor);
                produto = new Produto(nome, quantidade, valor, id);
                Py_DECREF(pResultBuscar);
            } else {
                PyErr_Print();
            }
            Py_DECREF(pArgs);
            Py_DECREF(pFuncBuscar);
        } else {
            if (PyErr_Occurred()) PyErr_Print();
        }
    } else {
        PyErr_Print();
    }

    return produto;
}

void Conexao::listar() {
    if (pModule != nullptr) {
        PyObject *pFuncListar = PyObject_GetAttrString(pModule, "listarProdutos");

        if (pFuncListar && PyCallable_Check(pFuncListar)) {
            PyObject *pArgs = PyTuple_New(0);

            PyObject *pResultListar = PyObject_CallObject(pFuncListar, pArgs);
            if (pResultListar != nullptr) {
                // Assumindo que a função Python retorna uma lista de tuplas (id, nome, quantidade, valor)
                Py_ssize_t tamanho = PyList_Size(pResultListar);
                for (Py_ssize_t i = 0; i < tamanho; ++i) {
                    PyObject *pItem = PyList_GetItem(pResultListar, i);
                    PyObject *pId = PyTuple_GetItem(pItem, 0);
                    PyObject *pNome = PyTuple_GetItem(pItem, 1);
                    PyObject *pQuantidade = PyTuple_GetItem(pItem, 2);
                    PyObject *pValor = PyTuple_GetItem(pItem, 3);

                    int id = PyLong_AsLong(pId);
                    string nome = PyUnicode_AsUTF8(pNome);
                    int quantidade = PyLong_AsLong(pQuantidade);
                    double valor = PyFloat_AsDouble(pValor);

                    cout << "ID: " << id << ", Nome: " << nome << ", Quantidade: " << quantidade << ", Valor: " << valor << endl;
                }
                Py_DECREF(pResultListar);
            } else {
                PyErr_Print();
            }
            Py_DECREF(pArgs);
            Py_DECREF(pFuncListar);
        } else {
            if (PyErr_Occurred()) PyErr_Print();
        }
    } else {
        PyErr_Print();
    }

}
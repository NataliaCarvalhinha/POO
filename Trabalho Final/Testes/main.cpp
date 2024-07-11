#include <Python.h>
#include <iostream>

using namespace std;

int main() {
    Py_Initialize();

    // Configurar o caminho de busca do Python para incluir o diretório atual
    PySys_SetPath(L".");


    // Carregar o módulo Python
    PyObject *pModule = PyImport_ImportModule("funcoes");

    // Verificar se o módulo foi carregado corretamente
    if (pModule != nullptr) {
        Py_DECREF(pModule);

        // Restante do seu código para chamar as funções do módulo 'funcoes'

    } else {
        PyErr_Print();
        std::cerr << "Erro ao importar o módulo Python." << std::endl;
        return 1;
    }

    PyObject *pFuncSoma = PyObject_GetAttrString(pModule, "soma");
    PyObject *pFuncSubtracao = PyObject_GetAttrString(pModule, "subtracao");
    PyObject *pFuncMultiplicacao = PyObject_GetAttrString(pModule, "multiplicacao");
    PyObject *pFuncDivisao = PyObject_GetAttrString(pModule, "divisao");
    

    // Verificar se as funções foram obtidas corretamente
    if (pFuncSoma && PyCallable_Check(pFuncSoma) &&
        pFuncSubtracao && PyCallable_Check(pFuncSubtracao) &&
        pFuncMultiplicacao && PyCallable_Check(pFuncMultiplicacao) &&
        pFuncDivisao && PyCallable_Check(pFuncDivisao)) {

        // Chamar as funções Python com os argumentos apropriados
        PyObject *pArgs = PyTuple_New(2); // Exemplo: função com dois argumentos
        PyTuple_SetItem(pArgs, 0, PyLong_FromLong(10)); // Argumento: 10
        PyTuple_SetItem(pArgs, 1, PyLong_FromLong(5));  // Argumento: 5

        // Chamar a função soma
        PyObject *pResultSoma = PyObject_CallObject(pFuncSoma, pArgs);
        if (pResultSoma != NULL) {
            std::cout << "Resultado da soma: " << PyLong_AsLong(pResultSoma) << std::endl;
            Py_DECREF(pResultSoma);
        } else {
            PyErr_Print();
            std::cerr << "Erro na chamada da função soma." << std::endl;
        }

        // Chamar a função subtração
        PyObject *pResultSubtracao = PyObject_CallObject(pFuncSubtracao, pArgs);
        if (pResultSubtracao != NULL) {
            std::cout << "Resultado da subtração: " << PyLong_AsLong(pResultSubtracao) << std::endl;
            Py_DECREF(pResultSubtracao);
        } else {
            PyErr_Print();
            std::cerr << "Erro na chamada da função subtração." << std::endl;
        }

        // Chamar a função multiplicação
        PyObject *pResultMultiplicacao = PyObject_CallObject(pFuncMultiplicacao, pArgs);
        if (pResultMultiplicacao != NULL) {
            std::cout << "Resultado da multiplicação: " << PyLong_AsLong(pResultMultiplicacao) << std::endl;
            Py_DECREF(pResultMultiplicacao);
        } else {
            PyErr_Print();
            std::cerr << "Erro na chamada da função multiplicação." << std::endl;
        }

        // Chamar a função divisão
        PyObject *pResultDivisao = PyObject_CallObject(pFuncDivisao, pArgs);
        if (pResultDivisao != NULL) {
            std::cout << "Resultado da divisão: " << PyFloat_AsDouble(pResultDivisao) << std::endl;
            Py_DECREF(pResultDivisao);
        } else {
            PyErr_Print();
            std::cerr << "Erro na chamada da função divisão." << std::endl;
        }

        Py_DECREF(pArgs);
    } else {
        if (PyErr_Occurred()) PyErr_Print();
        std::cerr << "Não foi possível encontrar uma ou mais funções Python." << std::endl;
    }


    // Finalizar o interpretador Python
    Py_Finalize();
    cout << "Funcionou" << endl;
    return 0;
}

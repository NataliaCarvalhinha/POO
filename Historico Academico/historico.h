#ifndef HISTORICO_H
#define HISTORICO_H

#include <iostream>
#include <vector>
#include <stdexcept>

#include "disciplina.h"

using namespace std;

class Historico {
    public:
        Historico(size_t limite) : limiteDisciplinas(limite){}
        void imprimeDisciplinas(bool disciplina = false); // quando disciplina = false, imprime o histórico completo

    private:
        vector<Disciplina> disciplinas;
        size_t limiteDisciplinas;
        friend ostream& operator<<(ostream& os, const Historico& historico);

};

#endif // HISTORICO_H
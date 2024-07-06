#ifndef HISTORICO_H
#define HISTORICO_H

#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <fstream>

#include "disciplina.h"

using namespace std;

class Historico {
    public:
        Historico(size_t limite) : limiteDisciplinas(limite){}
        friend ostream& operator<<(ostream& os, const Historico& historico);
        int operator+=(const Disciplina& disciplina);
        void operator+=(const vector<Disciplina>& disciplinas);
        int operator-=(const string& nomeDisciplina);
        vector<Disciplina> operator()(const string& periodo) const;
        double& operator[](const string& nomeDisciplina);
        double operator>>(double& cra) const;
        void carregarDisciplinas(const string& nomeArquivo);
        void salvarDisciplinas(const string& nomeArquivo) const;

    private:
        vector<Disciplina> disciplinas;
        size_t limiteDisciplinas;
};

#endif // HISTORICO_H
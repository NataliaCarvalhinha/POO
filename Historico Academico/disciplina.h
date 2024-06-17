#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <iostream>

using namespace std;

struct Disciplina {
    string nome;
    string periodoDeConclusao;
    double creditos;
    double notaFinal;

    Disciplina(string n, double c, double nota) : nome(n), creditos(c), notaFinal(nota) {}

    friend ostream& operator<<(ostream& os, const Disciplina& disciplina);
};

#endif // DISCIPLINA_H
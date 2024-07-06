#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <iostream>

using namespace std;

struct Disciplina {
    string nome;
    string periodoDeConclusao;
    double creditos;
    double notaFinal;

    Disciplina() : nome(""), periodoDeConclusao(""), creditos(0.0), notaFinal(-1.0) {}
    Disciplina(std::string n, std::string periodo, double cred, double nota)
        : nome(n), periodoDeConclusao(periodo), creditos(cred), notaFinal(nota) {}

    friend ostream& operator<<(ostream& os, const Disciplina& disciplina);
    friend istream& operator>>(istream& is, Disciplina& disciplina);

    bool operator<(const Disciplina& outra) const;
    bool operator==(const Disciplina& outra) const;

};

#endif // DISCIPLINA_H

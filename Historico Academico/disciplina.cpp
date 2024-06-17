#include "disciplina.h"

ostream& operator<<(ostream& os, const Disciplina& disciplina) {
    os << "Disciplina: " << disciplina.nome << ", Periodo de conclusão: " << disciplina.periodoDeConclusao <<", Créditos: " << disciplina.creditos << ", Nota Final: " << disciplina.notaFinal << endl;
    return os;
}
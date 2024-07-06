#include "disciplina.h"

ostream& operator<<(ostream& os, const Disciplina& disciplina) {
    os << "Disciplina: " << disciplina.nome 
       << ", Periodo de conclusão: " << disciplina.periodoDeConclusao 
       << ", Créditos: " << disciplina.creditos 
       << ", Nota Final: " << disciplina.notaFinal;
    return os;
}

istream& operator>>(istream& is, Disciplina& disciplina) {
    cout << "Digite o nome da disciplina: ";
    getline(is >> ws, disciplina.nome); 

    cout << "Digite o período de conclusão (ex. 2023.1): ";
    getline(is >> ws, disciplina.periodoDeConclusao);

    cout << "Digite o número de créditos: ";
    is >> disciplina.creditos; 

    cout << "Digite a nota final: ";
    is >> disciplina.notaFinal; 
    return is;
}

bool Disciplina::operator<(const Disciplina& outra) const {
    if (periodoDeConclusao != outra.periodoDeConclusao) {
        return periodoDeConclusao < outra.periodoDeConclusao;
    }

    return nome < outra.nome;
}

bool Disciplina::operator==(const Disciplina& outra) const {
    return nome == outra.nome;
}

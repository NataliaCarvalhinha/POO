#include "historico.h"

// Private -------------------------------------------------

friend ostream& operator<<(ostream& os, const Historico& historico) {
    os << "Histórico de Disciplinas:\n";
    for (const auto& disciplina : historico.disciplinas) {
        os << disciplina << "\n";
    }
    return os;
}

// Public -------------------------------------------------

void Historico::imprimeDisciplinas(const string& nome){
    if (nome.empty()){
        cout << *this;
    } else {
        bool encontrou = false;
        for (const auto& disciplina : disciplinas) {
            if (disciplina.nome == nome) {
                cout << disciplina << endl; // usa o operador << sobrecarregado para Disciplina
                encontrou = true;
                break; // para após encontrar a primeira correspondência
            }
        }
        if (!encontrou) {
            cout << "Disciplina '" << nome << "' não encontrada." << endl;
        }
    }
}
#include "sistema.h"

void Sistema::insere(const Atleta& atleta) {
    arvoreDeAtletas + atleta;
}

bool Sistema::busca(const string& nome) const {
    return arvoreDeAtletas(Atleta(nome, 0));
}

void Sistema::remove(const Atleta& atleta) {
    arvoreDeAtletas - atleta;
}

void Sistema::lista() const {
    cout << arvoreDeAtletas;
}

ostream& operator<<(ostream& os, const Sistema& sistema) {
    sistema.lista();
    return os;
}
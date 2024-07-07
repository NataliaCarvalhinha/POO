#include "sistema.h"

void Sistema::insere(Atleta* atleta) {
    arvoreDeAtletas + atleta;
}

Atleta* Sistema::busca(const string& nome) const {
    return arvoreDeAtletas(Atleta(nome, 0));
}

void Sistema::remove(Atleta* atleta) {
    arvoreDeAtletas - atleta;
}

void Sistema::lista() const {
    cout << arvoreDeAtletas;
}

ostream& operator<<(ostream& os, const Sistema& sistema) {
    sistema.lista();
    return os;
}
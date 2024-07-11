#include "atleta.h"

Atleta::Atleta(const string& nome, const int idade) : nome(nome), idade(idade) {}

Atleta::~Atleta() {}

string Atleta::getNome() const {
    return nome;
}

void Atleta::imprime(ostream& os) const {
    os << endl << "---------------------" << endl 
    << "Nome: " << nome << ", " 
    << endl << "Idade: " << idade;
}

ostream& operator<<(ostream& os, Atleta& atleta) {
    atleta.imprime(os);
    return os;
}

bool Atleta::operator<(const Atleta& outro) const {
    return nome < outro.nome;
}

bool Atleta::operator>(const Atleta& outro) const {
    return nome > outro.nome;
}

bool Atleta::operator==(const Atleta& outro) const {
    return nome == outro.nome;
}
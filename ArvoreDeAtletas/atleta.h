#ifndef ATLETA_H
#define ATLETA_H

#include <string>
#include <iostream>

using namespace std;

class Atleta {
protected:
    string nome;
    int idade;

public:
    Atleta(const string& nome, const int idade);
    virtual ~Atleta();

    string getNome() const;
    virtual void imprime(ostream& os) const;
    friend ostream& operator<<(ostream& os, Atleta& atleta);

    bool operator<(const Atleta& outro) const;
    bool operator>(const Atleta& outro) const;
    bool operator==(const Atleta& outro) const;
};

#endif

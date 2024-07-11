#ifndef ATLETA_VOLEI_H
#define ATLETA_VOLEI_H

#include <iostream>
#include "atleta.h"

using namespace std;

class AtletaVolei : public Atleta {
private:
    string posicao;

public:
    AtletaVolei(const string& nome,int idade, const string& posicao);

    void imprime(ostream& os) const override;
};

#endif

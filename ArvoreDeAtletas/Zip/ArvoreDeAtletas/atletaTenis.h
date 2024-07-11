#ifndef ATLETA_TENIS_H
#define ATLETA_TENIS_H

#include "atleta.h"

using namespace std;

class AtletaTenis : public Atleta {
private:
    int ranking;
    string estilo;

public:
    AtletaTenis(const string& nome, const int idade, int ranking, const string estilo);

    void imprime(ostream& os) const override;
};

#endif

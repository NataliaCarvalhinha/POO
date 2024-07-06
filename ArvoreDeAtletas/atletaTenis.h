#ifndef ATLETA_TENIS_H
#define ATLETA_TENIS_H

#include "atleta.h"

using namespace std;

class AtletaTenis : public Atleta {
private:
    int ranking;
    string estilo;

public:
    AtletaTenis(const string& nome, int ranking, const string estilo, const int idade);

    void imprime(ostream& os) const override;
};

#endif

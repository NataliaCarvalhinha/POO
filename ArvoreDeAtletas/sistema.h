#ifndef SISTEMA_H
#define SISTEMA_H

#include "arvore.h"
#include "atleta.h"
#include "atletaTenis.h"
#include "atletaVolei.h"
#include <string>
#include <iostream>

class Sistema {
    private:
        Arvore<Atleta> arvoreDeAtletas;

    public:
        void insere(Atleta* atleta);

        Atleta* busca(const string& nome) const;

        void remove(Atleta* atleta);

        void lista() const;

        friend ostream& operator<<(ostream& os, const Sistema& sistema);
};

#endif

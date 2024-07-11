#include "atletaVolei.h"

AtletaVolei::AtletaVolei(const string& nome, int idade, const string& posicao)
    : Atleta(nome, idade), posicao(posicao) {}

void AtletaVolei::imprime(ostream& os) const {
    os << endl << "---------------------" << endl 
    << "Nome: " << nome << ", " << endl 
    << "Idade: " << idade << ", " << endl 
    << "Esporte: Vôlei," << endl 
    << "Posição no Volei: " << posicao << endl;
}
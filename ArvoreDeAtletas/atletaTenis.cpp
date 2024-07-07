#include "atletaTenis.h"

AtletaTenis::AtletaTenis(const string& nome,  const int idade, int ranking, const string estilo) : Atleta(nome, idade), ranking(ranking), estilo(estilo) {}

void AtletaTenis::imprime(ostream& os) const {
    os << endl << "---------------------" << endl 
    << "Nome: " << nome << "," << endl 
    << "Idade: " << idade << "," << endl 
    << "Esporte: Tênis," << endl 
    << "Ranking: " << ranking  << "," << endl 
    << "Estilo de Jogo: " << estilo << endl;
}
#ifndef LIGA_H
#define LIGA_H

#include <vector>
#include <string>
#include <numeric>

using namespace std;

class Time {

    private:
        string nome;
        vector<vector<int>> golsEfetuados; // [ano][campeonato]
        vector<vector<int>> golsSofridos;  // [ano][campeonato]

    
    public:
        Time(string n, vector<vector<int>> ge, vector<vector<int>> gs);
        double calcularMediaMovel(int ano, int campeonato, int N, bool efetuados = true) const;      
        const string& getNome() const;
        double calculaSaldoDeGols(int campeonato, int ano) const;
        void verificaEvolucaoOuRegressaoNoDesempenhoPorCampeonato(
            int a,
            int c, 
            int N, 
            Time* time,
            vector<Time>* melhoraDesempenhoSofridos,
            vector<Time>* pioraDesempenhoSofridos,
            vector<Time>* estavelSofridos,
            vector<Time>* melhoraDesempenhoEfetuados,
            vector<Time>* pioraDesempenhoEfetuados,
            vector<Time>* estavelEfetuados
            );
        void verificaEvolucaoOuRegressaoNoDesempenho(
            int a,
            int campeonatos,
            int N, 
            Time* time,
            vector<Time>* melhoraDesempenhoSofridos,
            vector<Time>* pioraDesempenhoSofridos,
            vector<Time>* estavelSofridos,
            vector<Time>* melhoraDesempenhoEfetuados,
            vector<Time>* pioraDesempenhoEfetuados,
            vector<Time>* estavelEfetuados
            );
};

//---------------------------------------------------------------------------------

class Liga {
    
    private:
        int anos;
        int campeonatos;
        vector<Time> times;

    public:
        Liga(int a, int c, vector<Time> t);
        void calcularMediasMoveis(int N) const;
        void exibirTimeComMaiorSaldoDeGolsPorCampeonato() const;
        void avaliarDesempenhoTimeNosCampeonatos(int N);
        void avaliarDesempenhoTimeNoUltimoAno(int N);
        void mostrarTimeMaiorEvolucaoUltimoAno(int N);

};

//---------------------------------------------------------------------------------

#endif // LIGA_H

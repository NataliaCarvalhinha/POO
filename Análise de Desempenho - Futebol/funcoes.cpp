#include <iostream>
#include "lib.h"

using namespace std;

#define LIMIAR 0.1


//---------------------------------------------------------------------------------


Time::Time(string n, vector<vector<int>> ge, vector<vector<int>> gs) : nome(n), golsEfetuados(ge), golsSofridos(gs) {}

double Time::calcularMediaMovel(int ano, int campeonato, int N, bool efetuados) const {
        double soma = 0.0;
        if (ano < N - 1) return -1; // Não há dados suficientes
        for (int i = 0; i < N; ++i) {
            if (efetuados) {
                soma += golsEfetuados[ano - i][campeonato];
            } else {
                soma += golsSofridos[ano - i][campeonato];
            }
        }
        return soma / N;
}

double Time::calculaSaldoDeGols(int campeonato, int ano) const {
    return golsEfetuados[ano][campeonato] - golsSofridos[ano][campeonato];
}

const string& Time::getNome() const {
        return nome;
    }

void Time::verificaEvolucaoOuRegressaoNoDesempenhoPorCampeonato(
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
    ){
    double mediaEfetuados = time->calcularMediaMovel(a - 1, c, N, true);
    double mediaSofridos = time->calcularMediaMovel(a - 1, c, N, false);
    double mediaEfetuadosAnterior = time->calcularMediaMovel(a - 2, c, N, true);
    double mediaSofridosAnterior = time->calcularMediaMovel(a - 2, c, N, false);
    
    if (mediaSofridosAnterior == 0.0f) {
        estavelSofridos->push_back(*time);
    }

    if (mediaEfetuadosAnterior == 0.0f) {
        estavelEfetuados->push_back(*time);
    }

    float razaoSofridos = mediaSofridos / mediaSofridosAnterior - 1.0f;
    float razaoEfetuados = mediaEfetuados / mediaEfetuadosAnterior - 1.0f;

    if (razaoEfetuados > LIMIAR) { // razao > 10%
        melhoraDesempenhoEfetuados->push_back(*time);
    } else if (razaoEfetuados < -LIMIAR) { //razao < -10%
        pioraDesempenhoEfetuados->push_back(*time);
    } else {
        estavelEfetuados->push_back(*time);
    }

    if (razaoSofridos < -LIMIAR) {  // razao < -10%
        melhoraDesempenhoSofridos->push_back(*time);
    } else if (razaoSofridos > LIMIAR) {  // razao > 10%
        pioraDesempenhoSofridos->push_back(*time);
    } else {
        estavelSofridos->push_back(*time);
    }
}


void Time::verificaEvolucaoOuRegressaoNoDesempenho(
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
    ){
        double mediaEfetuados = 0.0;
        double mediaSofridos = 0.0;
        double mediaEfetuadosAnterior = 0.0;
        double mediaSofridosAnterior = 0.0;

        for (int c = 0; c < campeonatos; c++) {
            mediaEfetuados += time->calcularMediaMovel(a -1, c, N, true);
            mediaSofridos += time->calcularMediaMovel(a - 1, c, N, false);
            mediaEfetuadosAnterior += time->calcularMediaMovel(a - 2, c, N, true);
            mediaSofridosAnterior += time->calcularMediaMovel(a - 2, c, N, false);
        }

        mediaEfetuados /= campeonatos;
        mediaSofridos /= campeonatos;
        mediaEfetuadosAnterior /= campeonatos;
        mediaSofridosAnterior /= campeonatos;


        if (mediaSofridosAnterior == 0.0f) {
            estavelSofridos->push_back(*time);
            }

        if (mediaEfetuadosAnterior == 0.0f) {
            estavelEfetuados->push_back(*time);
        }

        float razaoSofridos = mediaSofridos / mediaSofridosAnterior - 1.0f;
        float razaoEfetuados = mediaEfetuados / mediaEfetuadosAnterior - 1.0f;

        if (razaoEfetuados > LIMIAR) { // razao > 10%
            melhoraDesempenhoEfetuados->push_back(*time);
        } else if (razaoEfetuados < -LIMIAR) { //razao < -10%
            pioraDesempenhoEfetuados->push_back(*time);
        } else {
            estavelEfetuados->push_back(*time);
        }

        if (razaoSofridos < -LIMIAR) {  // razao < -10%
            melhoraDesempenhoSofridos->push_back(*time);
        } else if (razaoSofridos > LIMIAR) {  // razao > 10%
            pioraDesempenhoSofridos->push_back(*time);
        } else {
            estavelSofridos->push_back(*time);
        }
    }


//---------------------------------------------------------------------------------

Liga::Liga(int a, int c, vector<Time> t) : anos(a), campeonatos(c), times(t) {}

void Liga::calcularMediasMoveis(int N) const {
    for (const auto& time : times) {
        cout << "Time: " << time.getNome() << endl;
        for (int c = 0; c < campeonatos; ++c) {
            double totalEfetuados = 0;
            double totalSofridos = 0;
            for (int a = N-1; a < anos; ++a) {
                double mediaEfetuados = time.calcularMediaMovel(a, c, N, true);
                double mediaSofridos = time.calcularMediaMovel(a, c, N, false);
                totalEfetuados += mediaEfetuados;
                totalSofridos += mediaSofridos;
                cout << "\nCampeonato " << c << " Ano " << a << " - Média Gols Efetuados: " << mediaEfetuados
                            << ", Média Gols Sofridos: " << mediaSofridos << endl;
            }
             cout << "\nMédia do Campeonato " << c << " ao longo dos anos : \n" 
                            << "Gols Efetuados: " << totalEfetuados/(anos-N + 1)
                            << ", Gols Sofridos: " << totalSofridos/(anos-N + 1) << endl;
            cout << "\n-----------------------------\n";

        }
    }
}

void Liga::avaliarDesempenhoTimeNosCampeonatos(int N) {
    for (int c = 0; c < campeonatos; c++) {
        vector<Time> melhoraDesempenhoSofridos;
        vector<Time> pioraDesempenhoSofridos;
        vector<Time> estavelSofridos;
        vector<Time> melhoraDesempenhoEfetuados;
        vector<Time> pioraDesempenhoEfetuados;
        vector<Time> estavelEfetuados;

        for (size_t i = 0; i < times.size(); i++) {
            times[i].verificaEvolucaoOuRegressaoNoDesempenhoPorCampeonato(
                anos,
                c, 
                N, 
                &times[i],
                &melhoraDesempenhoSofridos,
                &pioraDesempenhoSofridos,
                &estavelSofridos,
                &melhoraDesempenhoEfetuados,
                &pioraDesempenhoEfetuados,
                &estavelEfetuados
                );
        }

        cout << "\n--------------------------------------------------------------------------\n";
        
        cout << "\nCampeonato: " << c << endl;

        cout << "\n-----------------------------\n";

        cout << "\nTimes com Melhora de Desempenho de Gols Efetuados ( > 10% de aumento ):\n";
        for (Time& time : melhoraDesempenhoEfetuados) {
            cout << "- " << time.getNome() << endl;
        }

        cout << "\nTimes com Piora de Desempenho de Gols Efetuados ( < 10% de aumento ):\n";
        for (Time& time : pioraDesempenhoEfetuados) {
            cout << "- " << time.getNome() << endl;
        }

        cout << "\nTimes Estáveis ( variação menor que 10% ):\n";
        for (Time& time : estavelEfetuados) {
        cout << "- " << time.getNome() <<endl;
        }

            cout << "\nTimes com Melhora de Desempenho de Gols Sofridos ( < 10% de aumento ):\n";
        for (Time& time : melhoraDesempenhoSofridos) {
            cout << "- " << time.getNome() << endl;
        }

        cout << "\nTimes com Piora de Desempenho de Gols Sofridos ( > 10% de aumento ):\n";
        for (Time& time : pioraDesempenhoSofridos) {
            cout << "- " << time.getNome() << endl;
        }

        cout << "\nTimes Estáveis ( variação menor que 10% ):\n";
        for (Time& time : estavelSofridos) {
        cout << "- " << time.getNome() <<endl;
        }
    }
    cout << "\n--------------------------------------------------------------------------\n";

}

void Liga::avaliarDesempenhoTimeNoUltimoAno(int N) {
    vector<Time> melhoraDesempenhoSofridos;
    vector<Time> pioraDesempenhoSofridos;
    vector<Time> estavelSofridos;
    vector<Time> melhoraDesempenhoEfetuados;
    vector<Time> pioraDesempenhoEfetuados;
    vector<Time> estavelEfetuados;

    for (size_t i = 0; i < times.size(); i++) {
        times[i].verificaEvolucaoOuRegressaoNoDesempenho(
            anos,
            campeonatos,
            N, 
            &times[i],
            &melhoraDesempenhoSofridos,
            &pioraDesempenhoSofridos,
            &estavelSofridos,
            &melhoraDesempenhoEfetuados,
            &pioraDesempenhoEfetuados,
            &estavelEfetuados
            );
    }

    cout << "\n--------------------------------------------------------------------------\n";
    cout << "\nAvaliação Geral dos Times no Último Ano\n";
    cout << "\n-----------------------------\n";

    cout << "\nTimes com Melhora de Desempenho de Gols Efetuados ( > 10% de aumento ):\n";
    for (Time& time : melhoraDesempenhoEfetuados) {
        cout << "- " << time.getNome() << endl;
    }

    cout << "\nTimes com Piora de Desempenho de Gols Efetuados ( < 10% de aumento ):\n";
    for (Time& time : pioraDesempenhoEfetuados) {
        cout << "- " << time.getNome() << endl;
    }

    cout << "\nTimes Estáveis ( variação menor que 10% ):\n";
    for (Time& time : estavelEfetuados) {
        cout << "- " << time.getNome() << endl;
    }

    cout << "\nTimes com Melhora de Desempenho de Gols Sofridos ( < 10% de aumento ):\n";
    for (Time& time : melhoraDesempenhoSofridos) {
        cout << "- " << time.getNome() << endl;
    }

    cout << "\nTimes com Piora de Desempenho de Gols Sofridos ( > 10% de aumento ):\n";
    for (Time& time : pioraDesempenhoSofridos) {
        cout << "- " << time.getNome() << endl;
    }

    cout << "\nTimes Estáveis ( variação menor que 10% ):\n";
    for (Time& time : estavelSofridos) {
        cout << "- " << time.getNome() << endl;
    }

    cout << "\n--------------------------------------------------------------------------\n";
}

void Liga::exibirTimeComMaiorSaldoDeGolsPorCampeonato() const {
    for (int c = 0; c < campeonatos; c++) {
        for (int a = 0; a < anos; a++) {
            int maiorTime = 0;
            for (size_t t = 0; t < times.size(); t++) {
                int saldoTime = times[t].calculaSaldoDeGols(c, a);
                if (saldoTime > times[maiorTime].calculaSaldoDeGols(c, a)){
                    maiorTime = t;
                }
            }
            cout << "\nCampeonato " << c << " do ano " << a << ". Melhor time: " << times[maiorTime].getNome() << 
            " com " << times[maiorTime].calculaSaldoDeGols(c, a) << " gols." << endl;
        
        }
    }
}

void Liga::mostrarTimeMaiorEvolucaoUltimoAno(int N) {
    Time* timeMaiorEvolucaoEfetuados = &times[0];
    Time* timeMaiorEvolucaoSofridos = &times[0];
    float maiorEvolucaoEfetuados = -1.0f;
    float maiorEvolucaoSofridos = -1.0f;

    vector<Time> melhoraDesempenhoSofridos;
    vector<Time> pioraDesempenhoSofridos;
    vector<Time> estavelSofridos;
    vector<Time> melhoraDesempenhoEfetuados;
    vector<Time> pioraDesempenhoEfetuados;
    vector<Time> estavelEfetuados;


    for (size_t i = 0; i < times.size(); ++i) {
        // Avaliar desempenho do time no último ano
        times[i].verificaEvolucaoOuRegressaoNoDesempenho(
                                                         anos,
                                                         campeonatos, 
                                                         N,
                                                         &times[i],
                                                         &melhoraDesempenhoSofridos,
                                                         &pioraDesempenhoSofridos,
                                                         &estavelSofridos,
                                                         &melhoraDesempenhoEfetuados,
                                                         &pioraDesempenhoEfetuados,
                                                         &estavelEfetuados);

        // Calcular evolução nos gols efetuados
        double mediaEfetuadosUltimoAno = times[i].calcularMediaMovel(1, campeonatos - 1, N, true);
        double mediaEfetuadosPenultimoAno = times[i].calcularMediaMovel(2, campeonatos - 1, N, true);
        float evolucaoEfetuados = (mediaEfetuadosUltimoAno / mediaEfetuadosPenultimoAno) - 1.0f;


        // Calcular evolução nos gols sofridos
        double mediaSofridosUltimoAno = times[i].calcularMediaMovel(1, campeonatos - 1, N, false);
        double mediaSofridosPenultimoAno = times[i].calcularMediaMovel(2, campeonatos - 1, N, false);
        float evolucaoSofridos = (mediaSofridosUltimoAno / mediaSofridosPenultimoAno) - 1.0f;

        // Verificar se houve maior evolução nos gols efetuados
        if (evolucaoEfetuados > maiorEvolucaoEfetuados) {
            maiorEvolucaoEfetuados = evolucaoEfetuados;
            timeMaiorEvolucaoEfetuados = &times[i];
        }

        // Verificar se houve maior evolução nos gols sofridos
        if (evolucaoSofridos > maiorEvolucaoSofridos) {
            maiorEvolucaoSofridos = evolucaoSofridos;
            timeMaiorEvolucaoSofridos = &times[i];
        }
    }



    // Mostrar resultados
    cout << "Maior evolução nos gols efetuados no último ano: " << timeMaiorEvolucaoEfetuados->getNome() << endl;
    cout << "Maior evolução nos gols sofridos no último ano: " << timeMaiorEvolucaoSofridos->getNome() << endl;
}
    

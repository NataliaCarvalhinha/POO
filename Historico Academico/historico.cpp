#include "historico.h"


ostream& operator<<(ostream& os, const Historico& historico) {
    os << "Histórico de Disciplinas:\n";
    for (const auto& disciplina : historico.disciplinas) {
        os << disciplina << "\n";
    }
    return os;
}

int Historico::operator+=(const Disciplina& disciplina) {
    size_t pos = 0;
    for (; pos < disciplinas.size(); ++pos) {
        if (disciplinas[pos] == disciplina) {
            cout << "Não é possível inserir a disciplina '" << disciplina.nome << "'. Já existe no histórico.\n";
            return -1;
        }
        if (disciplina < disciplinas[pos]) {
            break;
        }
    }
    disciplinas.insert(disciplinas.begin() + pos, disciplina);

    return pos;
}

void Historico::operator+=(const vector<Disciplina>& novasDisciplinas) {
    for (const auto& disciplina : novasDisciplinas) {
            size_t pos = 0;
        for (; pos < disciplinas.size(); ++pos) {
            if (disciplinas[pos] == disciplina) {
                cout << "Não é possível inserir a disciplina '" << disciplina.nome << "'. Já existe no histórico.\n";
                break;
            }
            if (disciplina < disciplinas[pos]) {
                disciplinas.insert(disciplinas.begin() + pos, disciplina);
                break;
            }
        }
        if (pos == disciplinas.size()) {
            disciplinas.push_back(disciplina);
        }
    }
}

int Historico::operator-=(const string& nomeDisciplina) {
    auto it = find_if(disciplinas.begin(), disciplinas.end(),
                           [&nomeDisciplina](const Disciplina& d) { return d.nome == nomeDisciplina; });

    if (it != disciplinas.end()) {
        int index = distance(disciplinas.begin(), it);
        disciplinas.erase(it);
        return index;
    } else {
        cout << "Disciplina '" << nomeDisciplina << "' não encontrada no histórico.\n";
        return -1;
    }
}

vector<Disciplina> Historico::operator()(const string& periodo) const {
    vector<Disciplina> resultado;
    for (const auto& disciplina : disciplinas) {
        if (disciplina.periodoDeConclusao == periodo) {
            resultado.push_back(disciplina);
        }
    }
    return resultado;
}

double& Historico::operator[](const string& nomeDisciplina) {
    for (auto& disciplina : disciplinas) {
        if (disciplina.nome == nomeDisciplina) {
            return disciplina.notaFinal;
        }
    }

    Disciplina novaDisciplina(nomeDisciplina, "", 0.0, -1.0);
    disciplinas.push_back(novaDisciplina);
    return disciplinas.back().notaFinal;
}

double Historico::operator>>(double& cra) const {
    double somaNotas = 0.0;
    double somaCreditos = 0.0;

    for (const auto& disciplina : disciplinas) {
        somaNotas += disciplina.notaFinal * disciplina.creditos;
        somaCreditos += disciplina.creditos;
    }

    if (somaCreditos > 0) {
        cra = somaNotas / somaCreditos;
    } else {
        cra = 0.0;
    }

    return cra;
}

void Historico::carregarDisciplinas(const string& nomeArquivo) {
    ifstream arquivo(nomeArquivo);
    if (arquivo.is_open()) {
        disciplinas.clear();
        string nome, periodo;
        double creditos, nota;
        while (arquivo >> nome >> periodo >> creditos >> nota) {
            disciplinas.emplace_back(nome, periodo, creditos, nota);
        }
        arquivo.close();
    }
}

void Historico::salvarDisciplinas(const string& nomeArquivo) const {
    ofstream arquivo(nomeArquivo);
    if (arquivo.is_open()) {
        for (const auto& disciplina : disciplinas) {
            arquivo << disciplina.nome << " "
                    << disciplina.periodoDeConclusao << " "
                    << disciplina.creditos << " "
                    << disciplina.notaFinal << "\n";
        }
        arquivo.close();
    }
}
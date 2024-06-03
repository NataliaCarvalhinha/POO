# Liga de Futebol - Projeto de Análise de Desempenho

## Descrição do Projeto

Este projeto consiste em um sistema de análise de desempenho para times de futebol, implementado em C++. O sistema é capaz de calcular médias móveis de gols efetuados e sofridos, avaliar o desempenho dos times ao longo dos anos e exibir times com maior evolução e saldo de gols por campeonato. O projeto é composto por três arquivos principais: `lib.h`, `funcoes.cpp` e `main.cpp`.

## Arquivos

### `lib.h`

Este arquivo contém as definições das classes `Time` e `Liga`, além das suas respectivas declarações de métodos.

#### Classe `Time`

- **Atributos:**
  - `string nome`: Nome do time.
  - `vector<vector<int>> golsEfetuados`: Gols efetuados pelo time em diferentes anos e campeonatos.
  - `vector<vector<int>> golsSofridos`: Gols sofridos pelo time em diferentes anos e campeonatos.

- **Métodos:**
  - `Time(string n, vector<vector<int>> ge, vector<vector<int>> gs)`: Construtor da classe.
  - `double calcularMediaMovel(int ano, int campeonato, int N, bool efetuados = true) const`: Calcula a média móvel de gols efetuados ou sofridos.
  - `const string& getNome() const`: Retorna o nome do time.
  - `double calculaSaldoDeGols(int campeonato, int ano) const`: Calcula o saldo de gols do time.
  - `void verificaEvolucaoOuRegressaoNoDesempenhoPorCampeonato(...)`: Verifica a evolução ou regressão no desempenho do time em um campeonato específico.
  - `void verificaEvolucaoOuRegressaoNoDesempenho(...)`: Verifica a evolução ou regressão no desempenho geral do time.

#### Classe `Liga`

- **Atributos:**
  - `vector<Time> times`: Lista de times na liga.
  - `int anos`: Número de anos de dados.
  - `int campeonatos`: Número de campeonatos.

- **Métodos:**
  - `Liga(int a, int c, vector<Time> t)`: Construtor da classe.
  - `void calcularMediasMoveis(int N) const`: Calcula e exibe as médias móveis dos times.
  - `void exibirTimeComMaiorSaldoDeGolsPorCampeonato() const`: Exibe o time com maior saldo de gols por campeonato.
  - `void avaliarDesempenhoTimeNosCampeonatos(int N)`: Avalia o desempenho dos times nos campeonatos.
  - `void avaliarDesempenhoTimeNoUltimoAno(int N)`: Avalia o desempenho dos times no último ano.
  - `void mostrarTimeMaiorEvolucaoUltimoAno(int N)`: Mostra o time com maior evolução no último ano.

### `funcoes.cpp`

Este arquivo contém as implementações das funções declaradas no arquivo `lib.h`.

### `main.cpp`

Este arquivo contém a função principal (`main`) do programa, que interage com o usuário através de um menu, permitindo a execução das funcionalidades implementadas.

## Como Executar

1. **Compilar o programa:**

   ```sh
   make
   ```

2. **Executar o programa:**

   ```sh
   make run
   ```

3. **Interagir com o menu:**
   - `1`: Exibir Evolução de Médias Móveis dos Times.
   - `2`: Avaliar Desempenho dos Times.
   - `3`: Exibir Time com Maior Evolução no Último Ano.
   - `4`: Exibir Time com Maior Saldo de Gols por Campeonato.
   - `5`: Mostrar Time com Maior Evolução no Último Ano.
   - `0`: Sair do programa.

## Exemplo de Uso

Ao executar o programa, o usuário verá um menu com as opções descritas acima. Selecionando uma das opções, o programa realizará a tarefa correspondente e exibirá os resultados no console.

## Autor

- **Nome:** Natália
- **Contato:** <natalia.carvalhinha@poli.ufrj.br>

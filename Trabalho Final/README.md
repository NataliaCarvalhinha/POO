
# Projeto de Sistema de Gestão de Produtos

## Descrição

Este projeto é um sistema de gestão de produtos, que permite cadastrar, atualizar, buscar, listar e excluir produtos, e também aplicar e gerenciar descontos sobre os produtos. Utiliza C++ para a lógica do sistema e Python para a conexão com o banco de dados MySQL.

## Estrutura do Projeto

O projeto possui a seguinte estrutura de arquivos:

### Arquivos C++
- **main.cpp**: Ponto de entrada do programa.
- **produto.h**: Definição da classe `Produto`.
- **produto.cpp**: Implementação da classe `Produto`.
- **produtoComDesconto.h**: Definição da classe `ProdutoComDesconto`.
- **produtoComDesconto.cpp**: Implementação da classe `ProdutoComDesconto`.
- **sistema.h**: Definição da classe `Sistema`.
- **sistema.cpp**: Implementação da classe `Sistema`.
- **conexao.h**: Definição da classe de conexão.
- **conexao.cpp**: Implementação da classe de conexão.
- **Makefile**: Arquivo de configuração para a construção do projeto.

### Arquivos Python
- **conexao.py**: Gerenciamento da conexão com o banco de dados MySQL.
- **conector.py**: Funções de interação com o banco de dados (inserção, atualização, exclusão e busca de produtos).

### Arquivo SQL
- **CreateProduto.sql**: Script para criação das tabelas no banco de dados MySQL.

## Principais Bibliotecas Utilizadas

### C++
- **Standard Library**: Utilizada para operações básicas como manipulação de strings, vetores, entre outras.
- **MySQL Connector/C++**: Biblioteca para conexão e manipulação de bancos de dados MySQL a partir de programas C++.
- **Boost.Python**: Biblioteca que facilita a integração entre C++ e Python, permitindo a execução de código Python a partir de C++.

### Python
- **mysql-connector-python**: Biblioteca que permite a conexão com o banco de dados MySQL.
- **python-dotenv**: Biblioteca para carregar variáveis de ambiente de um arquivo `.env`.

## Requisitos

- **C++**: Compilador para código C++.
- **Python**: Versão 3.6 ou superior.
- **MySQL**: Banco de dados MySQL.
- **Bibliotecas Python**:
  - `mysql-connector-python`
  - `python-dotenv`
- **Boost.Python**: Para integrar C++ com Python.

## Configuração

1. **Configuração do Banco de Dados**:
   - Utilize o script `CreateProduto.sql` para criar as tabelas necessárias no seu banco de dados MySQL.
   - Configure suas variáveis de ambiente (`.env`) com as credenciais de acesso ao banco de dados.

2. **Compilação do Projeto C++**:
   - Utilize o `Makefile` para compilar o projeto. Execute o comando:
     ```bash
     make
     ```

3. **Execução do Programa**:
   - Execute o binário gerado após a compilação para iniciar o sistema de gestão de produtos.

## Uso

### Funções C++:
- O programa principal é executado a partir de `main.cpp`.
- As classes `Produto` e `ProdutoComDesconto` são usadas para representar os produtos e seus descontos.
- A classe `Sistema` gerencia as operações no sistema.

### Funções Python:
- As funções de interação com o banco de dados estão definidas em `conector.py`, utilizando `conexao.py` para gerenciar a conexão.

### Comandos Básicos:
- **Inserir Produto**:
  ```python
  inserirProduto(nome_produto, quantidade_produto, valor_produto)
  ```
- **Buscar Produto por Código**:
  ```python
  buscarProduto(codigo_produto)
  ```
- **Atualizar Produto**:
  ```python
  atualizarProduto(codigo_produto, novo_nome_produto, nova_quantidade_produto, novo_valor_produto)
  ```
- **Deletar Produto**:
  ```python
  deletarProduto(codigo_produto)
  ```
- **Listar Produtos**:
  ```python
  listarProdutos()
  ```



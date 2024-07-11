#include "sistema.h"

Sistema::Sistema(){
    conexao = Conexao();
}

void Sistema::inserir(Produto* produto){
    conexao.inserir(produto);
}
void Sistema::remover(Produto* produto){
    conexao.remover(produto);
}
void Sistema::atualizar(Produto* produto){
    conexao.atualizar(produto);
}
Produto* Sistema::buscar(int id){
    return conexao.buscar(id);
}
        
Produto* Sistema::buscar(string& nome){
    return conexao.buscar(nome);
}

void Sistema::listar(){
    conexao.listar();
}
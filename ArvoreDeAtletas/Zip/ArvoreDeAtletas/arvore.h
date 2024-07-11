#ifndef ARVORE_H
#define ARVORE_H

#include <iostream>

using namespace std;

template <typename T>
class No {
    public:
        T* valor;
        No* esquerda;
        No* direita;

        No(T* v) : valor(v), esquerda(nullptr), direita(nullptr) {}
};

template <typename T>
class Arvore {
    private:
        No<T>* raiz;

    public:
        Arvore() : raiz(nullptr) {}

        Arvore<T>& operator+(T* valor) {
            inserir(valor);
            return *this;
        }

        Arvore<T>& operator-(T* valor) {
            remover(valor);
            return *this;
        }

        T* operator()(T valor) const {
            return buscar(raiz, valor);
        }

        void inserir(T* valor) {
            raiz = inserirRecursivo(raiz, valor);
        }

        void remover(T* valor) {
            raiz = removerRecursivo(raiz, valor);
        }

        void exibirEmOrdem() const {
            exibirEmOrdemRecursivo(raiz);
            cout << endl;
        }

        template <typename U>
        friend ostream& operator<<(ostream& os, const Arvore<U>& arvore);

    private:
        No<T>* inserirRecursivo(No<T>* no, T* valor) {
            if (no == nullptr) {
                return new No<T>(valor);
            }

            if (*valor < *no->valor) {
                no->esquerda = inserirRecursivo(no->esquerda, valor);
            } else if (*valor > *no->valor) {
                no->direita = inserirRecursivo(no->direita, valor);
            }

            return no;
        }

        No<T>* removerRecursivo(No<T>* no, T* valor) {  
            if (no == nullptr) {
                return no;
            }

            if (*valor < *no->valor) {
                no->esquerda = removerRecursivo(no->esquerda, valor);
            } else if (*valor > *no->valor) {
                no->direita = removerRecursivo(no->direita, valor);
            } else {
                if (no->esquerda == nullptr) {
                    No<T>* temp = no->direita;
                    delete no->valor;
                    delete no;
                    return temp;
                } else if (no->direita == nullptr) {
                    No<T>* temp = no->esquerda;
                    delete no->valor;
                    delete no;
                    return temp;
                }

                No<T>* temp = minimoValorNo(no->direita);
                *no->valor = *temp->valor;
                no->direita = removerRecursivo(no->direita, temp->valor);
            }

            return no;
        }

        No<T>* minimoValorNo(No<T>* no) {
            No<T>* atual = no;
            while (atual && atual->esquerda != nullptr) {
                atual = atual->esquerda;
            }
            return atual;
        }

        T* buscar(No<T>* no, T valor) const {
            if (no == nullptr) {
                return nullptr;
            }

            if (valor == *no->valor) {
                return no->valor;
            } else if (valor < *no->valor) {
                return buscar(no->esquerda, valor);
            } else {
                return buscar(no->direita, valor);
            }
        }

        void exibirEmOrdemRecursivo(No<T>* no) const {
            if (no != nullptr) {
                exibirEmOrdemRecursivo(no->esquerda);
                cout << *no->valor << " ";
                exibirEmOrdemRecursivo(no->direita);
            }
        }
};

template <typename T>
ostream& operator<<(ostream& os, const Arvore<T>& arvore) {
    arvore.exibirEmOrdem();
    return os;
}

#endif

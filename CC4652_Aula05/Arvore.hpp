//
// Created by unifjbizarri on 14/09/2018.
//

#ifndef CC4652_AULA05_ARVORE_HPP
#define CC4652_AULA05_ARVORE_HPP
#include "No.hpp"
#include <iostream>
using namespace std;
template <typename T>
class Arvore{
private:
    No<T>* raiz;
    int n;
public:
    Arvore(): raiz(NULL),n(0){}

    bool insere(T valor){
        No<T>* novo = new No<T>(valor);
        if(!novo) {
            return false;
        }
        No<T>* atual = raiz;
        No<T>* anterior = NULL;
        while(atual){
            anterior = atual;
            if(valor <= atual->valor){
                atual = atual->esq;
            }else{
                atual = atual->dir;
            }
        }
        novo->pai = anterior;
        if(anterior){
            if(valor <= anterior->valor)
                anterior->esq = novo;
            else
                anterior->dir = novo;
        }else{
            raiz = novo;
        }
        n++;
        return true;
    }

    void erd(No<T>* r){
        if(r){
            erd(r->esq);
            cout << **r << endl;
            erd(r->dir);

        }
    }

    void erd(){
        erd(raiz);
    }

    bool busca(No<T>* r,T valor){
        if(!r)
            return false;
        else{
            if(valor == r->valor)
                return true;
            else if(valor < r->valor)
                return busca(r->esq, valor);
            else
                return busca(r->dir,valor);
        }
    }
    bool busca(T valor){
        return busca(raiz, valor);
    }



};


#endif //CC4652_AULA05_ARVORE_HPP

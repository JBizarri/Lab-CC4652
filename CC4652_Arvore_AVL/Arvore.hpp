//
// Created by unifjbizarri on 05/10/2018.
//

#ifndef CC4652_ARVORE_AVL_ARVORE_HPP
#define CC4652_ARVORE_AVL_ARVORE_HPP

#include "No.hpp"
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Arvore{
private:
    No<T> *raiz;
    int n;

    void erd(No<T>* n){
        if(n){
            erd(n->esq);
            cout << n->valor<<endl;
            erd(n->dir);
        }
    }
public:
    Arvore(): raiz(nullptr), n(0){
    }

    bool insere(T valor){
        No<T> *novo = new No<T>(valor);
        if(!novo)
            return false;

        No<T>* atual = this->raiz;
        No<T>* anterior = nullptr;

        while(atual) {
            anterior = atual;
            if (valor <= atual->valor) {
                atual = atual->esq;
            } else {
                atual = atual->dir;
            }
        }

            novo->pai = anterior;
            if(!anterior){
                raiz=novo;
            }else{
                if(valor <= anterior->valor){
                    anterior->esq = novo;
                }else{
                    anterior->dir = novo;
                }
            }


        n++;
        return true;
    }

    void leftRotate(No<T>* x){
        No<T>* y = x->esq;
        No<T>* b = y-> esq;
        No<T>* pai = x->pai;

        x->pai = y;
        y->esq = x;
        x->dir = b;
        if(b)
            b->pai = x;

        y->pai = pai;
        if(y->pai){
            if(y->valor <= y->pai->valor){
                pai->esq = y;
            }else{
                pai->dir = y;
            }
        }else{
            raiz = y;
        }
    }

    void rightRotate(No<T>* y){
        No<T>* x = y->dir;
    }

    void rotateTeste(){
        leftRotate(raiz);
        rightRotate(raiz);
        erd();

    }

    void erd(){
        erd(raiz);
    }

};

#endif //CC4652_ARVORE_AVL_ARVORE_HPP

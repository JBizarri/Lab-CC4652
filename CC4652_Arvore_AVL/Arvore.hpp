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

    void red(No<T>* n){
        if(n){
            cout<< n->valor<<endl;
            red(n->esq);
            red(n->dir);
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
                    anterior->esq = novo;balancear(raiz);
                }else{
                    anterior->dir = novo;

                }
            }
        n++;
        return true;
    }

    void leftRotate(No<T>* x){
        No<T>* y = x->dir;
        No<T>* b = y->esq;
        No<T>* pai = x;

        y->esq = pai;
        pai->dir = b;

        if(b)
            b->pai = pai;

        if(x==raiz){
            raiz = y;
            y->pai = x->pai;
        }else {
            if (pai->pai->dir == pai)
                pai->pai->dir = y;
            else
                pai->pai->esq = y;
            y->pai = pai->pai;

        }
        pai->pai = y;
        if(y->dir){
            balancear(y->dir);
        }
    }

    void rightRotate(No<T>* x){
        No<T>* y = x->esq;
        No<T>* b = y->dir;
        No<T>* pai = x;

        y->dir = pai;
        pai->esq = b;

        if(b)
            b->pai = pai;

        if(x==raiz){
            raiz = y;
            y->pai = x->pai;
        }else {
            if (pai->pai->esq == pai)
                pai->pai->esq = y;
            else
                pai->pai->dir = y;
            y->pai = pai->pai;

        }
        pai->pai = y;
        if(y->esq){
            balancear(pai->esq);
        }

    }

   int altura(No<T>* n){
       int dir, esq;

       if(n== nullptr)
           return 0;
       esq = altura(n->esq);
       dir = altura(n->dir);
       if(esq > dir)
           return esq+1;
       else
           return dir+1;
   }

    int diferenca(No<T>* n){
        int altDir = altura(n->dir);
        int altEsq = altura(n->esq);
        return altEsq - altDir;
    }

    void balancear(No<T>* n){
        int fb = diferenca(n);
        if (fb>1){
            if (diferenca(n->esq) > 0) {
                rightRotate(n);
            }
            else {
                leftRotate(n);
                rightRotate(n);
            }

        }
        else if (fb < -1){
            if (diferenca(n->dir) > 0) {
                leftRotate(n);
            }
            else{
                rightRotate(n);
                leftRotate(n);

            }
        }
    }


    void erd(){
        erd(raiz);
    }

    void red(){
        red(raiz);
    }

};

#endif //CC4652_ARVORE_AVL_ARVORE_HPP

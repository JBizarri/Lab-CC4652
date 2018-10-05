//
// Created by unifjbizarri on 05/10/2018.
//

#ifndef CC4652_ARVORE_AVL_NO_HPP
#define CC4652_ARVORE_AVL_NO_HPP
template <typename T>
class Arvore;
template <typename T>
class No{
private:
    No<T>* pai;
    No<T>* esq;
    No<T>* dir;
    T valor;
    int altura;
public:
    No(T valor): pai(nullptr),esq(nullptr),dir(nullptr),valor(valor),altura(0){}
    friend class Arvore<T>;

    T getValor(){
        return valor;
    }
    int getAltura(){
        return altura;
    }
};

#endif //CC4652_ARVORE_AVL_NO_HPP

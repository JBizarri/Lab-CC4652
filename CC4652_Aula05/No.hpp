//
// Created by unifjbizarri on 14/09/2018.
//

#ifndef CC4652_AULA05_NO_HPP
#define CC4652_AULA05_NO_HPP
template <typename T>
class Arvore;
template <typename T>
class No{
private:
    T valor;
    No<T>* pai;
    No<T>* esq;
    No<T>* dir;
public:
    No(T valor): valor(valor),pai(NULL),esq(NULL),dir(NULL){}
    T getValor(){
        return valor;
    }
    T operator*(){
        return getValor();
    }
    friend class Arvore<T>;
};


#endif //CC4652_AULA05_NO_HPP

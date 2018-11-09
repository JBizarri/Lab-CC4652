#include <iostream>
#include "No.hpp"
#ifndef CC4652_AULA02_LDE_HPP
#define CC4652_AULA02_LDE_HPP


template <typename T>

class LDE {
private:
    int n;
    No<T> *first;
public:
    LDE() : n(0), first(NULL) {}

    bool insert(T value) {
        No<T>* novo = new No<T>(value);
        if (novo == NULL) {
            return false;
        }
        No<T>* preceding = NULL;
        No<T>* current = first;

        while (current && current->value < value) {
            preceding = current;
            current = current->next;
        }

        novo->next = current;
        if (preceding != NULL) {
            preceding->next = novo;
        } else {
            first = novo;
        }
        n++;
        return true;
    }

    bool remove(T value){
        No<T>* current = first;
        No<T>* preceding = NULL;

        while(current && current->value < value){
            preceding = current;
            current = current->next;
        }
        if(current && current->value ==  value){
            if(preceding) {
                preceding->next = current->next;
            }else{
                first=current->next;
            }

            delete current;
            return true;
        } else{
            std::cout << "Erro ao remover: Valor nao encontrado" << std::endl;
            return false;
        }

    }

    bool search(T value){

        No<T>* current = first;

        while(current->next != NULL && current->value < value){
            current = current->next;
        }
        if(current->value == value) {
            std::cout << "Valor encontrado: " << value << std::endl;
            return true;

        }else {
            std::cout << "Erro na busca: Valor nao encontrado " << std::endl;
            return false;
        }

    }


    void print(){
        No<T>* current = first;
        while(current){
            std::cout << current->value << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    virtual ~LDE(){
        No<T>* current = first;
        No<T>* succeeding;
        while(current){
            succeeding= current->next;
            delete current;
            current = succeeding;
        }
    }
};

#endif //CC4652_AULA02_LDE_HPP
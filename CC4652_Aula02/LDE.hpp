//
// Created by unifjbizarri on 17/08/2018.
//
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
        if (novo == nullptr) {
            return false;
        }
        No<T> *preceding = nullptr;
        No<T> *current = first;

        while (current && value > current->value) {
            preceding = current;
            current = current->next;
        }

        novo->next = current;
        if (preceding != nullptr) {
            preceding->next = novo;
        } else {
            first = novo;
        }
        n++;
        return true;
    }

    bool remove(T value){
        if(n<=0){
            std::cout<<"Vazio"<<std::endl;
            return false;
        }

        No<T> *preceding = nullptr;
        No<T> *current = first;

    }

    No<T>* search(T value){

        No<T> *preceding = nullptr;
        No<T> *current = first;

        while(current && current->value < value){
            preceding = current;
            current = current->next;
        }
        if(value != current->value){
            std::cout<<"Valor nao encontrado" << std::endl;
            return 0;
        }else{
            std::cout << "Valor encontrado" << std::endl;
            std::cout << current->value << std::endl;
            return current;
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


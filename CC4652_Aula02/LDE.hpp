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
    LDE() : n(0), first(nullptr) {}

    bool insert(T value) {
        No<T>* nNo = new No<T>(value);
        if (nNo == nullptr) {
            return false;
        }
        No<T>* preceding = nullptr;
        No<T>* current = first;

        while (current && current->value < value) {
            preceding = current;
            current = current->next;
        }

        nNo->next = current;
        if (preceding != nullptr) {
            preceding->next = nNo;
        } else {
            first = nNo;
        }
        n++;
        return true;
    }

    bool remove(T value){
        No<T>* current = first;
        No<T>* preceding = nullptr;

        while(current && current->value < value){
            preceding = current;
            current = current->next;
        }
        if(current && current->value ==  value){
            preceding->next = current->next;
            delete current;
            return true;
        } else{
            return false;
        }

    }

    bool search(T value){

        No<T> *preceding = nullptr;
        No<T> *current = first;

        while(current && value > current->value){
            preceding = current;
            current = current->next;
        }
        if(current->value != value) {
            std::cout << "Valor nao encontrado " << std::endl;
            return false;
        }else {
            std::cout << "Valor encontrado: " << current->value << std::endl;
            return true;

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


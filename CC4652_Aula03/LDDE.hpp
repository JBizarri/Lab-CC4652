#ifndef LDDE_HPP
#define LDDE_HPP
#include <iostream>
#include "No.hpp"

template <typename T>
class LDDE{
private:
    No<T>* first;
    No<T>* last;
    int n;

public:
    LDDE():first(NULL), last(NULL), n(0){

    }

    bool insert(T value){
        No<T>* novo = new No<T>(value);
        if(!novo){
            return false;
        }
        No<T>* ptrPreceding = NULL;
        No<T>* ptrCurrent = first;
        while(ptrCurrent && ptrCurrent->value < value){
            ptrPreceding = ptrCurrent;
            ptrCurrent = ptrCurrent->next;
        }
        novo->previous = ptrPreceding;

        if(ptrPreceding){
            ptrPreceding->next = novo;
        }else{
            first = novo;
        }
        novo->next = ptrCurrent;
        if(ptrCurrent){
            ptrCurrent->previous=novo;
        }else{
            last = novo;
        }
        n++;
        return true;
    }

    void print(){
        No<T>* ptr = first;
        while(ptr){
            std::cout << ptr->value << " ";
            ptr = ptr->next;
        }
        std::cout<<std::endl;
    }

    bool remove(T value){
        No<T>* ptrCurrent = first;


        while(ptrCurrent && ptrCurrent->value < value){
            ptrCurrent = ptrCurrent->next;
        }
        if(!ptrCurrent || ptrCurrent->value != value){
            return false;
        }
        No<T>* ptrPreceding = ptrCurrent->previous;
        No<T>* ptrSucceeding = ptrCurrent->next;
        if(ptrPreceding){
            ptrPreceding->next=ptrSucceeding;
        }else{
            first = ptrSucceeding;
        }
        if(ptrSucceeding){
            ptrSucceeding->previous=ptrPreceding;
        }else{
            last = ptrPreceding;
        }
        delete ptrCurrent;
        n--;
        return true;
    }

    bool search(T value){
        No<T>* current = first;

        while(current->next && current->value < value){
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

};
#endif


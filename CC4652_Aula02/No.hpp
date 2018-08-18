//
// Created by unifjbizarri on 17/08/2018.
//
#ifndef CC4652_AULA02_NO_HPP
#define CC4652_AULA02_NO_HPP
#include <iostream>

template <typename T>
class LDE;

template <typename T>

class No {
private:
    T value;
    No<T>* next;
    No(T value): value(value), next(nullptr){}
public:
    ~No(){
        std::cout<< "Deletando no" << std::endl;
    }

    friend class LDE<T>;
};

#endif //CC4652_AULA02_NO_HPP

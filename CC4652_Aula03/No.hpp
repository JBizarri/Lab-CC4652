#ifndef NO_HPP
#define NO_HPP

#include <iostream>
class LDDE;

template <typename T>
class No{
public:
    T value;
    No<T>* next;
    No<T>* previous;

    No(T value):next(NULL), previous(NULL), value(value){}


    friend class LDDE<T>;


};
#endif
#include <iostream>
#include "Arvore.hpp"

int main() {
    Arvore<int> a;
    a.insere(4);
    a.insere(1);
    a.insere(9);
    a.insere(-1);
    a.insere(-8);
    a.erd();


    //a.rotateTeste();
    return 0;
}
#include <iostream>
#include "Arvore.hpp"

int main() {
    Arvore<int> a;

    a.insere(1);
    a.insere(99);
    a.insere(88);
    a.insere(-5);
    a.insere(0);
    a.insere(-7);
    /*
    a.insere(4);
    a.insere(6);
    a.insere(8);*/
    cout << "ERD:" << endl;
    a.erd();
    cout << "RED:" << endl;
    a.red();
    return 0;
}
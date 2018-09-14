#include <iostream>
#include "Arvore.hpp"
int main() {
    Arvore<int> a;
    a.insere(5);
    a.insere(2);
    a.insere(7);
    a.insere(1);
    a.insere(3);
    a.insere(6);
    a.erd();
    int x;
    x=a.busca(8);
    cout<<x<<endl;
    x=a.busca(7);
    cout<<x<<endl;
    return 0;
}
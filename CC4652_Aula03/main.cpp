#include <iostream>
template <typename T>
#include "LDDE.hpp"


int main() {
    LDDE<int> l;
    for(int i=0;i<=10;i++){
        l.insert(i);
    }
    l.print();
    l.search(0);
    l.search(10);
    l.search(5);
    l.remove(0);
    l.remove(10);
    l.remove(5);
    l.remove(5);
    l.search(5);
    l.print();

}
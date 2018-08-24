#include <iostream>
#include "LDE.hpp"
using namespace std;

int main() {
    LDE<int> l;
    for(int i=0;i<=5;i++){
        l.insert(i);
    }

    l.print();
    l.search(5);
    l.remove(2);
    l.print();
    l.search(33);
    l.remove(33);
    l.remove(5);
    l.remove(0);
    l.print();
    return 0;
}
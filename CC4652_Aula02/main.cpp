#include <iostream>
#include "LDE.hpp"
using namespace std;

int main() {
    LDE<int> l;
    for(int i=0;i<=20;i++){
        l.insert(i);
    }

    l.print();
    l.search(10);
    l.remove(6);
    l.print();
    return 0;
}
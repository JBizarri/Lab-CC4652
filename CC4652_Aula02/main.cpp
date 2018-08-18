#include <iostream>
using namespace std;
#include "LDE.hpp"

int main() {
    LDE<int> l;
    for(int i=60;i>=0;i--) {
        l.insert(i);
    }

    l.search(70);
    l.print();
    return 0;
}
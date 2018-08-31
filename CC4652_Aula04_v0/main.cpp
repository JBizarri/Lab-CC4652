#include <iostream>
#include "FEC.hpp"
using namespace std;
int main() {
    FEC<int> f;

    f.insert(7);
    f.insert(2);
    f.insert(6);
    f.insert(3);
    f.insert(8);
    f.print();
    f.remove();
    f.remove();
    f.print();
    f.insert(5);
    f.insert(4);
    f.print();
    int temp;
    while(f.remove(&temp)){
        cout << temp << " ";
    }cout<<endl;

    return 0;
}
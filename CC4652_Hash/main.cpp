#include <iostream>
#include "LDE.hpp"
#include "Hash.hpp"
#include <ctime>
#include <vector>
using namespace std;




int main() {
    Hash<int> hash(200);
    srand(time_t(NULL));
    vector<int> v = hash.geraAleatorio(200,50);
    vector<int> h = hash.histograma(v, 50);


    for(int i = 0; i< hash.getMax();i++){

        hash.insere(v[i]);
    }

    cout<< hash.busca(50) << endl;

}
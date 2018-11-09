//
// Created by unifjbizarri on 09/11/2018.
//

#ifndef CC4652_HASH_HASH_HPP
#define CC4652_HASH_HASH_HPP

#include "LDE.hpp"
#include <vector>
#include <iostream>

using namespace std;
template <typename T>
class Hash{
private:
    int max;
    LDE<T>* v;
public:
    Hash(int max): max(max), v(new LDE<T>){

    }
    vector<int> geraAleatorio(int n, int distintos){
        vector<int> v;
        for(int i=0;i<n;i++){
            v.push_back(rand()% distintos);
        }
        return v;
    }

    vector<int> histograma(vector<int> v, int distintos){
        vector<int> h(distintos,0);
        for(int i=0;i<v.size();i++){
            h[v[i]]++;
        }
        return h;
    }

    void calculaHash(vector<int> &dados){

        for(int i=0;i<dados.size();i++){
            dados[i] = hash(dados[i], 10);
        }
    }

    int hash(int x, int tam){
        return x%tam;
    }

    void insere(T x){
        int pos = hash(x,max);
        v[pos].insert(x);
    }
    int getMax() const {
        return max;
    }

    bool busca(T x){
        int pos = hash(x,max);
        return v[pos].search(x);
    }

};

#endif //CC4652_HASH_HASH_HPP

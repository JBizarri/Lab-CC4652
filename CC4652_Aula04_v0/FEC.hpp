//
// Created by unifjbizarri on 31/08/2018.
//

#ifndef CC4652_AULA04_FEC_HPP
#define CC4652_AULA04_FEC_HPP
#define MAX 5
template <typename T>
class FEC{
private:

    int start;
    int end;
    T v[MAX+1];
    int n;
public:
    FEC(): n(MAX+1),start(0),end(0){}

    bool insert(T value){
        if(((end+1)%n) == start){
            return false;
        }
        v[end] = value;
        end = (end+1)%n;
        return true;
    }

    bool remove(T *temp=NULL){
        if(start==end){
            return false;
        }

        if (temp) {
            *temp = v[start];
        }
        start =(start+1)%n;
        return true;

    }

    void print(){
        std::cout << "Fila: ";
        for(int k = start; k!=end;k=(k+1)%n){
            std::cout << v[k] << " ";
        }
        std::cout << std::endl;
    }
};



#endif //CC4652_AULA04_FEC_HPP

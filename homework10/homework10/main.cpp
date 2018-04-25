#include <iostream>
#include <algorithm>

template <class T,int SIZE>

class ShiftArray{
public:
    ShiftArray(){}
    ~ShiftArray(){}
    T &operator[](int i){
        i = i%SIZE;
        if(i < 0) i += SIZE;
        return array[i];
    }
    void circshift(int n){
        T temp[SIZE];
        for (int i =0; i < SIZE;i++){
            temp[i]=array[i];
        }
        if (n >= 0){
            for(int j=0; j < SIZE; j++){
                array[(j+n)%SIZE]=temp[j];
            }
        }
        else{
            for(int k = 0; k < (-1*n);k++){
                for(int j=0;j < SIZE-1;j++){
                    temp[j]=array[j];
                    array[j]=array[j+1];
                    
                }
                array[SIZE-1]=temp[0];
            }
        }
    }
private:
    T array[SIZE];
};

int main(int argc, char **argv)
{
    ShiftArray<int,3> a;
    a[0] = 21;
    a[1] = -12;
    a[2] = 103;
    for (int j = 1 ; j < 5 ; j++){
        a.circshift(1);
        for (int i = 0 ; i < 3 ; i++){
            std::cout << a[i] << " ";
        }
        std::cout << std::endl;
    }
    
    // test char
    ShiftArray<char,20> mes;
    for (int i = 0 ; i < 20 ; i++){
        mes[i] = '_';
    }
    mes[0] = 'H';
    mes[1] = 'e';
    mes[2] = 'l';
    mes[3] = 'l';
    mes[4] = 'o';
    for (int j = 0 ; j < 20 ; j++){
        for (int i = 0 ; i < 20 ; i++){
            std::cout << mes[i];
        }
        std::cout << std::endl;
        mes.circshift(-1);
    }
    return 0;
}


//
// sample47.cpp
//
#include <iostream>

template<class T,int SIZE>
class CyclicArray{
public:
    // default constructor
    CyclicArray();

    // destructor
    ~CyclicArray();
    
    // [] operator overload
    T &operator[](int i);
    
private:
    // integer array
    T array[SIZE];
};

template<class T,int SIZE>
CyclicArray<T,SIZE>::CyclicArray()
{
    // nothing to do
}

template<class T,int SIZE>
CyclicArray<T,SIZE>::~CyclicArray()
{
    // nothing to do
}

template<class T,int SIZE>
T& CyclicArray<T,SIZE>::operator[](int i){
    i = i % SIZE;
    if (i < 0) i += SIZE;
    return array[i];
}

int main(int argc, const char * argv[])
{
    // integer array
    CyclicArray<int,10> ia;
    for (int i = 0 ; i < 10 ; i++){
        ia[i] = i * 10;
    }
    // print
    for (int i = -10 ; i < 20 ; i++){
        std::cout << "i=" << i << " ia(i)=" << ia[i] << std::endl;
    }
    
    // double array
    CyclicArray<double,20> da;
    for (int i = 0 ; i < 20 ; i++){
        da[i] = i * 0.12;
    }
    // print
    for (int i = -10 ; i < 20 ; i++){
        std::cout << "i=" << i << " da(i)=" << da[i] << std::endl;
    }
    return 0;
}


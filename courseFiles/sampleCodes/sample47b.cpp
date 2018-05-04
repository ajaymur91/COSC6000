// cyclic array
#include <iostream>

template <class T, int SIZE>
class CyclicArray{
public:
    // default constructor
    CyclicArray(){}
    // destructor
    ~CyclicArray(){}
    // [] operator overload: Note that it returns a reference
    T &operator[](int i){
        // Cyclic mechanism
        i = i % SIZE;
        if (i < 0) i += SIZE;
        return array[i];
    }
private:
    // integer array
    T array[SIZE];
};


int main(int argc, const char * argv[])
{
    // integer array
    CyclicArray<int,16> ia;
    for (int i = 0 ; i < 16 ; i++){
        ia[i] = i * 10.0;
    }
    // print
    for (int i = -10 ; i < 20 ; i++){
        std::cout << "i=" << i << " ia(i)=" << ia[i] << std::endl;
    }

    return 0;
}


//
// sample56.cpp
//
#include <iostream>
#include <string>

using namespace std;

class pets{
public:
    // constructor
    pets(){
        cout << "constructor of pets" << endl;
    }
    // destructor
    virtual ~pets(){
        cout << "destructor of pets" << endl;
    }
    
    // member functions
    void give_name(string name){
        pet_name = name;
    }
    
    virtual void show_name(){
        cout << "pet name is " << pet_name << endl;
    }
protected:
    string pet_name;
};

class dog: public pets{
public:
    // construncotr
    dog(){
        cout << "constructor of dog" << endl;
    };
    // destructor
    ~dog(){
        cout << "destructor of dog" << endl;
    }
    void show_name(){
        cout << "dog name is " << pet_name << endl;
    }
};


class cat: public pets{
public:
    // constructor
    cat(){
        cout << "constructor of cat" << endl;
    };
    // destructor
    ~cat(){
        cout << "destructor of cat" << endl;
    }
    void show_name(){
        cout << "cat name is " << pet_name << endl;
    }
};


int main(int argc, const char * argv[])
{
    pets* mypet[3];
    
    mypet[0] = new dog;
    mypet[0]->give_name("GOO");
    
    mypet[1] = new cat;
    mypet[1]->give_name("FOO");
    
    mypet[2] = new dog;
    mypet[2]->give_name("BOO");
    
    for (int i = 0 ; i < 3 ; i++){
        cout << i << " ";
        mypet[i]->show_name();
    }
    // delete
    for (int i = 0 ; i < 3 ; i++){
        delete mypet[i];
    }
    return 0;
}

//
// sample50.cpp
//
#include <iostream>

class Pet
{
public:
    virtual void print(){
        std::cout << "Name:" << name << std::endl;
    }
    std::string name;
};

class Dog:public Pet
{
public:
    virtual void print(){
        std::cout << "Name:" << name << std::endl;
        std::cout << "Breed:" << breed << std::endl;
    }
    std::string breed;
};

int main(int argc,char *argv[]){
    Dog vdog;
    vdog.name = "Taro";
    vdog.breed = "Shiba-Inu";
    Pet vpet = vdog;
    
    vpet.print();
    return 0;
}

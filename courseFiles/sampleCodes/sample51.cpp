//
// sample51.cpp
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
    Dog *pdog = new Dog;
    pdog->name = "Taro";
    pdog->breed = "Shiba-Inu";
    Pet *ppet = pdog;
    
    ppet->print();
    return 0;
}

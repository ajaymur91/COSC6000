#include <iostream>

// enumerate "comp" type for "compare" function
enum comp{GREATER=1, LESS=-1,EQUAL=0};
const double OZ2G = 28.35;
const int OZ2LB=16;

class Weight{
public:
    Weight();
    Weight(int lb,int oz);
    Weight(int oz);
    
    int get_Pounds() const;
    int get_Ounces() const;
    double get_Grams() const;
    
    friend Weight add(const Weight& item1,const Weight& item2);
    friend comp compare(const Weight& item1,const Weight& item2);
private:
    void convert(void);
    int lb;
    int oz;
    double g;
};
Weight::Weight():lb(0),oz(0){
    
}

Weight::Weight(int lb,int oz):lb(lb),oz(oz){
    convert();
}

Weight::Weight(int oz):lb(0),oz(oz){
    convert();
}

int Weight::get_Pounds() const{
    return lb;
}

int Weight::get_Ounces() const{
    return oz;
}

double Weight::get_Grams() const{
    return g;
}

void Weight::convert(void){
    lb+=(oz/OZ2LB);
    oz %= OZ2LB;
    g = (lb*OZ2LB+oz)*OZ2G;
}


Weight add(const Weight& item1,const Weight& item2){
    
    Weight itemSum(item1.lb + item2.lb , item1.oz + item2.oz);
    return itemSum;
}

comp compare(const Weight& item1,const Weight& item2){
    if(item1.get_Grams() > item2.get_Grams()){
        return comp::GREATER;
    }
    else if (item2.get_Grams() > item1.get_Grams()){
        return comp::LESS;
    }
    else{
        return comp::EQUAL;
    }
}





int main(int argc, const char * argv[]) {
    Weight item1(2,12);
    Weight item2(36);
    
    std::cout << "Item1 is " << item1.get_Pounds()
    << "(lb) " << item1.get_Ounces() << "(oz).\n";
    
    std::cout << "Item2 is " << item2.get_Pounds()
    << "(lb) " << item2.get_Ounces() << "(oz).\n";
    
    std::cout << "Item1 is ";
    switch(compare(item1,item2))
    {
        case GREATER:
            std::cout << "greater than ";
            break;
        case LESS:
            std::cout << "less than ";
            break;
        case EQUAL:
            std::cout << "equal to ";
            break;
        default:
            std::cout << "Something Wrong ";
    }
    std::cout << "Item2\n";
    
    Weight total = add(item1,item2);
    std::cout << "The total weight is " << total.get_Pounds()
    << "(lb) " << total.get_Ounces() << "(oz), which is equivalent to "
    << total.get_Grams() << "(g)\n";
    
    return 0;
}


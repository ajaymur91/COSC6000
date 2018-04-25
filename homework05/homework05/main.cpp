#include <iostream>

const int IN2FT=12;
const int FT2YD=3;

class USLength
{
public:
    USLength();
    USLength(int yd,int ft,int in);
    USLength(int ft,int in);
    USLength(int in);
    void setLength(int newYd,int newFt,int newIn);
    int getYards(void);
    int getFeet(void);
    int getInches(void);
    
private:
    void convert(void);
    int yd,ft,in;
};

USLength::USLength():yd(0),ft(0),in(0){
    
}

USLength::USLength(int yd,int ft,int in):yd(yd),ft(ft),in(in){
    convert();
}

USLength::USLength(int ft,int in):yd(0),ft(ft),in(in){
    convert();
}

USLength::USLength(int in):yd(0),ft(0),in(in){
    convert();
}

void USLength::setLength(int newYd, int newFt , int newIn){
    yd=newYd;
    ft=newFt;
    in=newIn;
    convert();
}

int USLength::getYards(void){
    return yd;
}

int USLength::getFeet(void){
    return ft;
}

int USLength::getInches(void){
    return in;
}

void USLength::convert(void){
    ft += in/IN2FT;
    yd += ft/FT2YD;
    in %= IN2FT;
    ft %= FT2YD;
}

int main(){
    USLength bar1(100);
    USLength bar2(3,8);
    USLength bar3(3,13);
    USLength bar4(1,2,23);
    
    std::cout << "bar1: " << bar1.getYards() << "yds " << bar1.getFeet() << "ft " << bar1.getInches() << "in " << std::endl;
    
    std::cout << "bar2: " << bar2.getYards() << "yds " << bar2.getFeet() << "ft " << bar2.getInches() << "in " << std::endl;
    
    std::cout << "bar3: " << bar3.getYards() << "yds " << bar3.getFeet() << "ft " << bar3.getInches() << "in " << std::endl;
    
    std::cout << "bar4: " << bar4.getYards() << "yds " << bar4.getFeet() << "ft " << bar4.getInches() << "in " << std::endl;
    
    USLength bar12;
    bar12.setLength(bar1.getYards()+bar2.getYards(), bar1.getFeet()+bar2.getFeet(), bar1.getInches()+bar2.getInches());
    std::cout << "bar12: " << bar12.getYards() << "yds " << bar12.getFeet() << "ft " << bar12.getInches() << "in" << std::endl;
    return 0;
}


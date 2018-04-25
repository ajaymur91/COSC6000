#ifndef USLength_hpp
#define USLength_hpp
#include <stdio.h>
#include <iostream>

const int IN2FT=12;
const int FT2YD=3;

namespace length {
    class USLength
    {
    public:
        USLength();
        USLength(int yd,int ft,int in);
        USLength(int ft,int in);
        USLength(int in);
        int getYards(void);
        int getFeet(void);
        int getInches(void);
        friend std::istream& operator >> (std::istream &strm,USLength &L1);
        friend std::ostream& operator << (std::ostream &strm,const USLength& L1);
        bool operator < (const USLength& L2) const;
        bool operator > (const USLength& L2) const;
        bool operator <= (const USLength& L2) const;
        bool operator >= (const USLength& L2) const;
        bool operator == (const USLength& L2) const;
    private:
        void convert(void);
        int yd,ft,in;
    };
}


#endif /* USLength_hpp */

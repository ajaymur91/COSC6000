
#ifndef USLength_hpp
#define USLength_hpp

#include <stdio.h>
#include <iostream>
//#include <iostream>
const int IN2FT=12;
const int FT2YD=3;

namespace diego{
    
    class USLength
    {
    public:
        USLength();
        USLength(int yd,int ft,int in);
        USLength(int ft,int in);
        USLength(int in);
        //void setLength(int newYd,int newFt,int newIn);
        int getYards(void);
        int getFeet(void);
        int getInches(void);
        friend std::ostream& operator << (std::ostream &strm,const USLength& L1);
        //friend bool operator == (const USLength& L1,const USLength& L2);
        //friend bool operator < (const USLength& L1,const USLength& L2);
        //friend bool operator <= (const USLength& L1,const USLength& L2);
        //friend bool operator >= (const USLength& L1,const USLength& L2);
        //friend bool operator > (const USLength& L1,const USLength& L2);
        bool operator == (const USLength& L2) const;
        bool operator < (const USLength& L2) const;
        bool operator <= (const USLength& L2) const;
        bool operator >= (const USLength& L2) const;
        bool operator > (const USLength& L2) const;
        friend USLength operator + (const USLength& L1,const USLength& L2);
        friend USLength operator += (USLength& L1,const USLength& L2);
        friend USLength operator * (const USLength& L1,const int& n);
        friend USLength operator * (const int& n, const USLength& L1);
        friend USLength operator / (const USLength& L1,const int& n);
        friend USLength operator *= (USLength& L1,const int& n);
        friend USLength operator /= (USLength& L1,const int& n);
    private:
        void convert(void);
        int yd,ft,in;
    };
}
#endif /* USLength_hpp */

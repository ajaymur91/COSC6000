//
//  USLength.cpp
//  HOMEWORK7
//
//  Created by dgomez on 3/16/18.
//  Copyright © 2018 dgomez. All rights reserved.
//

#include "USLength.hpp"
#include <iomanip>
#include <iostream>


namespace diego{
    
    
    //////////////////////////////
    ////// MEMBER FUNCTIONS //////
    //////////////////////////////
    
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
    
    //////////////////////////////
    /////////// GETTERS //////////
    //////////////////////////////
    
    int USLength::getYards(void){
        return yd;
    }
    
    int USLength::getFeet(void){
        return ft;
    }
    
    int USLength::getInches(void){
        return in;
    }
    
    //////////////////////////////
    /////////// CONVERT //////////
    //////////////////////////////
    
    void USLength::convert(void){
        ft += in/IN2FT;
        yd += ft/FT2YD;
        in %= IN2FT;
        ft %= FT2YD;
    }
    
    //////////////////////////////
    ////////// OVERLOADS /////////
    //////////////////////////////
    
    std::ostream& operator << (std::ostream &strm, const USLength& L1)
    {
        strm << L1.yd << "yds " << L1.ft << "ft " << L1.in << "in" << std::endl;
        
        return strm;
    }
    
    //////////////////////////////
    //////////// BOOLS ///////////
    //////////////////////////////
    
    bool USLength::operator == (const USLength& L2) const{
        return ((yd*FT2YD*IN2FT + ft*IN2FT + in) == (L2.yd*FT2YD*IN2FT + L2.ft*IN2FT + L2.in));
        //(yd + == L2.yd) && (ft == L2.ft) && (in == L2.in);
    }
    
    bool USLength::operator < (const USLength& L2) const{
        return ((yd*FT2YD*IN2FT + ft*IN2FT + in) < (L2.yd*FT2YD*IN2FT + L2.ft*IN2FT + L2.in));
    }
    
    bool USLength::operator <= (const USLength& L2) const{
        return ((yd*FT2YD*IN2FT + ft*IN2FT + in) <= (L2.yd*FT2YD*IN2FT + L2.ft*IN2FT + L2.in));
    }
    
    bool USLength::operator >= (const USLength& L2) const{
        return ((yd*FT2YD*IN2FT + ft*IN2FT + in) >= (L2.yd*FT2YD*IN2FT + L2.ft*IN2FT + L2.in));
    }
    
    bool USLength::operator > (const USLength& L2) const{
        return ((yd*FT2YD*IN2FT + ft*IN2FT + in) > (L2.yd*FT2YD*IN2FT + L2.ft*IN2FT + L2.in));
    }
    
    //////////////////////////////
    //////// ARITHMATIC //////////
    //////////////////////////////
    
    USLength operator + (const USLength& L1,const USLength& L2){
        USLength Lsum(L1.yd+L2.yd,L1.ft+L2.ft,L1.in+L2.in);
        return Lsum;
    }
    
    USLength operator += (USLength& L1,const USLength& L2){
        L1.yd += L2.yd;
        L1.ft += L2.ft;
        L1.in += L2.in;
        L1.convert();
        return L1;
    }
    
    USLength operator * (const USLength& L1,const int& n){
        USLength Ltime(L1.yd*n,L1.ft*n,L1.in*n);
        return Ltime;
    }
    
    USLength operator * (const int& n,const USLength& L1){
        USLength Ltime(n*L1.yd,n*L1.ft,n*L1.in);
        return Ltime;
    }
    
    USLength operator / (const USLength& L1,const int& n){
        USLength Ldiv(L1.yd/n,L1.ft/n,L1.in/n);
        return Ldiv;
    }
    
    USLength operator *= (USLength& L1,const int& n){
        L1.yd *= n;
        L1.ft *= n;
        L1.in *= n;
        L1.convert();
        return L1;
    }
    
    USLength operator /= (USLength& L1,const int& n){
        L1.yd /= n;
        L1.ft /= n;
        L1.in /= n;
        L1.convert();
        return L1;
    }
}



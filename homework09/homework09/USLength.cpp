#include "USLength.hpp"

namespace length {
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
    bool USLength::operator < (const USLength &L2) const{
        return ((yd*FT2YD*IN2FT + ft*IN2FT + in) < (L2.yd*FT2YD*IN2FT + L2.ft*IN2FT + in));
    }
    bool USLength::operator > (const USLength &L2) const{
        return ((yd*FT2YD*IN2FT + ft*IN2FT + in) > (L2.yd*FT2YD*IN2FT + L2.ft*IN2FT + in));
    }
    bool USLength::operator <= (const USLength &L2) const{
        return ((yd*FT2YD*IN2FT + ft*IN2FT + in) <= (L2.yd*FT2YD*IN2FT + L2.ft*IN2FT + in));
    }
    bool USLength::operator >= (const USLength &L2) const{
        return ((yd*FT2YD*IN2FT + ft*IN2FT + in) < (L2.yd*FT2YD*IN2FT + L2.ft*IN2FT + in));
    }
    bool USLength::operator == (const USLength &L2) const{
        return ((yd*FT2YD*IN2FT + ft*IN2FT + in) == (L2.yd*FT2YD*IN2FT + L2.ft*IN2FT + in));
    }
    std::istream& operator >> (std::istream &strm,USLength &L1){
        strm >> L1.yd >> L1.ft >> L1.in;
        return strm;
    }
    std::ostream& operator << (std::ostream &strm,const USLength &L1){
        strm << L1.yd << " yd, " << L1.ft << " ft, " << L1.in << " in";
        return strm;
    }
}


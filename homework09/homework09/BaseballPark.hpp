#ifndef BaseballPark_hpp
#define BaseballPark_hpp

#include <stdio.h>
#include "USLength.hpp"
#include <iostream>
#include <string>
#include <fstream>
namespace  park{
    class BaseballPark
    {
    public:
        BaseballPark();
        BaseballPark(std::string franchise,std::string stadium,std::string city,int capacity,length::USLength dimension);
        std::string get_franchise() const;
        std::string get_stadium() const;
        std::string get_city() const;
        int get_capacity() const;
        length::USLength get_dimension() const;
        void set_franchise(std::string franchise);
        void set_stadium(std::string stadium);
        void set_city(std::string city);
        void set_capacity(int capacity);
        void set_dimension(length::USLength dimension);
        friend std::istream& operator >> (std::istream &strm,BaseballPark &bp);
        friend std::ostream& operator << (std::ostream &strm,const BaseballPark &bp);
    private:
        std::string franchise,stadium,city;
        int capacity;
        length::USLength dimension;
        
    };
}

#endif /* BaseballPark_hpp */

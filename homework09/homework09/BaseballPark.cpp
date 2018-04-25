#include "BaseballPark.hpp"

namespace park {
    BaseballPark::BaseballPark():franchise("NA"),stadium("NA"),city("NA"),capacity(0),dimension(0){
        
    }
    BaseballPark::BaseballPark(std::string franchise,std::string stadium,std::string city,int capacity,length::USLength dimension):franchise(franchise),stadium(stadium),city(city),capacity(capacity),dimension(dimension){
        
    }
    std::string BaseballPark::get_franchise() const{
        return franchise;
    }
    std::string BaseballPark::get_stadium() const{
        return stadium;
    }
    std::string BaseballPark::get_city() const{
        return city;
    }
    int BaseballPark::get_capacity() const{
        return capacity;
    }
    length::USLength BaseballPark::get_dimension() const{
        return dimension;
    }
    
    void BaseballPark::set_franchise(std::string franchise){
        this -> franchise=franchise;
    }
    void BaseballPark::set_stadium(std::string stadium){
        this -> stadium=stadium;
    }
    void BaseballPark::set_city(std::string city){
        this -> city=city;
    }
    void BaseballPark::set_capacity(int capacity){
        this -> capacity=capacity;
    }
    void BaseballPark::set_dimension(length::USLength dimension){
        this -> dimension=dimension;
    }
    
    std::istream& operator >> (std::istream &strm,BaseballPark &bp){
        strm >> bp.franchise >> bp.stadium >> bp.city >> bp.capacity >> bp.dimension;
        return strm;
    }
    std::ostream& operator << (std::ostream &strm, const BaseballPark &bp){
        strm << bp.franchise << ", " << bp.stadium << ", " << bp.city << ", " << bp.capacity << ", " << bp.dimension;
        return strm;
    }
}

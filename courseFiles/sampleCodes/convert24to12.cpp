#include <iostream>
#include <string>
#include <iomanip>
#include <exception>

class TimeFormatMistake:public std::exception{
public:
    TimeFormatMistake(std::string message):message(message){}
    virtual const char *what() const throw(){
        return message.c_str();
    }
private:
    std::string message;
};

bool askYN(std::string mes){
    std::cout << mes << std::endl;
    std::string ans;
    std::cin >> ans;
    if (ans[0] == 'Y' || ans[0] == 'y') return false;
    
    return true;
}

int main(int argc, char **argv)
{
    while(1){
        // input
        std::cout << "Enter time in 24-hour notation:";
        std::string strTime;
        std::cin >> strTime;
        
        int hour=0;
        int minu=0;
        std::string ampm;
        try{
            // check length
            if (strTime.length() != 5){
                throw TimeFormatMistake("Length is not 5!");
            }
            // check separator
            if (strTime[2] != ':'){
                throw TimeFormatMistake("Separator must be \':\'!");
            }
            
            // extract
            std::string strHour = strTime.substr(0,2);
            std::string strMinu = strTime.substr(3,2);
            hour = std::stoi(strHour);
            minu = std::stoi(strMinu);
        
            // check hour
            if (hour < 0 || hour >= 24){
                throw TimeFormatMistake("Hour must be between 0 to 23.");
            }
            // check minute
            if (minu < 0 || minu >= 60){
                throw TimeFormatMistake("Minute must be between 0 to 59.");
            }
            
            // convert
            ampm = "AM";
            if (hour >= 12){
                ampm = "PM";
                if (hour > 12){
                    hour -= 12;
                }
            }
            if (hour == 0){
                hour = 12;
            }
        }
        catch (std::exception &e){
            std::cout << e.what() << std::endl;
            std::cout << "Enter a correct format time.\n";
            continue;
        }
        // print
        std::cout << "That is the same as\n";
        std::cout << hour << ':' << std::setfill('0') << std::setw(2) << minu << " " << ampm << std::endl;
    
        if (askYN("Again?(y/n)")) break;
    }
    std::cout << "End of program\n";
    
    return 0;
}


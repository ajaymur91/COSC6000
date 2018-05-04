// Program to illustrate the switch statement.#include <iostream>
# include <iostream>

int main(int arc, char *argv[]){
    char grade;
    std::cout << "Enter your midterm grade and press return: ";
    std::cin >> grade;
    
    switch(grade)
    {
        case 'A':
            std::cout << "Excellent. "
                << "You need not take the final.\n";
            break;
        case 'B':
            std::cout << "Very good.";
            grade = 'A';
            std::cout << "Your midterm grade is now "
                << grade << std::endl;
            break;
        case 'C':
            std::cout << "Passing.\n";
            break;
        case 'D':
        case 'F':
            std::cout << "Not good. "
                    << "Go study.\n";
            break;
        default:
            std::cout << "That is not a possible grade.\n";
    }
    
    return 0;
}


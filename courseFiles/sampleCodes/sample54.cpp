#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <iomanip>

class StringVar
{
public:
    /// Initializes the object so it can accept string values of length 100
    /// or less. Set the value of the object euqal to empty string.
    StringVar();
    
    /// Initializes the object so it can accept string values up to size
    /// in length. Set the value of the object euqal to empty string.
    StringVar(int size);
    
    /// Precondition: The array a contains charactors terminated with '\0'.
    /// Initializes the object so its cvalue is the string stored in a and
    /// so that it can later be set to string values up to strlen(a) in
    /// length.
    StringVar(const char a[]);
    
    /// Copy constructor
    StringVar(const StringVar &string_object);
    
    /// Destructor
    ~StringVar();
    
    /// Returns the length of the current string values.
    size_t length() const;
    
    /// Precondition: If ins is a file input stream, then ins has been
    /// connected to a file.
    /// Action: The next text in the input stream ins, up to '\n', is
    /// copied to the calling object. If there is not sufficient room,
    /// then only as much as will fit is copied.
    void input_line(std::istream &ins);
    
    /// Overload tje << operator so it can be used to putput values
    /// of type StringVar
    /// Precondition: If outs is a file output stream, then outs has
    /// already been connected to  file.
    friend std::ostream& operator <<(std::ostream &outs, const StringVar &string_object);
    
private:
    char *value;///< pointer to dynamic array that holds the string value.
    size_t max_length;///<declared max length of any string value.
};

StringVar::StringVar():StringVar(100)// calling other constructor
{
}

StringVar::StringVar(int size):max_length(size)
{
    value = new char[max_length + 1];
    value[0] = '\0';
}

StringVar::StringVar(const char a[]):max_length(strlen(a))
{
    value = new char[max_length + 1];
    strcpy(value,a);
}

StringVar::StringVar(const StringVar &string_object)
:max_length(string_object.length())
{
    value = new char[max_length + 1];
    strcpy(value,string_object.value);
}

StringVar::~StringVar()
{
    delete [] value;
}

size_t StringVar::length() const
{
    return strlen(value);
}

void StringVar::input_line(std::istream &ins){
    ins.getline(value,max_length + 1);
}

std::ostream& operator <<(std::ostream &outs, const StringVar &string_object)
{
    outs << string_object.value;
    return outs;
}


int main(int argc, const char * argv[])
{
    {
        StringVar your_name(30);
        StringVar my_name("Hideki");
        std::cout << "What is your name?\n";
        your_name.input_line(std::cin);
        std::cout << "I am " << my_name << std::endl;
        std::cout << "We will meet again " << your_name << std::endl;
     }
    return 0;
}

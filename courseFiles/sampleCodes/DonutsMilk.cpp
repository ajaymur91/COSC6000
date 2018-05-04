// Donuts and Milk 
//
#include <iostream>

using namespace std;

class NoMilk{
public:
    NoMilk():count(0){};
    NoMilk(int how_many):count(how_many){};
    int get_donuts() const { return count;};
private:
    int count;
};

int main(int argc, char **argv)
{
    int donuts;
    int milk;
    double dpg;
    try
    {
        cout << "Enter number of donuts:\n";
        cin >> donuts;
        cout << "Enter number of glasses of milk:\n";
        cin >> milk;
        if (milk <= 0) throw NoMilk(donuts);

        dpg = donuts /static_cast<double>(milk);
        cout << donuts << " donuts.\n" << milk << " glasses of milk.\n";
        cout << "You have " << dpg << " donuts per glass of milk.\n";
    }
    catch(NoMilk e)
    {
        cout << e.get_donuts() << " donuts and No milk!.\n";
        cout << "Go buy some milk!.\n";
    }
    return 0;
}



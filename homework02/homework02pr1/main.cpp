#include <iostream> //importing input/output stream
#include <iomanip> //importing input/output manipulators (seting decimal precision)

using namespace std; //setting namespace

int main(){
    
    int sum=0,score,i=0; //setting count variabls i and while loop variable n
    double average; //setting variable sum that is the "sum" of all the test "scores" and average
    //is the average of all the test scores
    
    cout << "\nThis function will take the average of test scores.\n";
    cout << "To end the the function enter in a value less than zero and the average will be\n";
    cout << "calculated without the negative value." << endl <<endl;
    //cout displays to the user how to use the function
    
    while(1){ //initialization of the while loop that will run until user puts in a value that is <0
        cout << "Enter the score for test #" << i+1 <<": "; //cout produces the strings in the terminal
        cin >> score; //user inputs of the test test score
        
        if(score < 0){ //breaks the loop if score is less than zero
            break;
        }
        
        sum+=score; //sum equals the sum of the scores
        i++; //loop counter i.e. how many tests are a part of the average
    }  //sum and counter happen at the end of the loop incase user adds negative value and that value shouldn't
    //be part of calculating the average.
    
    average=sum/(double)i; //basic mean calculation and setting average as type double
    cout.setf(ios::fixed); //input/output stream fixed
    cout.setf(ios::showpoint);//input/output stream showpoint
    cout.precision(1); //setting precision as 1 decimal
    cout << "The average of the " << i << " tests is: " << average << endl; //display of the average
    return 0;
}

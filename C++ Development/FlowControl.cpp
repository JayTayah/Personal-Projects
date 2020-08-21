#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    vector <int> vec {1,2,3};
    char letter {};
    bool check {true};
    
    
    while (check){
        
    
    cout << "P - Print numbers" << endl;
    cout << "A - Add a number" << endl;
    cout << "M - Display mean of the numbers" << endl;
    cout << "S - Display the smallest number" << endl;
    cout << "L - Display the largest number" << endl;
    cout << "Q - Quit" << endl;
    cout << "Please enter a letter from the following:" <<endl;
    
    cin >> letter;
        
    switch (letter){
        case 'p':
        case 'P': {
            if (vec.size()== 0){
                cout << "[] - the list is empty";
            }
            else {
                cout << "[ ";
                for (auto vecc: vec){
                    cout << vecc << " ";
                
                }
                cout << "]" << endl;
            }
            break;
        }
        case 'a':
        case 'A': {
            int number {};
            cout << "Enter the number you'd like to add:";
            cin >> number;
            vec.push_back (number);
            
            cout << number << " was added!";
            
            break;
        }
        case 'm':
        case 'M': {
            if (vec.size() == 0){
            cout << "Unable to calculate the mean - no data";
            }
            else {
                double sum {};
                for (auto vecc: vec){
                    sum += vecc;
                }
                cout << "The mean is: " << (sum/vec.size()) << endl;
            }
            break;
        }
        case 's':
        case 'S': {
            if (vec.size()==0){
            cout << "Unable to determine the smallest number - list is empty";
            }
            else {
                double smallest_num {};
                for (int i=0; i < vec.size(); i++){
                    if (vec[i]<smallest_num){
                        smallest_num = vec[i];
                    }
                }
                cout << "The smallest number is: " << smallest_num << endl;
            }
            break;
        }
        case 'l':
        case 'L': {
            if (vec.size()==0){
            cout << "Unable to determine the largest number - list is empty" <<endl;
            }
            else {
                double largest_num {};
                for (int i=0; i < vec.size(); i++){
                    if (vec[i]>largest_num ){
                        largest_num  = vec[i];
                    }
                }
                cout << "The largest number is: " << largest_num  << endl;
            }
            break;
        }
        case 'q':
        case 'Q': {
            cout << "Goodbye" <<endl;
            check = false;
            break;
        }
    }
    
}
    return 0;
}


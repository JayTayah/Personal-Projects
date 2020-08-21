#include <iostream>
#include <stddef.h>

using namespace std;

void print (int *arr3, size_t);
int *apply_all(int *arr1, size_t , int *arr2, size_t);

int main() {
    const size_t array1_size {5};
    const size_t array2_size {3};
    
    int array1[] {1,2,3,4,5};
    int array2[] {10,20,30};
    
    cout << "Array 1: " ;
    print(array1,array1_size);
    
    cout << "Array 2: " ;
    print(array2,array2_size);
    
    int *results = apply_all(array1, array1_size, array2, array2_size);
    constexpr size_t results_size {array1_size * array2_size};

    cout << "Result: " ;
    print(results, results_size);
    
    cout << endl;

    return 0;
}

//Print the array
void print (int *array, size_t size){
    cout << "[ ";
    for (int i=0; i<size; i++){
        cout << array[i] << " ";
    }
    cout << "]" << endl;
}

//Multiply all the integers in one array with another array
int *apply_all(int *arr1, size_t size_1, int *arr2, size_t size_2){
    
    int *new_array {nullptr};
    new_array = new int[size_1*size_2];   
    
    int new_size {0};
    for (int i{0}; i<size_1; i++){
        for (int j {0}; j<size_2; j++){
            new_array[new_size] = (arr1[i]*arr2[j]);
            new_size++;
        }
        }
        
        return new_array;
    }
/* 
Saint Petersburg State University of Telecommunications (SPBSUT)
IKPI-04
Saganenko A.V
Lab 1 
Sorting algorithms
- Bubble sort
- Heap sort
- Insertion sort
main.cpp
18.03.2022
ver 1.14
*/

#include <iostream>
#include <fstream>
#include <random>

#include "sortingalgorithms.h"

using std::cout, std::cin, std::ios, std::ofstream, std::ifstream, std::string;
const int EXTREME_LENGTH = 1000000; 

/**
    (int A, int B, int C)->(int*)
    Generates the array, with the length of A, using true random
    numbers. Seeds of the random numbers are equal to current time.
    Each value is generated within range of B...C
    Returns the array.
    >>generate_random_array(Amount of elements, max value, min value)
*/  
int *generate_random_array(int amount_of_elements, int max_value, int min_value);
/**
    (int A)->(int A[])->(int*)
    Creates the array, with the length of A, using custom (user's)
    numbers.
    Returns the array.
    >>generate_custom_array(Amount of elements)
    >>Input element with index 0: 6
    >>Input element with index 1: 10
*/  
int *generate_custom_array(int amount_of_elements);
/**
    (int* A)->(int*)
    Creates the array, taking all the numbers from the file.
    File location is: (exodus/presort.txt) Variable A
    is respond for amount of elements in the array.
    Return the array.
    >>generate_array_from_file(Amount of elements)
*/
int *generate_array_from_file(int &amount_of_elements);
/**
    (int* A, int B)->()
    Prints all values of the array A with length of B
    in console. Returns nothing.
    >>print_array(array,Amount of elements)
    >>-150
    >>56
*/ 
void print_array(int* array, int amount_of_elements);

//============================================================================

int *generate_random_array(int amount_of_elements, int max_value, int min_value)
{    
    static int array[EXTREME_LENGTH];
    srand((int)time(0));   
    for (int i = 0; i < amount_of_elements; i++)
        array[i]=rand()%(max_value-min_value+1)+min_value;
    return array;
}

int *generate_custom_array(int amount_of_elements)
{     
    static int array[EXTREME_LENGTH];
    int this_number = 0;
    for (auto i = 0; i < amount_of_elements; i++)  {   
            cout<<"Input element with index "<<i<<": ";
            cin>>this_number;
            array[i]=this_number;
        }
    return array;
}

int *generate_array_from_file(int &amount_of_elements)
{
    static int array[EXTREME_LENGTH];
    int this_number;
    string this_string;
    int amount_of_elements_local = 0;
    ifstream file("exodus/presort.txt"); 
    while (getline (file, this_string)) {
        this_number=stoi(this_string);
        array[amount_of_elements_local]=this_number;
        amount_of_elements_local++;
    }
    amount_of_elements = amount_of_elements_local;
    return array;
}

void print_array(int* array, int amount_of_elements)
{
    for (auto i = 0; i < amount_of_elements; i++)
        cout<<"i: "<<i<<" Value: "<<array[i]<<"\n";
}

//============================================================================

int main() {
    int amount_of_elements = 15000, min_value = -15000, max_value = 15000;
    int *array, *array_sorted1, *array_sorted2, *array_sorted3;
    
    cout<<"Start."<<"\n"; //.................................................

    array = generate_random_array(amount_of_elements,max_value,min_value);
    //array = generate_custom_array(amount_of_elements);
    //array = generate_array_from_file(amount_of_elements);

    //write_array(array,amount_of_elements,"presort");
    //print_array(array,amount_of_elements);
    
    array_sorted1 = bubble_sort(array,amount_of_elements);
    array_sorted2 = heap_sort(array,amount_of_elements);
    array_sorted3 = insertion_sort(array,amount_of_elements);
    
    //write_array(array_sorted1,amount_of_elements,"bubble");
    //write_array(array_sorted2,amount_of_elements,"heap");
    //write_array(array_sorted3,amount_of_elements,"insertion");
    
    write_proof(array_sorted1,array_sorted2,array_sorted3,amount_of_elements);
    
    cout<<"End."<<"\n";  //.................................................
}
#include <iostream>
using namespace std;

void printArray(int ar[], int size)
{
    cout << "\nprinting the array\n";
    for (int i = 0; i < size; i++)
    {
        cout << ar[i] << "  ";
    }
    cout << "\n**********************************\n";
}
// hello djdksjkas
int main()
{
    // declaring array
    int arr1[5];
    // printArray(arr1, 5);

    // initializing array and filling all values
    int arr2[4] = {13, 56, 2, 4};
    // printArray(arr2, 4);
    int arr3[] = {13, 56, 2, 4};
    // printArray(arr3, 4);

    // initialize array with less values than max size
    int arr4[6] = {12, 56}; // {12, 56, 0, 0, 0, 0} formed array

    // initialize array with one value 0 will create the array 
    // initialized wwith all zeroes
    int arr5[5] = {0}; // {0, 0, 0, 0, 0}
    
    return 0;
}
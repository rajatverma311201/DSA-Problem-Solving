// programiz.com article link
// https://www.programiz.com/dsa/insertion-sort
/*
Insertion Sort works on the principle of taking a element
then placing the element in correct position by shifting the left elements to the right
do this for each element starting from the 2nd element as 1st element is already sorted.
*/

/*
Time Complexity :
Best case : O(n)
Worst case : O(n^2)

Space Complexity : O(1)
*/

#include <iostream>
using namespace std;

// function declarations
void insertionSort(int ar[], int size);
void display(int ar[], int size);

// main function to execute the program
int main()
{
    int arr[10] = {2, 6, 1, -1, 0, 10, 15, 20, 19, -25};

    // display the unsorted array
    display(arr, 10);

    // call the sort function
    insertionSort(arr, 10);

    // display the sorted array
    display(arr, 10);

    return 0;
}

// this function is to sort in ascending order
/*
for sorting in descending order reverse the
inequality in if condition below
*/
void insertionSort(int ar[], int size)
{
    for (int i = 1; i < size; i++)
    {
        // pick the ith element
        int x = ar[i];
        int j = i - 1;

        // check if the ith element is lesser
        // than the elements to the left of it
        // if yes then shift the elements to the right
        // if just left element to ith element is lesser than ith
        // then loop will not be executed
        while (j >= 0 && x < ar[j])
        {
            ar[j + 1] = ar[j];
            j--;
        }
        // place the ith element in its correct position
        ar[j + 1] = x;
    }
}

// this function displays the elements of array in one line
void display(int ar[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << ar[i] << "  ";
    }
    cout << endl;
}
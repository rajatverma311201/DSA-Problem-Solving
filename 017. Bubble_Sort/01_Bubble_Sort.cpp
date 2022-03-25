// programiz.com article link
// https://www.programiz.com/dsa/bubble-sort

/*
Bubble  sort works on the principle of comparing adjacent elements
and then interchanging them if they are not sorted 
*/


/*
Time Complexity :
Best case : O(n^2)
Worst case : O(n^2)

Space Complexity : O(1)
*/

#include <iostream>
using namespace std;

// function declarations
void bubbleSort(int ar[], int size);
void display(int ar[], int size);

// main function to execute the program
int main()
{
    int arr[10] = {2, 6, 1, -1, 0, 10, 15, 20, 19, -25};

    // display the unsorted array
    display(arr, 10);

    // call the sort function
    bubbleSort(arr, 10);

    // display the sorted array
    display(arr, 10);

    return 0;
}

// this function is to sort in ascending order
/*
for sorting in descending order reverse the
inequality in if condition below
*/
void bubbleSort(int ar[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            // if just next element is less than
            // the just previous element
            // then swap them

            // this is for ascending order
            // and for descending order reverse the inequaltiy
            if (ar[j + 1] < ar[j])
                swap(ar[j + 1], ar[j]);
        }
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
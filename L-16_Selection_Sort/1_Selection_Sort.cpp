// programiz.com article link
// https://www.programiz.com/dsa/selection-sort

/*
selection sorts work on the principle :
pick the smallest element from the array and place it in its correct sorted index
repeat the above procedure for each index
*/

#include <iostream>
using namespace std;

// function declarations
void selectionSort(int ar[], int size);
void display(int ar[], int size);

// main function to execute the program
int main()
{
    int arr[10] = {2, 6, 1, -1, 0, 10, 15, 20, 19, -25};

    // display the unsorted array
    display(arr, 10);

    // call the sort function
    selectionSort(arr, 10);

    // display the sorted array
    display(arr, 10);

    return 0;
}

// this function is to sort in ascending order
/*
for sorting in descending order reverse the
inequality in if condition below
*/
void selectionSort(int ar[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        // assume ith index element as the min element index
        // for ascending order
        int minInd = i;

        for (int j = i + 1; j < size; j++)
        {
            // if current index element is less than
            // the ith index element then update
            // minIndex by current index

            // this is for ascending order
            // and for descending order reverse the inequaltiy
            if (ar[j] < ar[minInd])
                minInd = j;
        }
        // swap the ith element with the lowest element
        // from the remaining elements
        swap(ar[minInd], ar[i]);
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
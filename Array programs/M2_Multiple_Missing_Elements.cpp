/*
This is the best method used for 
finding missing element in an array
This method can be used for any type 
of array whether sorted or unsorted
*/

/*
Use Hashtable in this approach
mark the presence of a element in the array by 1 
in hash table at its index and then print the index 
which is still marked 0
*/

#include <iostream>
using namespace std;

void findMissing(int a[], int size);
int maximum(int a[], int size);
int minimum(int a[], int size);

int main()
{
    int arr[10] = {1, 2, 3, 5, 6, 7, 8, 12, 13, 16};
    cout << "The missing numbers are : \n";
    findMissing(arr, 10);
    return 0;
}

void findMissing(int a[], int size)
{
    int mx = maximum(a, 10);
    int mn = minimum(a, 10);

    int H[mx] = {0};

    for (int i = 0; i < size; i++)
    {
        H[a[i]]++;
    }

    // printing missing elements
    for (int i = mn; i <= mx; i++)
    {
        if (H[i] == 0)
            cout << i << "  ";
    }
}

int maximum(int a[], int size)
{
    int mx = a[0];
    for (int i = 0; i < size; i++)
    {
        if (a[i] > mx)
            mx = a[i];
    }
    return mx;
}

int minimum(int a[], int size)
{
    int mn = a[0];
    for (int i = 0; i < size; i++)
    {
        if (a[i] < mn)
            mn = a[i];
    }
    return mn;
}
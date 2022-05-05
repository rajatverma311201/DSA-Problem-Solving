/*
This Method works only in sorted arrays
and first element of array is 1
*/

/*
if there are first n natural numbers
and among them 1 number is missing then
we should subtract the sum of array elements
from the sum of n natural numbers

eg.   1, 2, 3, 4, 5, 6, 8, 9, 10, 11
*/

#include <iostream>
using namespace std;

int arraySum(int a[], int size);
int findMissing(int a[], int size);

int main()
{
    int arr[10] = {1, 2, 3, 4, 6, 7,8, 9, 10, 11};
    cout<<"The missing number is : "<<findMissing(arr, 10)<<"\n";
    return 0;
}

int findMissing(int a[], int size)
{
    int N = a[size - 1];

     // sum of N natural numbers - sum of array elements
    int miss = (N * (N + 1) / 2) - arraySum(a, size);

    return miss;
}

int arraySum(int a[], int size)
{
    int s = 0;
    for (int i = 0; i < size; i++)
        s += a[i];
    return s;
}
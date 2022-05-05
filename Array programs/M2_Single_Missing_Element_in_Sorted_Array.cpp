/*
This Method works only in sorted arrays
*/

/*
in this method we take help of index and element present
at it the difference between every element and its index
should be same as of first element
*/
#include <iostream>
using namespace std;

int findMissing(int a[], int size);

int main()
{
    int arr[10] = {1, 2, 3, 4, 6, 7, 8, 9, 10, 11};
    cout << "The missing number is : " << findMissing(arr, 10) << "\n";
    return 0;
}

int findMissing(int a[], int size)
{
    int miss;
    int l = a[0];
    int diff = l - 0;
    for (int i = 0; i < size; i++)
    {
        if ((a[i] - i) != diff)
        {
            miss = (diff + i);
            break;
        }
    }
    return miss;
}

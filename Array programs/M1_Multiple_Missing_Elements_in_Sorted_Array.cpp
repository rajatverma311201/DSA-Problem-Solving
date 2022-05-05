/*
This Method works only in sorted arrays
*/

/*
in this method we take help of index and element present
at it the difference between every element and its index
should be same and as soon as we get new difference 
we update the existing difference
*/

#include <iostream>
using namespace std;

void findMissing(int a[], int size);

int main()
{
    int arr[10] = {1, 2, 3, 5, 6, 7, 8, 12, 13, 16};
    cout << "The missing numbers are : \n";
    findMissing(arr,10);
    return 0;
}

void findMissing(int a[], int size)
{
    int miss;
    int l = a[0];
    int diff = l - 0;
    for (int i = 0; i < size; i++)
    {

        if ((a[i] - i) != diff)
        {
            while (diff < a[i] - i)
            {
                cout << (i + diff) << "  ";
                diff++;
            }
        }
    }
}
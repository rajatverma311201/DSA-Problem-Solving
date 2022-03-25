#include <iostream>
using namespace std;

int peakIndex(int ar[], int size)
{
    int s = 0;
    int e = size - 1;
    int mid = s + (e - s) / 2;

    int peak;
    while (s <= e)
    {
        if (ar[mid + 1] < ar[mid] && ar[mid - 1] < ar[mid])
        {
            return mid;
        }

        else if (ar[mid] < ar[mid - 1])
        {
            e = mid - 1;
        }

        else if (ar[mid] < ar[mid + 1])
        {
            s = mid + 1;
        }

        mid = s + (e - s) / 2;
    }
    return -1;
}

int main()
{
    int arr[7] = {1, 2, -5, -10, -20, -30, -90};

    // int arr[7] = {1, 2, 3, 4, 5, 6, 0};
    cout << peakIndex(arr, 7);

    return 0;
}
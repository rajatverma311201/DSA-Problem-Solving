#include <iostream>
using namespace std;

int BinarySearch(int a[], int l, int h, int key)
{
    if(l>h)
    return -1;
    
    int mid = l + (h-l)/2;
    if(key==a[mid])
    return mid;
    else if(key>a[mid])
    return BinarySearch(a, mid+1, h, key);
    else if(key<a[mid])
    return BinarySearch(a,l, mid-1, key);
}

int main()
{
    int size = 5;
    int a[] = {2, 4, 10, 14, 16};
    cout<<BinarySearch(a, 0, size-1, 14);
    return 0;
}
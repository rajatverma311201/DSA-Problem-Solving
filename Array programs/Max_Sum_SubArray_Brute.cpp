// Brute Force approach

#include <iostream>
using namespace std;

int main()
{
    int arr[] = {5, -1, -8, 7, -5, 4, 5, -1, 3, -8, -2,-10, 10};
    int size=13;
    int maxsum = 0;
    int sum = 0;
    int l = 0;
    int h = 0;

    for (int i = 0; i < size; i++)
    {
        sum = 0;
        for (int j = i; j < size; j++)
        {
            sum = sum + arr[j];
            if (sum > maxsum)
            {
                l = i;
                h = j;
                maxsum = sum;
            }
        }
    }
    cout << "sum = " << maxsum << endl;
    cout << "l = " << l << endl;
    cout << "h = " << h << endl;
    cout<<"Array : \n";
    for(int i=l; i<=h; i++)
    {
        cout<<arr[i]<<"  ";
    }

    return 0;
}
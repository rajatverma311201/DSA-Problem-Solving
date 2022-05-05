#include <iostream>
using namespace std;

int main()
{
    int arr[] = {5, -1, -8, 7, -5, 4, 5, -1, 3, -8, -2,-10, 10};
    int size=13;
    int maxsum = 0;
    int maxsum2 = 0;
    int currsum = 0;
    int currsum2 = 0;
    
    int l=0;
    int h=0;
    for (int i = 0; i < size; i++)
    {

        currsum = currsum+arr[i];
        currsum2 = currsum2 + arr[size-1-i];
        if(currsum<0)
        {
            currsum = 0;
            // cout<<"negative"<<endl<<i<<endl;
        }
        else if(currsum>maxsum)
        {

            // cout<<"positive"<<endl<<i<<endl;
            maxsum = currsum;
            h = i;
        }
        if(currsum2<0)
        {
            currsum2 = 0;
            // cout<<"negative"<<endl<<i<<endl;
        }
        else if(currsum2>maxsum2)
        {

            // cout<<"positive"<<endl<<i<<endl;
            maxsum2 = currsum2;
            l = size-1-i;
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
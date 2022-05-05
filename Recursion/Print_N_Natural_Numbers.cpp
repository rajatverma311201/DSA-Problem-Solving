#include <iostream>
using namespace std;

void Natural(int n)
{
    if(n==0)
    return;
    
    Natural(n-1);
    // printing while returning
    cout<<n<<endl;
}

int main()
{
    int c;
    cout << "Enter number of terms : ";
    cin >> c;

    Natural(c);

    return 0;
}
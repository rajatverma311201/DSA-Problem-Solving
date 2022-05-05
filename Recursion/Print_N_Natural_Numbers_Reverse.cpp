#include <iostream>
using namespace std;

void Natural(int n)
{
    if(n==0)
    return;
    
    // printing while calling
    cout<<n<<endl;
    Natural(n-1);
}

int main()
{
    int c;
    cout << "Enter number of terms : ";
    cin >> c;

    Natural(c);

    return 0;
}
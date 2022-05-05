#include <iostream>
using namespace std;

// for a to the power n (a^n)
int Power(int a, int n)
{
    if (n == 0)
        return 1;
    else
        // a^n = a * a^(n-1)
        return (a * Power(a, n - 1));
}

int main()
{
    int a;
    cout << "Enter a No. : ";
    cin >> a;
    int n;
    cout << "Enter Exponent : ";
    cin >> n;

    cout << a << " raised to " << n << " is : " << Power(a, n) << endl;

    return 0;
}
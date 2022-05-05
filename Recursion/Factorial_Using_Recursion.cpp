#include <iostream>
using namespace std;

int Fact(int n)
{
    // base case
    if (n == 0)
        return 1;
    else
        // n! = n*(n-1)!
        return (n * Fact(n - 1));
}

int main()
{
    int n;
    cout << "Enter a No. : ";
    cin >> n;

    cout << "The Factorial is : " << Fact(n) << endl;

    return 0;
}
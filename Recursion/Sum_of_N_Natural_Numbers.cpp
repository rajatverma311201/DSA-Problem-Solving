#include <iostream>
using namespace std;

// base case
int Sum(int n)
{
    if (n == 0)
        return 0;
    else
        return n + Sum(n - 1);
}

int main()
{
    int n;
    cout << "Enter number of terms : ";
    cin >> n;

    cout << "The sum of first " << n << " natural number is :" << Sum(n);

    return 0;
}
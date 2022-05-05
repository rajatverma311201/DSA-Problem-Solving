#include <iostream>
using namespace std;

// 0, 1, 1, 2, 3, 5, 8, 13, 21, 29, 50
int Fibo(int n)
{
    if (n <= 1)
        return n;
    else
        return (Fibo(n - 1) + Fibo(n - 2));
}

int main()
{
    int n;
    cout << "Enter the Term : ";
    cin >> n;
    cout << Fibo(n) << endl;

    return 0;
}
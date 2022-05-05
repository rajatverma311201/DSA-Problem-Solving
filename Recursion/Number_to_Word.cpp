#include <iostream>
using namespace std;

string word[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

void numberToWord(int n)
{
    // Base Case
    if (n == 0)
        return;

    // Recursive Calling
    numberToWord(n / 10);

    // Processing
    int d = n % 10;
    cout << word[d] << " ";
}
int main()
{
    int n;
    cout << "Enter a natural number : ";
    cin >> n;
    numberToWord(n);

    return 0;
}
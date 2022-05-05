#include <iostream>
using namespace std;

int k=0;

int *Union(int A[], int m, int B[], int n)
{
    int *C = new int[m + n];
    int i = 0;
    int j = 0;
    // int k = 0;

    while (i < m && j < n)
    {
        if (A[i] < B[j])
            C[k++] = A[i++];

        else if (B[j] < A[i])
            C[k++] = B[j++];

        else if (A[i] == B[j])
        {
            C[k++] = A[i];
            i++;
            j++;
        }
    }
    for (; i < m; i++)
        C[k++] = A[i];

    for (; j < n; j++)
        C[k++] = B[j];


    return C;
}
void printArray(int ar[], int size)
{
    cout << "\n printing the array \n";
    for (int i = 0; i < size; i++)
    {
        cout << ar[i] << "  ";
    }
    cout << "\n**********************************\n";
}

int main()
{
    int A[7] = {1, 5, 9, 13, 17, 21, 25};
    int B[5] = {2, 4, 5, 10, 12};
    int *C = Union(A, 7, B, 5);
    printArray(C, k);
    return 0;
}
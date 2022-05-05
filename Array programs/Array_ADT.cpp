#include <iostream>
using namespace std;

class Array
{
private:
    int *A;
    int size;
    int length;

public:
    // Constructors and Destructors
    Array();
    Array(int sz);
    ~Array();

    // Checker functions
    bool IsEmpty();
    bool IsFull();
    bool IsValidIndex(int index);

    void Display();

    // Modifiers
    void Push(int element);
    void Pop();
    void Insert(int index, int element);
    void Delete(int index);

    // Getter Methods
    int GetLength();
    int Get(int index);

    // Setter Methods
    void Set(int index, int element);

    // Maximum and Minimum Finder Methods
    int Max();
    int Min();

    // Searching Methods
    int LinearSearch(int key);
    int BinarySearch(int key);

    // Array Reverse Methods
    void Reverse();
};

// Default constructor
Array::Array()
{
    size = 100;
    length = 0;
    A = new int[size];
}

// Parameterized Constructor to initialize size when explicitly given
Array::Array(int sz)
{
    size = sz;
    length = 0;
    A = new int[size];
}

// Destructor
Array::~Array()
{
    delete[] A;
}

// Checks if the array is empty and returns 1 else return 0
bool Array::IsEmpty()
{
    if (length > 0)
        return false;
    else
        return true;
}

// Checks if the array is full and returns 1 else return 0
bool Array::IsFull()
{
    if (length < size)
        return false;
    else
        return true;
}

// Checks if the given index is valid and returns 1 else return 0
bool Array::IsValidIndex(int index)
{
    if (index >= 0 && index < length)
        return true;
    else
        return false;
}

// Prints the current Array
void Array::Display()
{
    if (IsEmpty())
    {
        cout << "Array Empty \n";
        return;
    }
    for (int i = 0; i < length; i++)
    {
        cout << A[i] << "  ";
    }
    cout << "\n";
}

// Inserts element after the last element
void Array::Push(int element)
{
    if (IsFull())
        cout << "Array is full \n";
    else
    {
        A[length] = element;
        length++;
    }
}

// Deletes the last element
void Array::Pop()
{
    if (IsEmpty())
        cout << "Array Empty \n";
    else
    {
        int x = A[length - 1];
        length--;
        cout << "Popped Element is : " << x;
    }
}

// Insert element at a given index
void Array::Insert(int index, int element)
{
    int j = length - 1;
    if (IsFull())
    {
        cout << "Array is full \n";
    }
    else if (index < 0 || index > length)
    {
        cout << "Invalid Index \n";
    }
    else if (index >= 0 && index <= length)
    {
        while (j >= 0 && length < size && A[j] > element)
        {
            A[j + 1] = A[j];
        }
        A[j + 1] = element;
        length++;
    }
}

// Delete Element at a given index
void Array::Delete(int index)
{
    int x = A[index];
    int i = index;
    if (IsEmpty())
    {
        cout << "Array Empty \n";
    }
    else if (index < 0 || index >= length)
    {
        cout << "Invalid Index \n";
    }
    else
    {
        while (i < length)
        {
            A[i] = A[i + 1];
        }
        length--;
        cout << "Deleted Element is : " << x;
    }
}

// Know the current length of Array
int Array::GetLength()
{
    return length;
}

// Know the element at a given index
int Array::Get(int index)
{
    if (IsValidIndex(index))
        return A[index];

    else
        return -1;
}

// Set an Element at a given index
void Array::Set(int index, int element)
{
    if (IsEmpty())
        cout << "Array Empty \n";

    else if (IsValidIndex(index))
        A[index] = element;

    else if (!IsValidIndex(index))
        cout << "Invalid Index \n";
}

// Get the Maximum Element in the Array
int Array::Max()
{
    if (IsEmpty())
    {
        cout << "Array Empty \n";
        return -1;
    }
    else
    {
        int mx = A[0];
        for (int i = 1; i < length; i++)
        {
            if (A[i] > mx)
            {
                mx = A[i];
            }
        }
        return mx;
    }
}

// Get the Minimum Element in the Array
int Array::Min()
{
    if (IsEmpty())
    {
        cout << "Array Empty \n";
        return -1;
    }
    else
    {
        int mn = A[0];
        for (int i = 1; i < length; i++)
        {
            if (A[i] < mn)
            {
                mn = A[i];
            }
        }
        return mn;
    }
}

// Search for a key in the Array using Linear Search
int Array::LinearSearch(int key)
{
    if (IsEmpty())
    {
        cout << "Array Empty \n";
        return -1;
    }
    else
    {
        for (int i = 0; i < length; i++)
        {
            if (A[i] == key)
                return i;
        }
        return -1;
    }
}

// Search for a key in the Array using Binary Search
int Array::BinarySearch(int key)
{
    if (IsEmpty())
    {
        cout << "Array Empty \n";
        return -1;
    }
    else
    {
        int l = 0;
        int h = length - 1;
        while (l <= h)
        {
            int mid = l + (h - l) / 2;
            if (A[mid] == key)
                return mid;

            else if (key > A[mid])
                l = mid + 1;

            else if (key < A[mid])
                h = mid - 1;
        }

        return -1;
    }
}

// Reverse the Array by Swapping from both ends using two pointer technique
void Array::Reverse()
{
    if (IsEmpty())
        cout << "Array Empty \n";

    else
    {
        int s = 0;
        int e = length - 1;
        while (s <= e)
        {
            swap(A[s], A[e]);
            s++;
            e--;
        }
    }
}

// Menu Driver Program for Array ADT
int main()
{
    int sz;
    cout << "Enter Size of Array : ";
    cin >> sz;
    Array arr(sz);
    int ch;
    int key, index, element;
    while (true)
    {
        cout << "0. Exit from the Program \n";
        cout << "1. bool IsEmpty() \n";
        cout << "2. bool IsFull() \n";
        cout << "3. bool IsValidIndex(int index) \n";
        cout << "4. void Display() \n";
        cout << "5. void Push(int element) \n";
        cout << "6. void Pop() \n";
        cout << "7. void Insert(int index, int element) \n";
        cout << "8. int Delete(int index) \n";
        cout << "9. int GetLength() \n";
        cout << "10. int Get(int index) \n";
        cout << "11. void Set(int index, int element) \n";
        cout << "12. int Max() \n";
        cout << "13. int Min() \n";
        cout << "14. int LinearSearch(int key) \n";
        cout << "15. int BinarySearch(int key) \n";
        cout << "16. void Reverse() \n";
        cout << "Enter your choice : ";

        bool exit = false;
        cin >> ch;

        switch (ch)
        {
        case 0:
        {
            exit = true;
            cout << "Bye Bye !!! \n";
            cout << "\n ################################################## \n \n";
            break;
        }
        case 1:
        {
            cout << arr.IsEmpty() << "\n";
            cout << "\n ################################################## \n \n";
            break;
        }

        case 2:
        {
            cout << arr.IsFull() << "\n";
            cout << "\n ################################################## \n \n";
            break;
        }

        case 3:
        {
            cout << "Enter Index to be validated : ";
            cin >> index;
            cout << arr.IsValidIndex(index) << "\n";
            cout << "\n ################################################## \n \n";
            break;
        }

        case 4:
        {
            cout << "Current Array is : \n";
            arr.Display();
            cout << "\n ################################################## \n \n";
            break;
        }

        case 5:
        {
            cout << "Enter the element to be Pushed : ";
            cin >> element;
            arr.Push(element);
            cout << "\n ################################################## \n \n";
            break;
        }

        case 6:
        {
            arr.Pop();
            cout << "\n ################################################## \n \n";
            break;
        }

        case 7:
        {
            cout << "Enter index separated by element to be Inserted : ";
            cin >> index >> element;
            arr.Insert(index, element);
            cout << "\n ################################################## \n \n";
            break;
        }

        case 8:
        {
            cout << "Enter Index to be Deleted : ";
            cin >> index;
            arr.Delete(index);
            cout << "\n ################################################## \n \n";
            break;
        }

        case 9:
        {
            cout << "Length is : " << arr.GetLength() << "\n";
            cout << "\n ################################################## \n \n";
            break;
        }

        case 10:
        {
            cout << "Enter index of the element : ";
            cin >> index;
            arr.Get(index);
            cout << "\n ################################################## \n \n";
            break;
        }

        case 11:
        {
            cout << "Enter index separated by element to Set  : ";
            cin >> index >> element;
            arr.Set(index, element);
            cout << "\n ################################################## \n \n";
            break;
        }

        case 12:
        {

            cout << "Maximum Element is : " << arr.Max() << "\n";
            cout << "\n ################################################## \n \n";
            break;
        }

        case 13:
        {
            cout << "Minimum Element is : " << arr.Min() << "\n";
            cout << "\n ################################################## \n \n";
            break;
        }

        case 14:
        {
            cout << "Enter the element to be Searched : ";
            cin >> key;
            int ind = arr.LinearSearch(key);
            if (ind >= 0)
                cout << "Element found at index : " << ind;
            else
                cout << "Element not found";
            cout << "\n ################################################## \n \n";
            break;
        }

        case 15:
        {
            cout << "Enter the element to be Searched : ";
            cin >> key;
            int ind = arr.BinarySearch(key);
            if (ind >= 0)
                cout << "Element found at index : " << ind;
            else
                cout << "Element not found";
            cout << "\n ################################################## \n \n";
            break;
        }

        case 16:
        {
            cout << "Reverse Array is : \n";
            arr.Reverse();
            cout << "\n ################################################## \n \n";
            break;
        }

        default:
            cout << "Invalid Input \n";
        }

        if (exit)
            break;
    }
    return 0;
}



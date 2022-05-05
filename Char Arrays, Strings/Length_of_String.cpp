#include <iostream>
using namespace std;

int getLength(char name[])
{
    int len=0;
    while(name[len]!='\0')
    {
        len++;
    }
    return len;
}

int main()
{
    char name[20];
    cin>>name;
    // cout<<name;


    cout<<"The length of String is : "<<getLength(name)<<"\n";
    return 0;
}
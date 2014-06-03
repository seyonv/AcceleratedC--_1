//PROGRAM OUTPUTS THE FIRST N FIBONACCI NUMBERS

#include<iostream>
using namespace std;

int fib(int n1)
{
    if (n1==1||n1==2)
        return 1;
    else
        return fib(n1-1)+fib(n1-2);
    
}

int main()
{
    int n;
    cout<<"Enter N where N is the Nth fibonacci number: ";
    cin>>n;
    while (n>0)
    {
        cout<<"\n "<<fib(n);
        n--;
    }
}
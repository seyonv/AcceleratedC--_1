//PROGRAM THAT TESTS DIFFERENT NOTATIONS/SYNTAX FOR POINTERS

#include<iostream>
#include<string>
using namespace std;

int main()
{
    //int *p       *p has type int
    //int* p        p has type int* (pointer to int)
    //int* p, q     *p and q have type int. The space has no effect.
    //int (*p),q    same as line above
    
    
    int x=5;
    cin>>x;
    int* p=&x;
    //After initializing, *p deferences p and outputs the value stored in the location pointed to by p
    //while p itself, would ouput the address that p points to (what p stores)
    cout<<"The value of variable x is "<<*p<<"\n";
    cout<<"The address of variable x is"<<p;
    return 0;
}
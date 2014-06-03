//AVERAGE CALCULATOR PROGRAM

#include <iostream>
#include <string>

using namespace std;
int main()
{
    int average=0,x;
    cout <<"Please enter 5 numbers\n";
    for (int i=0; i<5; i++)
    {
        cin>>x;
        average+=x;
    }
    
    
    cout << "\n The Average is "<<average/5<<"\n";
    return 0;
}

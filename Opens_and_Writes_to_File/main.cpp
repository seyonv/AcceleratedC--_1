//OPENS AND WRITES TO A FILE

#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ofstream myfile;
    myfile.open("example.txt");
    myfile << "OK Writing this to a file.\n";
    myfile.close();
    return 0;
}
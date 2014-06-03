//CHAPTER 3 - STORING A COLLECTION OF DATA IN A VECTOR AND OUTPUTTING THE MEDIAN


#include<iostream>
#include<iomanip>
#include<ios>
#include<string>
#include<iostream>
#include<vector> //allows use of vectores


using namespace std;

int main()
{
    cout << "Please enter yoour midterm and final grades: ";
    double midterm, final;
    
    cin >>midterm>>final;
    
    cout << "Please enter all your homework grades, followed by end of file: ";
    
    //Vector that holds objects of type double.
    
    vector<double> homework;
    double x;
    
    //if the read fails, the loop breaks
    //push_back is a member function of vectors and it APPENds an element to the end of the vector (e.g. homework.push_back(x))
    while (cin >>x)
        homework.push_back(x);
    
    //typedef defines a synonym. THerefore, instead of using the sizetp
    //The vector type defines a type named vector<double>::size_type and a function named size
    //function size returns a size_type value
    typedef vector<double>::size_type vec_sz;
    vec_sz size = homework.size();
    
    if (size==0)
    {
        cout<< "\n You must enter your grades. Please try again \n";
        
        return 1;
    }
    
    sort(homework.begin(),homework.end());
    vec_sz mid=size/2;
    int median;
    (size%2==0) ? (median=(homework[mid]+homework[mid-1])/2)
    : (median=homework[mid]);
    
    cout <<"Your final Grade is: "<<setprecision(3)
    <<0.2*midterm+0.4*final+0.4*median<<endl;
    
    
    return 0;
}


#include<iostream>
#include<iomanip>
#include<ios>
#include<string>
#include<iostream>
#include<vector>

using namespace std;

double grade(double midterm, double final, double homework)
{
    return 0.2*midterm+0.4*final+0.4*homework;
}

//entire vector<double> vec is copied and this is inefficient (PASSING BY VALUE)
double median(vector<double> vec)
{
    typedef vector<double>::size_type vec_sz;
    
    vec_sz size=vec.size();
    
    //if the vector is empty, an exception is thrown
    //execution stops and passes to another part of the program
    //along with the exception object
    if (size==0)
        throw domain_error("median of an empty vector");
    
    sort(vec.begin(),vec.end());
    
    vec_sz mid = size/2;
    return size%2==0 ? ((vec[mid]+vec[mid-1])/2) : (vec[mid]);
    
}

//reference to constant vector of type double
//vector<double> homework
//vector<double>& hw = homework; (this means that hw is a synonym for homework)
//This function is a ALSO called grade
//This is OVERLOADING and the argument list will be checked to decide which function to call
//The & asks the implementation NOT to copy its argument and const means don't change it
double grade(double midterm, double final, const vector<double>& hw)
{
    if (hw.size()==0)
        throw domain_error("student has done no homework");
    return grade(midterm,final,median(hw));
    
}

//problem of reading homework grades into a vector
//problem of designing this function is that it must return the homework grades it reads
//AND it must return an indication of whether the attempted input was succesful
//But a function can only return one value, therefore must pass an address(reference to an object)
//and modify the object located at that address


//expect function to modify its argument, therefore must pass an lvalue and not just any expression
//an lvalue is a value that denotes a NONTEMPORARY object (e.g. variable, reference). sum/count is NOT an lvalue



//read homework grades from an input stream and puts it into a vector<double>
//in is a reference to some input stream
//istream& is a reference type to an input stream object(used to read text from console, string or file)
//it RETURNS THE VECTOR STREAM THAT WAS PASSED INTO IT

istream& read_hw(istream& in, vector<double>& hw)
{
    if (in) {
        
        //remove previous contents and leaves us with an empty vector
        hw.clear();
        
        double x;
        while (in>>x)
            hw.push_back(x);
        
        //clear the stream so that input will work for the next student
        //reset any error indicatiosn so that input can continue
        in.clear();
    }
    
    //this means we were given an object that we're NOT going to a copy and we will
    //return the object without copying it
    
    return in;
}

int main()
{
    cout <<"Please enter your first name: ";
    
    string name;
    cin >>name;
    
    cout <<"Hello, "<<name <<"!"<< endl;
    
    //ask for and read midterm and final grades
    cout<<"Please enter your midterm and final grades: ";
    
    double midterm,final;
    cin>>midterm >> final;
    
    cout << "Enter all your homework grades, "
    "followed by end-of-file: ";
    
    vector<double> homework;
    
    //read the homework grades
    read_hw(cin,homework);
    
    //Comput the final grade if possible
    try {
        double final_grade = grade(midterm, final, homework);
        streamsize prec = cout.precision(); //used to save old precision and reset it after outputting
        cout << "Your final grade is "<<setprecision(3)
        <<  final_grade << setprecision(prec)<<endl;
    }
    catch(domain_error){
        cout<<endl<<"You must enter your grades. "
        "Please try again." <<endl;
        return 1;
    }
    
    
    return 0;
}


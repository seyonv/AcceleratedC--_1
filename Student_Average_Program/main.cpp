
//CALCULATING AND ORGANIZING STUDENT AVERAGES
//New program inputs from a text file in the following format (name, midterm grade, final exam grade, homework grade(s)
//Output should calculate final grade(40% median homework grade, 40% final exam, 20% midterm) ordered alphabetically

//SAMPLE INPUT                      ||                   SAMPLE OUTPUT
//Smith 93 91 47 90 92 73 100 87    ||    Carpenter 86.8
//Carpenter 75 90 87 92 93 60 0 98  ||    Smith 90.4
//...                               ||    ...


//Steps: [1] read data into a Student_info object
//       [2] generate the overall grade for a Student_info object
//       [3] sort a vector of Student_info objects

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iomanip>

using namespace std;

struct Student_info {
    string name;
    double midterm,final;
    vector<double> homework;
};

istream& read (istream& is, Student_info& s)
{
    //read and store the student's name and midterm and final exam grades
    is >> s.name >> s.midterm >> s.final;
    
    read_hw(is, s.homework); //read AND store all the student's homework grades
    return is;
    
}

//because it's a reference variable, there is no overboard in copying the object
//and modifying it in the function modifies the original variable passed in
//returns double representing OVERALL GRADE
double grade(const Student_info& s)
{
    return grade(s.midterm,s.final,s.homework);
}

//The sort function compares elements of the vector it is trying to sort
//it uses the "<" operator for the element type it is trying to sort
//but we must define "<" for the struct Student_info since it has multiple parameters

//HOWEVER, sort functio ntakes on third arguement called PREDICATE
//the predicate is a funtion that yields a boolean(true or false)
//if the predicate is present it will use this INSTEAD of the "<" operator to compare elements

//just uses the string comparison function ("A" is less than "B")

//can then call sort(students.begin(), students.end(), compare)

bool compare(const Student_info& x, const Student_info& y)
{
    return x.name < y.name;
}

int main()
{
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;
    
    //read and store all the records and find the length of the longest name
    //finding the longest name is only for the sake of formatting
    //max function is in the algorithm library
    while(read(cin,record))
    {
        maxlen= max(maxlen, record.name.size());
        students.push_back(record);
    }
    //alphabetize all the records
    sort(students.begin(),students.end(),compare);
    
    for (vector<Student_info>::size_type i =0; i!=students.size(); ++i)
    {
        //write the name padded on the right to maxlen+i characters
        cout << students[i].name
        << string(maxlen+1-students[i].name.size(),' ');
        
        
        try{
            double final_grade = grade(students[i]);
            streamsize prec = cout.precision();
            cout <<setprecision(3) <<final_grade
            <<setprecision(prec);
            
        }
        catch(domain_error e)
        {
            cout<<e.what();
        }
        cout <<endl; //skip line for the next student
    }
    
    return 0;
}

//Chapter 9 - Defining New Types
//C++ has two kinds of types: built-in types(char,int,double) and class types(string,vector,istream)

//Problems with Student_info object. Assumed that anyone who used a newly created one, would read data into it
//failure to do so would result in object with empty homework vector and undefined values for midterm and final
//and unpredictable results. If a user wants to check whether a Student_info object contained valid data
//the only way to do so would be to look at the actual data members, which would require detailed knowledge
//of how we had implemented the Student_info class. Another problem is that the "interface" to our original Student_info
//structure is scattered and by convention. Classes solve these problems
//structs members are public by default while classes' members are private by default

//class types

struct Student_info{
    std::string name;
    double midterm, final;
    std::vector<double> homework;
    
    //shown below are function headers for member functions
    std::istream& read(std::istream&); //added
    double grade() const;              //added
}
//Student_info now has 4 data elements, but also two member functions
//These member functions will let us read a record from an input stream and c

//The function is part of the Student_info structure and are available to all users of the Student_info class
//IMPORTANT POINTS
//1. Function ame is Student_info::read
//2. Do not need to pass a Student_info object as an argument. E.g. Even though  std::vector<double> homework
//isn't passed in we can still access it as the function is a member of the Student_info object.
//NO NEED TO PASS IN Student_info Object. Student_info& is IMPLICIT in each call
//3.access data elements directly, e.g. midterm vs. s.midterm (where s is a Student_info object)
//4.
istream& Student_info::read(istream& in)
{
    in>>name>>midterm>>final;
    read_hw(in,homework);
    return in;
}

//grade is a member of the Student_info object
//The "::" in fonr of grade is to make sure that it uses a version of the name
//that is not a member of anything. It tries to access the function that takes two doubles and vector<double>
//without the :: operator it would think we were referring to Student_info::grade
//also note once again that there is no need to pass in the Student_info object as it is implicit
double Student_info::grade() const
{
    return ::grade(midterm,final, homework);
}

//compare difference to old impleementation
//for member function, there is no object that is an argument therefore, we qualify that the function
//is constant and therefore CANNOT change the internal state of the object on which they are executing
//we pass a nonconstant object(a STudent_info object) to a constant function and the function treates the object
//as if it were constant
double Student_info::grade() const(..) //member function version
double grade(const Student_info&) (...) //original

//NOTE: If a function changes the state of an object(an attribute), then it ought to be a member of that object
//but for example, the compare function which looks at Student_info arguments and compares them is better to leave as a global function

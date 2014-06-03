//9.3 - Protection

//putting things in a private label makes the data elements inaccessible to users of the Student_info type
//therefore, CANNOT refere to theses elements/attributes from nonmember functions


class Student_info {
public:
    //interface goes here
    double grade() const;
    std::istream& read(std::istream&);
    
private:
    //implementation goes here
    std::string name;
    double midterm, final;
    std::vector<double> homework;
}


//Accessor functions

//now provide a way for users to retrieve a student's name but we want read access and NOT write access
//instead of giving users access to the "name" data element /attributes
//the name is a const member function which takes no arguments and which returns a string that is a copy of n.
//By copying n, rather than returing a reference, we ensure that users can read but not change the value of n
//name is an ACCESSOR FUNCTION


class Student_info {
public:
    double grade() const;
    std::istream& read(std::istream&);
    std::string name() const {return n;}
private:
    std::string n;
    double midterm,final;
    std::vector<double> homework;
}

//accessors should only be provided when they are part of the abstract interface of the class
//In the case of Student_info, our abstraction is that of a student and a corresponding final grade.
//Therefore, the notion of a student name is part of our abstraction and it is fitting to provide a name function
//but midterm, final and homework are part of our implementation but NOT part of our interface

//compare is a global function so we have to pass the Student_info objects by reference
//we must also use x.name and y.name as opposed to accessing name directly


bool compare(const Student_info& x, const Student_info& y)
{
    return x.name() < y.name();
}

//TESTING FOR EMPTY - ensure that grade function isn't called before data is held
Student_info s;
cout<<s.grade() <<endl;

//valid function will tell the user whether the object contains valid data (returning true or false)
//
class Student_info {
public:
    bool valid() const {return !homework.empty();}
    //as before
}


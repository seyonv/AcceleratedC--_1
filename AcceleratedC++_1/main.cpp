//COMPILATION OF A C++ PROGRAM
/*Steps: 1. Preprocessing, 2. Compilation, 3. Linking
 1.Preprocessing ( the preprocessor takes a c++ source code file and deals with the #includes, #defines and other
 preprocessor directives.
 
 -It works on one C++ source file (.cpp) at a time by  replacing #include directives with the content of their
 respective files, doing replacement of macros (#define), etc.
 -it works on a stream of preprocessing tokens, and macro substitution is defined as replacing tokens by other tokens
 -After all this, it produces a single output that is a stream of tokens resulting from the transformation described above
 -It also adds some special markers that tell the compiler where each line came in from so that it can use those to produce
 sensible error messages
 
 2. Compilation (compiler takes the preprocessor's output and produces a single object file from it)
 
 -compilation step is performed on each output of the preprocessor and involves parsing the C++ source code
 and producing a single object file. This object file contains the compiled code(in binary form) of the symbols
 defined in the input. Symbols in object files are referred to by name
 
 -also calls assembler before converting to object file
 
 -object files can refer to symbols that are not defined. This is the case when you use a declaration and don't
 provide a definition for it. The compiler doesn't mind this and will happily produce the object file as long as the
 source code is well-formed
 
 -At this point, compilers usually let you stop compilation. This is useful as you compile files individually
 and if you change one file, you do NOT need to recompile everything
 
 -The produced object files can be put in special archives called static libraries, for easier reusing later on
 and at THIS stage, '"regular" compiler errors are  reported
 
 3. Linking(the linker takes the object files produced by the compiler and produces either a library or an executable file
 
 -The linker is what produces the final compilation output from the object files the compiler produced. This output can either
 be a shared(or dynamic) library or an executable
 -It links all the object files by replacing the references to undefined symbols contained within them with the correct addresses
 Each of these symbols can be defined in other object files or in libraries. If they are defined in libraries other than the
 standard library, than you need to tell the linker about them.
 -At this stage, the most common errors are missing definitions or duplicate definitions. The former means that either the
 definitions don't exist(i.e. they are not written), or that the object files or libraries where they reside were not given
 to the linker
 */


//************************************************************************************************
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

//************************************************************************************************
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

//************************************************************************************************
//STORING A COLLECTION OF DATA IN A VECTOR AND OUTPUTTING THE MEDIAN


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

//************************************************************************************************
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


//************************************************************************************************
//Linked List

#include<iostream>

using namespace std;

//Create new datatype (Node)
//each node contains data itself and pointer ot the next node
//next is of type node* (pointer to a node)
struct node{
    int x;
    node* next;
};


int main()
{
    cout<<"Output the number of values you wish to Store in a linked list \n";
    
    int num_var,next_value;
    cin>>num_var;
    
    //pointers to node
    node *root=NULL; //pointer to initial memory location
    node *conductor; //pointer to current node (as list is traversed)
    for (int i=0; i<num_var; i++)
    {
        cin>>next_value;
        if (i==0)
        {
            root =new node;
            
            //ptr->next is equivalent to (*ptr).next
            root->next=0; //set address of next node to 0. This means that there is no currently assigned next node
            root->x=next_value; //set data of node(the int) to 12
            conductor = root; //conductor points to first node
            
        }
        else
        {
            
        }
        
        
        
        
    }
    
    
    //use new if you want object to remain in existence until deleted.
    //Otherwise it gets destroyed when it goes out of scope
    //however it is more expensive to use new
    
    
    //traverse until you reach the last node in the list
    if (conductor!=0){
        while (conductor->next!=0)
            conductor = conductor -> next;
    }
    conductor->next = new node;
    conductor = conductor -> next;
    conductor->next=0;
    conductor->x = 42;
    
}

//************************************************************************************************
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

//************************************************************************************************
//OPENS A FILE AND PARSES THROUGH IT AND REMOVES EXTRANEOUS CHARACTERS

#include <iostream>
using std::cout;
using std::endl;

#include <fstream>
using std::ifstream;

#include <cstring>

const int MAX_CHARS_PER_LINE = 512;
const int MAX_TOKENS_PER_LINE = 20;
const char* const DELIMITER = " ";

int main()
{
    // create a file-reading object
    ifstream fin;
    fin.open("data.txt"); // open a file
    if (!fin.good())
        return 1; // exit if file not found
    
    // read each line of the file
    while (!fin.eof())
    {
        // read an entire line into memory
        char buf[MAX_CHARS_PER_LINE];
        fin.getline(buf, MAX_CHARS_PER_LINE);
        
        // parse the line into blank-delimited tokens
        int n = 0; // a for-loop index
        
        // array to store memory addresses of the tokens in buf
        const char* token[MAX_TOKENS_PER_LINE] = {}; // initialize to 0
        
        // parse the line
        token[0] = strtok(buf, DELIMITER); // first token
        if (token[0]) // zero if line is blank
        {
            for (n = 1; n < MAX_TOKENS_PER_LINE; n++)
            {
                token[n] = strtok(0, DELIMITER); // subsequent tokens
                if (!token[n]) break; // no more tokens
            }
        }
        
        // process (print) the tokens
        for (int i = 0; i < n; i++) // n = #of tokens
            cout << "Token[" << i << "] = " << token[i] << endl;
        cout << endl;
    }
}

//************************************************************************************************
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


//************************************************************************************************
//CHAPTER 4 - ORGANIZING PROGRAMS AND DATA

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


//************************************************************************************************

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

//************************************************************************************************
//CHAPTER 5 - USING SEQUENTIAL CONTAINERS AND ANALYZING STRINGS
//want to know if students have failed a course. Therefore, we want to extrac the data from the student_info vector
//and store it in a new vector. Also want to remove the data from the original vector so it onlt
//contains information of students who have passed and push it onto another vector


bool fgrade(const Student_info& s)
{
    return grade(s) < 60;
}

//Inferior implementation
//There are two records of each student record
vector<Student_info> extract_fails(vector<Student_info>& students)
{
    Vector<Student_info> pass, fail;
    
    for(vector<Student_info>::size_type i=0; i<!=students.size(); ++i)
        if (fgrade(students[i]))
            fail.push_back(students[i]));
        else
            pass.push_back(students[i]));
    
    students = pass;
    return fail;
    
    
}


//In order to solve this problem of using extra memory
//one way is to eliminate pass entirely and just use a single local variable named fail
//As we go through the original Student_info vector, will remove it if its a failing grade
//and keep it if it's a passing grade

//NOTE*: Regardless of the solution below, there is still a problem of run time
//which is O(N^2)
//Vectors are optimized for fast random access but it is expensive to insert or delete elements
//that are NOT at the end of a vector

vector<Student_info> extract_fails(vector<Student_info>& students)
{
    vector<Student_info> fail;
    vector<Student_info>::size_type i=0;
    
    //it would be incorrect to do size = students.size() and then i!=size
    //because this size would remain constant even as records are being deleted
    //therefore. must constantly reevaluate the size of the students vector
    //
    while (i!=students.size())
    {
        if (fgrade(students[i]))
        {
            fail.push_back(students[i]);
            students.erase(students.begin()+i);
        }
        else
            ++i;
        
        //important to note that if a failing grade is encountered
        //you don't increment i as the element would be erased and everything pushed bacl
    }
    
    return fail; //return vector<Student_info> fail
}

//ITERATORS (most obvious form of an iterator is a pointer)
//Look at the container operations that extract_fails actually uses
//First, it uses the index i to fetch values from the students vector (accesses it sequentially)
//iterator is a value that
//1. identifies a container and an element in the container
//2.lets us examine the value stored in that element
//3. provides operations for moving between elements in the container
//4.Restricts the available operations in ways that correspond to twhat the container can handle efficiently



//Using index for iteration
for (vector<Student_info>::size_type i=0; i!=students.size(); ++i)
cout<<students[i].name <<endl;

//Equivalent way using iterators
for (vectir<Student_info>::const_iterator iter = students.begin(); iter!=students.end(); ++iter)
{
    //the parentheses are needed to override normal operator precedence
    //(*iter).name is equal to iter -> name
    cout <<iter->name <<endl;
}

//Every standard container, like vector, defines two associated iterator types
//container-type is the container type like vector<Student_info>
//1. container-type::const_iterator (use if you only need read access)
//2. container-type::iterator (use if you want to change the value stored in the container)

// **students.begin() and students.end() return a value of the ITERATOR type

//reimplement extract_fails function using iterators

vector<Student_info> extract_fails(vector<Student_info>& students)
{
    vector<Student_info> fail;
    vector<Student_info>::iterator iter= students.begin(); //type is iterator as we want to modify students
    while(iter!=students.end())
    {
        if (fgrade(*iter))
        {
            fail.push_back(*iter);
            iter=students.erase(iter);
            
            //calling erase invalidates every iterator after the pointer erased including students.end()
            //erase returns an interator positioned on an element that follows the one erased
        }
        else
            +iter;
    }
    
    return fail;
}

//erasing or inserting an element from a vector that is not at the end is costly
//because every element after it must be moved backward/forward

//************************************************************************************************
//REWRITING PROGRAM TO USE LIST TYPE

//Because the code now uses iterators, we have removed the reliance on indices
//rewrite program using a data structure that deletes elements efficiently within the container

//Lists are slower for random access, but are optimized for fast insertion and deletion ANYWHERE in the container
//however if program only deletes elements from the end, then vectors will outperform lists

//like a vector, the list type is a template and must define the object type
//that a list holds by naming it in angle brackets

//**NOTE: The implementations of ++iter and students.erase() are different if using list or vector
//but they have the same effect


list<Student_info> extract_fails(list<Student_info>& students)
{
    list<Student_info> fail;
    list<Student_info>::iterator iter = students.begin();
    
    while (iter!=students.end())
    {
        if (fgrade(*iter))
        {
            fail.push_back(*iter);
            iter=students.erase(iter);
        }
        else
            ++iter;
    }
    return fail;
}

//Lists have their own sort function and we must call it as shown below
list<Student_info> students;

students.sort(compare); //same compare function as for vectors(customize for particular application though)


//************************************************************************************************
//5.6 - Taking strings apart
//Might want to break a line of input into words, separated by whitespace

//Implement way to read an entire line of input and examine the words within that line
//--Write a function that takes a string and returns a vector<string> which contains entry for each word in inputted string
//function will define two indices(i & j) and we will locate a word by computing
//the vaues of i and j such that the word will be in the range [i,j)
//e.g. string s = "The fox ran". i is pointing at s[0]="T" and j is pointing at s[4]=" "

//in this case, passing by reference not because we need to modify
//but because passing by constant reference takes less memory than passing by value

//This code needs #include<cctype> which defines useful function for processing
//individual characters, including the isspace method


#include <iostream>
#include <ios>
#include <stdexcept>
#include <string>
#include <cctype>
#include <vector>
#include <iomanip>
#include <algorithm>


using std::string; using std::vector;
using std::cin;    using std::cout;
using std::endl;


vector<string> split(const string& s)
{
    vector<string> ret; //ret is the vector of strings that is being returned
    typedef string::size_type string_size; //string_size is a synonym for string::size_type
    string_size i=0;
    
    //invariant: we have processed characters [original value of i, i)
    while (i!=s.size())
    {
        //characters in range are all spaces (could be more than one space in a row)
        while (i!=s.size() && isspace(s[i]))
            ++i;
        
        //find end of next word
        //make j skip over to start of next word
        string_size j=i;
        
        //invariant: none of the characters in range [original j, current j) is a space
        while (j!=s.size() && !isspace(s[j]))
            ++j;
        
        //if we found some nonwhitespace characters
        if (i!=j)
        {
            //copy from s starting at i and taking j-1 chars
            ret.push_back(s.substr(i,j-1));
            i=j; //start from the first whitespace after the word
        }
    }
    return ret;
}

int main()
{
    string s;
    
    //read and split each line of input
    while (getline(cin,s))
    {
        vector<string> v = split(s);
        //write each word in v
        for (vector<string>::size_type i=0; i!=v.size(); ++i )
            cout<< v[i] <<endl;
    }
    return 0;
}


//************************************************************************************************
//CHAPTER 6 - USING LIBRARY ALGORITHMS
/*Every container provides companion iterator types that allows us to navigate
 through the container and examine its elements
 In general: can use the ++ operator to advance any type of iterator from one element to the next
 can use the * operator to deference and access the element associated with any type of iterator
 */

//Below two are equivalent
//1)


for (vector<string>::const_iterator it=bottom.begin(); it!=bottom.end(); ++it)
ret.push_back(*it);

//2)
ret.insert(ret.end(), bottom.begin(), bottom.end());

//GENERIC ALGORTIHM - algorithm that is not part of any particular kind of container
//but takes a cure from its arguments' types about how to access the data it uses
//normally they take iterators among their arugments

//E.g. copy algorithm takes three iterators copies all the elements in the range [begin,end) to
//a sequence of elements starting at out and extending as far as necessary
copy(begin, end, out);

//The above is equivalent to
while (begin!=end)
*out++ = *begin++;

//equivalent to

{
    *out = *begin;
    ++out;
    ++begin;
}

//ITERATOR ADAPTORS - function that yield iterators with properties that are related to their arguments in useful ways
//defined in <iterator>
//the most common iterator adaptor is back_inserter

//back_inserter takes a container as its argument and yields an iterator that, when used as a
//destination, appends values to the container
//E.g. back_inserter(ret) is an iterator that, when used as a destination, appends elements to ret

//This copies all of the elements of bottom(from begin to end) and appends them to the end of ret
//third parameter MUST be an iterator and therefore, cannot simply use ret as the 3rd parameter
copy(bottom.begin(), bottom.end(), back_inserter(ret));



//************************************************************************************************
//Rewrite split using iterators



bool space(char c)
{
	return isspace(c);
}

bool not_space(char c)
{
	return !isspace(c);
}





vector<string> split(const string& str)
{
	vector<string> ret;
	typedef string::const_iterator iter;
    
	iter i=str.begin();
    
	while (i!=str.end())
	{
		//find_if(b, e, p)
		//test each element in [b, e) against the predicate p. Stops when it finds
        //an element for which the predicate yields true
        
		//ignore leading blanks
		i= find_if(i,str.end(), not_space);
        
		//find end of next word
		iter j=find_if(i,str.end(),space);
        
		//copy the characters in [i,j)
		if (i!=j)
		{
			ret.push_back(string(i,j));
			i=j; //start from the whitespace after the word
		}
        
	}
}


//************************************************************************************************
//Palindromes - determine whether a word is a palindrome

bool is_palindrome(const string& s)
{
    //rbegin returns an interator that starts with the last element in the container
    //equal function compares two sequencs to determine whether they contatin equal values
    //the first two iterators specify the first sequence and the third iterator
    //specifies the starting point of the second sequence. It is assumed that the
    //sequences are the same size, so no fourth parameter is needed
    
    return equal(s.begin(), s.end(), s.rbegin());
    //will compare first character in s with last character in s and will move inwards and compare again
}

//************************************************************************************************

//Finding URLS(Uniform Resource Locators) that are embedded in a string
//Might use a function by creating a single string that holds the entire contents of a document and search for all urls
//URL is a sequence of characters of the form
//protocol-name://resource-name where protocol name consists of only letters and resource name is alphanumeric+special characters

//iterate through, looking for the characters ://, if found then look backward to find protocol-name
//and forward to find the resource-name


vector<string> find_urls(const string& s)
{
    vector<string> ret; //vector into which we store the URL's
    typedef string::const_iterator iter;
    iter b=s.begin(), e = s.end();
    
    //look through the entire input
    while (b!=e)
    {
        //look for one or more letters followed by ://
        b=url_beg(b,e);
        
        //if we found it
        if (b!=e)
        {
            
            //get the rest of the URL
            iter after=url_end(b,e);
            
            //remember the URL
            ret.push_back(string(b,after));
            
            //advance b and check for more URLs on this line
            b = after;
            
        }
        return ret;
    }
    
    //url_beg will be responsible for identifying whether a valid URL is present
    //AFTER the calls to url_beg and url_end the iterator b denotes the beginning o a URL
    //and the iterator after denotes the position one past the last character in the URL
    
    //e.g. randomhttp://www.google.com b=url_beg(b,e) points to the r, and after=url_end(b,e) point to the space after m in com
    //while e= s.end() points to the end of the string and beg points to the h in http
    
    //must then increment the value of b to look for the next URL. Therefore set b to be one past the end of the URL
    //which is where after is
    
    string::const_iteratator
    url_end(string::const_iterator b, string::const_iterator e)
    {
        //stops if it finds an element for which the predicate (not_url_char) yields true
        return find_if(b,e,not_url_char);
        
    }
    bool not_url_char(char c)
    {
        //characters, in addition to alphanumerics, that can appear in a URL
        //local vairables that are declared to be STATIC are preserved across invocations of the function
        //Thus, we will construct and initialize the string url_ch only on the first call to not_url_char
        //all subsequent calls will use the object that the first call created
        static const string url_ch="~;/?:@=&$-+.+!*'(),";
        
        //isalnum(c), defined in <cctype>, returns true if c is an alphanumeric character
        //find looks for the predicate (third argument) within the sequence defined by the first two arguments, iterators))
        //find returns an iterator denoting the first occurence of the value in the given sequence if the value is found
        //if the value is not found, it returns the second argument (in this case url_ch.end() )
        
        //by precedence, != is evaluated before ||
        return !(isalnum(c)|| find(url_ch.begin(),url_ch.end(),c) != url_ch.end()) ;
    }
    
    //For simplicity, assume that one or more letters precede and suceede the :/// separator
    //This functions returns iterator pointing to beginning of valid protocol
    //b is current location to start searching from and e is the absolute endpoint of the string
    string::const_iterator
    url_beg(string::const_iterator b, string::const_iterator e)
    {
        static const string sep="://";
        
        typedef string::const_iterator iter;
        
        //i marks where the separator(://) is found
        iter i=b;
        
        //search takes two pairs of iterators. The first pair denotes the sequence in which we are looking
        //the second pair denotes the sequence that we wish to locate. It returns interator to first occurence if it passes
        //if search fails, it returns the second iterator (which is e).
        while ((i=search(i,e,sep.begin(),sep.end())) != e)
        {
            //Now a separator has been found and must make sure the separator isn't at the beginning or end of the line
            if (i!=b && i+sep.size()!=e)
            {
                ///beg marks the beginning of the protocol name, which is ":"
                iter beg = i;
                
                //make sure the separator isn't at the beginning or end of the line
                while (beg!=b && isalpha(beg[-1]))
                    --beg;
                
                //is there at least one appropriate character before and after the separator
                //i[sep.size()] = *( i+sep.size() )
                
                if (beg!=i && !not_url_char(i[sep.size()]))
                    return beg;
            }
            i+=sep.size();
        }
        return e; //no valid separator found, therefore return e
    }
    
    //*******************************************************************************************************
    //6.2 - COMPARING GRADING SCHEMES
    //Two grading schemes
    //1. Average of all homeworks, zero mark for homeworks not turned in
    //2. Median of only assignments that the student actually submitted
    //Read all the student records, separating the students who did all the homework from the others
    //Apply each fo the grading schemes to all the students in each group and report the median grade of each group
    
    //function checkes whether student did all the homework
    
    bool did_all_hw(const Student_info& s)
    {
        //recall  that if 0 is not found in the sequence given by the first two iterators, then the 2nd argument is returned
        return ((find(s.homework.begin(), s.homework.end(), 0)) == s.homework.end())
        
    }
    
    vector<Student_info> did, didnt;
    Student_info student;
    
    //read all the records, separating them into the corresponding vector, did or didn't
    while (read(cin,student))
    {
        if (did_all_hw(student))
            did.push_back(student);
        else
            didnt.push_back(student);
        
    }
    
    
    //check that both groups are non-empty
    if (did.empty())
    {
        cout<<"No student compeleted all the homework!" <<endl;
        return 1;
    }
    if (didnt.empty())
    {
        cout<<"Every student completed all the homework!"<<endl;
        return 1;
    }
    
    //ANALYZE THE GRADES
    //Three analyses to perform, which each have two parts (analyze both vectors, did and didnt separately)
    //Output routine should take five arguments
    //1. The stream on which to write the output
    //2. A string that represents the name of the analysis
    //3. The function to use for the analysis
    //4 & 5. Two arguments, each of which is one of the vectors that we want to analyze
    //E.g. Assume the fist analysis is done by a function called median_analysis, then would output using the function below
    //write_analysis(cout, "median", median_analysis, did, didnt);
    
    
    
    //the transform function takes three iterators and a function. The first two iterators specify the range to transform
    //The third iterator is the destination into which to put the result of running the function
    //The fourth argument is a function that transform applies to each element of the input sequence
    //to obtain the corresponding element of the output sequence of the output sequence
    
    //back_inserter, which is an iterator adaptor, takes a container as its argument and yields an iterator that, when used as a
    //destination, appends values to the container
    //E.g. back_inserter(ret) is an iterator that, when used as a destination, appends elements to ret
    
    double median_analysis(const vector<Student_info>& students)
    {
        vector<double> grades;
        
        //The function grade is applied to every element in the range students.begin() to students.end()
        //and this is appended to the end of the grades vector
        transform(students.begin(), students.end(), back_inserter(grades), grade_aux);
        
        return median(grades);
    }
    
    //The above transform function may not work because there are several overloaded version of the grade function
    //and because it has no arguments, the compiler doesn't know which one to call.
    //Another problem is that the grade function will throw an exception if any student did no homework at all
    
    //Write an auxillary function to change this
    double grade_aux(const Student_info& s)
    {
        try {
            return grade(s);
        }
        catch (domain_error)
        {
            return grade(s.midterm, s.final, 0);
        }
    }
    
    // ** NOW JUST REPLACE grade in the transform function with grade_aux
    
    //define the write_analysis function
    
    void write_analysis(ostream& out,
                        const string& name,
                        double analysis(const vector<Student_info>&),
                        const vector<Student_info>& did,
                        const vector<Student_info>& didnt)
    {
        out <<name <<" : median(did) = "<<analysis(did)
        <<", median(didnt) = "<<analysis(didnt)<<endl;
        
    }
    
    
    int main()
    {
        //students who did and didn't do their homework
        vector<Student_info> did, didnt;
        
        //read the student records and partition them
        Student_info student;
        while (read(cin,student))
        {
            if (did_all_hw(student))
                did.push_back(student);
            else
                didnt.push_back(student);
            
        }
        
        //verify that the analyses will show us something
        if (did.empty())
        {
            cout<<"No student did all the homework!"<<endl;
            return 1;
            
        }
        if (didnt.empty()
            {
                cout<<"Every student did all the homework!"<<endl;
                return 1;
            }
            
            //do the analyses
            write_analysis(cout, "median",median_analysis, did, didnt);
            write_analysis(cout, "average",aveage_analysis, did, didnt);
            write_analysis(cout, "median of homework turned in",optimistic_median_analysis, did, didnt);
            
            return 0;
            }
            
            
            //Write the average function to use for average_analysis
            double average(const vector<double>& v)
        {
            //accumulate is defined in the <numeric> library
            //The accumulate function adds the values in range denoted by the first two arguments, starting with the
            //the value given by the third argument (which also gives the resulting type, e.g. 0.0 will make accumulate return a double
            return accumulate(v.begin(),v.end(),0.0)/v.size();
        }
            
            double average_grade(const Student_info& s)
        {
            return grade(s.midterm,s.final, average(s.homework))
        }
            
            double average_analysis(const vector<Student_info>& students)
        {
            vector<double> grades;
            
            //recall that tranform applies the average_grade function to every element between students.begin() and students.end()
            //and appends this to the end of the grade vector (which is where the iterator returned by back_inserter(grades) points to
            transform(students.begin(), students.end(),
                      back_inserter(grades), average_grade);
            
            return median(grades);
        }
            
            //Calculating optimistic_median_analysis(median of homework's turned in (nonzero homework's)
            double optimistic_median(const Student_info& s)
        {
            vector<double> nonzero;
            //extracts nonzero vectors from the homework vector and appends them to  (vector<double> nonzero)
            remove_copy(s.homework.begin(), s.homework.end(),
                        back_inserter(nonzero),0);
            
            if (nonzero.empty())
                return grade(s.midterm,s.final,0);
            else
                return grade(s.midterm, s.final,median(nonzero));
        }
            
            
            //two-pass solution
            vector<Student_info>
            extract_fails(vector<Student_info>& students)
        {
            vector<Student_info> fail;
            //remove_copy_if uses the predicate as a test and calls the function, which will then return true or false
            //and if it returns true, then the element will be "removed", meaning appended to the fail vector
            remove_copy_if(students.begin(), students.end(),
                           back_inserter(fail),pgrade);
            
            //"remove" elements corresponding to failing grades
            //what remove_if does is it copies elements that do NOT satisfy the predicate(passing grades)
            //to the beginning of the sequence and it returns an iterator that refers to one past the last
            //element that it did NOT "remove"
            //E.g. [p,p,f,f,p,f,p] -> [p,p,p,p,p,f,p] and return_if points to the fifth p while students.end() points
            //to the space after the last p
            //RESULT, afters students.erase. is only passing records
            students.erase(remove_if(students.begin(), students.end(),
                                     fgrade), students.end());
            return fail;
        }
            
            bool pgrade(const Student_info& s)
        {
            return !fgrade(s);
        }
            
            //SINGLE-PASS SOLUTION (For large inputs, this solution is essentially TWICE as fast as the double-pass one)
            //The previous solution calculates the grade for every element in students twice, once from remove_copy_if
            //and once from remove_copy
            //The algorithm partition takes a sequence and rearranges its elements so that the ones that satisfy a predicate PRECEDE
            //the ones that don't satisfy it. It returns an iterator pointing to the first element that fails the predicate
            
            //However MUST use stable_partition which keeps the same order within each half(e.g. alphabetic arrangement)
            
            vector<Student_info>
            extract_fails(vector<Student_info>& students)
        {
            vector<Student_info>::iterator iter=stable_partition(students.begin(),students.end(),pgrade);
            vector<Student_info> fail(iter,students.end()); //vector consisting of all failing elements
            
            students.erase(iter,students.end());
            return fail;
        }
            
            
            

//*******************************************************************************************************
//CHAPTER 7: USING ASSOCIATIVE CONTAINERS
//sequential containers are elements that remain in the sequence we choose for them
//Write a program that determines whether any element of a container contains the value 42, using sequential containers
//then there are two plausible strategies. 1. Inspect every element until we find 42 or run out of elements
//2. Keep the container in the appropriate order and deviese a fast algorithm (but this is difficult)
//Efficient, easy to implement option is to use associative containers

//Associative container: automatically arrange elements into a sequence
//that depends on the values of the elements themselves rather than the way we inserted them
//key, value format. E.g. If student's name is key, can efficiently find students by name
//for vectors however, the closest thing to a key is the integer index, but this is NOT really a key
//as inserting or deleting an element, not at the end, results in a change of the index

// **(Data structure that stores KEY/VALUE pairs is most common ) - ASSOCIATIVE ARRAY
//most common kind of associative array is a MAP, defined in the <map> header
//similar to vector, but index need not be an integer and may be a string or any other type of value
//on ASSOCIATIVE CONTAINERS, CANNOT use algorithms that change the contents of containers

//*******************************************************************************************************
//7.2 - COUNTING WORDS
//Pair is a simple data structure that holds two elements (first and second)
//Each element in a amap is really a pair, first element contains KEY, second element contains associated VALUE
            
#include<iostream>
#include<map>
#include<string>

using std::string; using std::map;
using std::cin; using std::cout;
using std::endl;

int main()
{
    string s;
    map<string, int> counters; //store each word an associated counter

    //read the input, keeping track of each word and how often we see it & when we encounter a word for the first time,
    //the map automatically creates a new element with that key(value-initialized to 0 for int)
    while (cin >>s)
        ++counters[s];

    //output the words and associated counts
    for (map<string,int>::const_iterator it=counters.begin(); it!=counters.end(); ++it)
    {
        //recall the it->first means (*it).first where first and second refer to the attributes string and int respectively
        cout<< it ->first << "\t" << it->second <<endl;
    }

return 0;
}

//*******************************************************************************************************
//7.3 -Generating a Cross-reference table
//This table indiciates where each word occurs in the input
//Changes are that now, instead of reading a word at a time, we'll read a line at a time
//and associate line number with words as well as break each line into its constituent word
//INSTEAD of using split directly,  will use it as a parameter  to the cross reference function
//e.g. could pass find_url to the cross-reference function to see where URLS appear in the input


//As before, will uses map with keys(distinct words from input) but values are a set of vectors that track line numbers
//on which each word appears. Therefore, we map from string to vector<int>

            
#include<iostream>
#include<map>
#include<vector>
#include<string>
            
using std::string; using std::map;
using std::cin;    using std::cout;
using std::endl;   using std::vector;
using std::istream;

vector<string> split(const string& s)
{
    vector<string> ret; //ret is the vector of strings that is being returned
    typedef string::size_type string_size; //string_size is a synonym for string::size_type
    string_size i=0;

    //invariant: we have processed characters [original value of i, i)
    while (i!=s.size())
    {
        //characters in range are all spaces (could be more than one space in a row)
        while (i!=s.size() && isspace(s[i]))
            ++i;
        
        //find end of next word
        //make j skip over to start of next word
        string_size j=i;
        
        //invariant: none of the characters in range [original j, current j) is a space
        while (j!=s.size() && !isspace(s[j]))
            ++j;
        
        //if we found some nonwhitespace characters
        if (i!=j)
        {
            //copy from s starting at i and taking j-1 chars
            ret.push_back(s.substr(i,j-1));
            i=j; //start from the first whitespace after the word
        }
    }
    return ret;
}

//must write vector<int> > and not >> because the compiler needs that space
//find_words defines a function parameter which captures ouur intent to pass to xref, the function to use to split the input into words
//saying "=split" means that we have a DEFAULT ARGUMENT and callers can omit this parameter. If they include it, it is overwritten
//e.g. If the user calls xref(cin), then split is used to find words. If the user calls xref(cin,find_urls) then find_urls is used
//to find words

//parameters are input stream and function used to split the input into words
//CREATE AND RETURN A MAP OF ALL WORDS AND THE CORRESPONDING LINE NUMBERS THEY APPEAR ON
map<string, vector<int> > xref(istream& in, vector<string> find_words(const string&) = split)
{
    string line;
    int line_number = 0;
    map<string, vector<int> > ret;

    //read the next line - get line reads from in and stores in line until the delim character or newline character ("\n") is found
    while (getline(in,line))
    {
        ++line_number;
        //break the input lint into words, presumably when given a string, the find_words function does this and returns vector<string>
        vector<string> words = find_words(line);
        
        //remember that each word occurs on the current line
        //iterator it denotes an element of words, and so *it is one of the words in the input line and we use this word to index
        //our map. The value is a vector<int> which holds the line numbers on which this word has appeared so far
        for (vector<string>::const_iterator it=words.begin(); it!= words.end(); ++it)
            ret[*it].push_back(line_number);
    }

    return ret;

};
//when we insert a new string key into the map (value-initialization), it will be associated with
//an empty vector<int>. The call to push_back will append the current line number to this initially empty vector

int main()
{
    //call xref using split by default
    map<string, vector<int> > ret = xref(cin);

    //write the results
    for (map<string, vector<int> >::const_iterator it=ret.begin(); it!=ret.end(); ++it)
    {
        //write the wrod
        cout<<it->first<<" occurs on line(s): ";
        
        //followed by the corresponding line numbers
        vector<int>::const_iterator line_it = it ->second.begin();
        cout<<*line_it; //write the first line numebr
        
        ++line_it;
        //write the rest of the line numbers, if any
        while (line_it!=it->second.end())
        {
            cout<<", "<<*line_it;
            ++line_it;
        }
        
        //write a new line to separate each word from the next
        cout <<endl;
        
    }
    return 0;
}


//*******************************************************************************************************
//7.4 - Generating sentences
//Takes a description of a sentence structure - a grammar- and generates random sentences that
//meet that description. E.g. might describe a sentence as a noun and a verb and an object or noun and a verb, etc.
//E.g. Categories || Rules
//<noun>          || cat
//<noun>          || dog
//<noun-phrase>   || <noun>
//<verb>          || jumps
//<verb>          || runs
//<location>      || on the stairs
//<sentence>      || the <noun-phrase> <verb> <location>

//Program should FIRST find the rule for how to make a sentence & then resolve the first rule it encounters and resolve the rest
//Table containts two kinds of entries: categories, enclosed in <>, and ordinary words. Each category has one or more rules
//each ordinary words simply stands for itself
//Need a map that maps categories to the corresponding rules. Categories are stored as strings, but rules arem ore complex
//category sentence is associated with rule that has 3 categories and one ordinary word
//easiest way to manage multiple instances of the same key is to store each collection of rules in its OWN vector
//THEREFORE, grammar is stored in a map from string to vectors which themselves hold vector<string> (vector<vector<string> >)


#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<stdexcept>
            
using std::string;      using std::map;
using std::cin;         using std::cout;
using std::endl;        using std::vector;
using std::istream;     using std::domain_error;
using std::logic_error;

vector<string> split(const string& s)
{
    vector<string> ret; //ret is the vector of strings that is being returned
    typedef string::size_type string_size; //string_size is a synonym for string::size_type
    string_size i=0;

    //invariant: we have processed characters [original value of i, i)
    while (i!=s.size())
    {
        //characters in range are all spaces (could be more than one space in a row)
        while (i!=s.size() && isspace(s[i]))
            ++i;
        
        //find end of next word
        //make j skip over to start of next word
        string_size j=i;
        
        //invariant: none of the characters in range [original j, current j) is a space
        while (j!=s.size() && !isspace(s[j]))
            ++j;
        
        //if we found some nonwhitespace characters
        if (i!=j)
        {
            //copy from s starting at i and taking j-1 chars
            ret.push_back(s.substr(i,j-1));
            i=j; //start from the first whitespace after the word
        }
    }
    return ret;
}


typedef vector<string> Rule;
typedef vector<Rule> Rule_collection;
typedef map<string, Rule_collection> Grammar;

int nrand(int n);
void gen_aux(const Grammar& g, const string& word, vector<string>& ret);

Grammar read_grammar(istream& in);
vector<string> gen_sentence(const Grammar& g);
vector<string> gen_sentence(const Grammar& g);
bool bracketed(const string& s);
void gen_aux(const Grammar& g, const string& word, vector<string>& ret);

//selecting a random element using standard libraries rand() function
//which takes no arguments and returns an random integer in the range [0,RAND_MAX), RAND_MAX is fixed largest integer
//must reduce this range to [0,n)

//will partition the available random numbers into n equal-sized buckets, perhaps with some numbers left over
//Then we can computer a random number, figure out which bucket it falls, and return that bucket's number
//function returns a random integer in range [0,n)
int nrand(int n)
{
    if (n<=0||n>RAND_MAX)
        throw domain_error("Argument to nrand is out of range");
    const int bucket_size = RAND_MAX/n;
    int r;
    do r=rand()/bucket_size; //integer division truncates the result
    while (r>=n);

    return r;
}

//Read from an input stream and return the corresponding grammar (map<string, Rule_collection>)
Grammar read_grammar(istream& in)
{
    Grammar ret;
    string line;

    //read the input
    while (getline(in,line))
    {
        //split the input into words
        vector<string> entry = split(line);
        
        //if entry is empty, then it's a blank line and we disregard it
        if (!entry.empty())
            //CONSTRUCT A NEW, UNNAMED RULE by copying the elements from entry
            //entry[0] is a string(the CATEGORY) and ret[entry[0]] is a Rule_collection(vector<Rule>) which is being appended to
            //push all element from the 2nd to the end, the 1st element is the category
            ret[entry[0]].push_back(Rule (entry.begin()+1, entry.end()) );
    }
    return ret;
};


//Generating the sentence - input will be grammar and output will be vector<string>, the sentence
//must initially find a rule that corresponds to sentence. And will build output in pieces
//not by concatenating them, but by pushing them onto an empty vector using push_back

vector<string> gen_sentence(const Grammar& g)
{
    vector<string> ret;
    gen_aux(g,"<sentence>",ret); //auxillary function that will act as sentence generator
    return ret;
}

//Note that gen_aux will need to determien whether a word represents a category and it will
//do so by checking if ht word has angle brackets around it
bool bracketed(const string& s)
{
    return s.size()>1 && s[0] == '<' && s[s.size()-1] == '>';
}

//The job of gen_aux is to expand the input string that it is given as its second argument, by looking up that string in the
//grammar that is its first parameter and placing its output into the third parameter (given as ret)

void gen_aux(const Grammar& g, const string& word, vector<string>& ret)
{
    if(!bracketed(word)){
        ret.push_back(word);
    }
    else
    {
        //locate the rule that corresponds to word
        //cannot use g(word) because if it doesn't exist, it will try to create a newkey
        //and this will crash as grammar is a constant map. g.find(word) looks for the iterator that refers to the element word
        //and if none exist, it returns g.end()
        Grammar::const_iterator it=g.find(word);
        
        //now it points to an element of the map g, which is a pair that can be accessed by dereferencing
        if(it==g.end())
            throw logic_error("empty rule");
        
        //fetch the set of possible rules
        const Rule_collection& c=it->second; //(*it).second - All the rules corresponding to a category are stored here
        
        //from which we select a rule at random. Remember that Rule is vector<string>
        const Rule& r=c[nrand(c.size())];
        
        //recursively expand the selected rule
        for (Rule::const_iterator i=r.begin(); i!=r.end(); ++i)
            gen_aux(g, *i, ret);
    }

}



int main()
{
    //generate the sentence. Recall the ret is returned, which is where the words are pushed onto
    vector<string> sentence = gen_sentence(read_grammar(cin));

    //write the first word, if any
    vector<string>::const_iterator it=sentence.begin();
    if (!sentence.empty())
    {
        cout<<*it;
        ++it;
    }

    //write the rest of the words, each preceded by a space
    while (it!=sentence.end())
    {
        cout<<" "<<*it;
        ++it;
    }

    cout<<endl;
    return 0;
}

//*******************************************************************************************************
//Chapter 8 - Writing Generic functions
//whenever we've written a function so far, we've know the types of the function's paramaters & return value
//However, we used a library function called find, which takes two iterators and a value as arguments
//we can use the same find function to find values of any appropriate type in any kind of container
//THEREFORE, we do NOT know what find's argument or result types will be until we see it.
//Such a function is called a GENERIC FUNCTION. But how do we let someone know whether it will work with particular arguments?

///E.g. If a function has parameters x and y, and computes x+y, then the mere existence of that computation
//implicitly requires that x and y have types for which x+y is defined.

//By its' nature, generic function are abstract. If they were written to solve specific problems, then they
//wouldn't be abstract

//*******************************************************************************************************
//8.1.1. - MEDIANS OF UNKNOWN TYPE
//The language feature that implements generic functions is called template function
//Templates allows us to write a SINGLE definition for a family of functions-or types- that behave SIMILARLY
//,except for differences that we can attribute to the types of their template parameters

//Template parameters allow us to write programs in terms of common behavior, even though we do not
//know the specific types that correspond to the template paramaters when we define the template
//We DO know the types when we use a template and that knowledge is available when we compile and link our program

//e.g. before we created a function with the ability to calculate the median of a vector<double>
//but there is no reason to restrict the function to vector<double>. We can take the median of vectors of other types as well
//by using template functions

//says we're defining a template function and that the function will take a "type parameter"
//type paraemters are like function parameters. They define names that can be used within the scope of the function
//however, type parameters refer to types, not variables. Therfore, whenever T appears in the function, the implementation
//will assume that T names a type. When we call median, the implementation will bind T to a type determined during compilation
//E.g. say we call median(vi) where vi is a vector<int> object. The implementation INSTANTIATES our code
//as if we had written a specific version of median that took a vector<int> and returned an int

template <class T>
T median(vector<T> v)
{
    //typename is there to tell the implementation that vector<T>::size_type is the name of a type. (this is a MUST)
    //even though the implementation does not yet know what type T represents
    typedef typename vector<T>::size_type vec_sz;
    vec_sz size = v.size();
    if (size==0)
        throw domain_error("median of an empty vector");

    sort(v.begin(),v.end());
    vec_sz mid=size/2;

    //e.g. when evaluting true case, we have to know the type of v's elements in order to know the types of v[mid] and v[mid-1]
    //These types in turn, determine the type of the + and / operators
    return size % 2==0 ? (v[mid]+v[mid-1])/2 : v[mid];
}

//*******************************************************************************************************
//8.1.2 - Template instantiation
//When we call median on behalf of a vector<int>, the implementation will effectively create and compile an instance of the
//function that replaces every use of T by int
//if we also call median for a vector<double>, then the implemetnation will again infer the types from the call

//For C++ implementations that follow the traditional edit-compile-link mode, instantiation often happens not at compile
//time, but at link time


//If you write your own templates, most current implementations require that in order to instantiate a template, the definition of the
//template, not just the declaration, has to be accessible to the implementation. Generally, this requirement implies access to the
//source files that define the template, as well as the header file
//*******************************************************************************************************

//8.1.3. - Generic Functions and types
//Recall that the difficult part of designing and using templates is understanding the interaction between a template and the
//"appropriate types" that can be used within the template. One type dependency seen is in our definition of the template version
//of median. The types stored in the vectors that are passed to the median function must support addition and division, and these
//operations had better map to their NORMAL arithmetic meanings.

//Other type issues arise in the interactions between templates and type conversions. For example, when we called find
//to check whether students had done all their homework, we wrote

find(s.homework.begin(), s.homework.end(),0);
//in this case, homework is a vector<double> , but we told find to look for an int. But there is no consequence as we cam
//easily compare int and double values. But when we call accumulate...

accumulate(v.begin(),v.end(),0.0)
//we MUST use the double form, as the accumulate function uses the type of the third argument as the type of its accumulator

//When we called max
string::size_type maxlen=0;
maxlen = max(len, name.size());
//we noticed that it is ESSENTIAL that the type of len match exactly the type returned by name.size(), otherwise it won't compile
//Plausible implementation of the max function is shown below

template <class T>
T max(const T& left, const T& right)
{
    return left > right ? left : right;
}

//if we pass an int and a double, the impementation has no way to infer which argument to convert so that they are the same
//Therefore, passing an int and a double will FAIL at compile time

//*******************************************************************************************************
//8.2 - Data Structure Independence
//The median function implemented above generalizes across types that a vector may contain
//but we may want the function to deal with values stored in ANY kind of data structure, like a list or a string
//ALSO, we would like to be able to act on part of a container as opposed to having to use the whole container
//--For example ,the standard library uses iterators to allow us to call find on any contigious part of any container

//find(c.begin(),c.end(),val);

//why are we not allowed to say c.find(val) though?
//this would meann that we're calling find as a member of whatever type c has and that the type of c would have to define
//find as a member.

//A subtle reason for generic functions to take iterator arguments instead of container arguments directly is that it's
//possible for iterators to access elemetns that aren't in the container at all, in the ordinary sense
//E.g. rbegin function yields an iterator that grants access to the passed container's elments in reverse order
//*******************************************************************************************************
//8.2.1 - Algorithms and Iterators
/*
The implementation of the more popular standard-library functions all include iterators
Some containers support operations that others do not. This support translates into operations
that some iterators support and others do not. For example, it is possible to access
an element with a given index directly in a vector, but not in a list.
Accordingly, if we have an iterator that refers to another element of that same vector, the design of the iterator
makes it possible to obtain the iterator of that element by simply adding the difference between the elments' indices

ALL ITERATORS USE THE ++ operator to refer to the next element of its container

-Library defines FIVE ITERATOR CATEGORIES, each corresponding to a specific collection of iterator operations
-Each standard library algorithm SAYS what category it expects for each iterator arguments
*/

//*******************************************************************************************************
//8.2.2 - Sequential read-only access
//implement find. Result is either first iterator iter, whose corresponding element is x (*iter==x) or end if no such iterator exists

template <class In, class X>
In find(In begin, IN end, const X&x)
{
    while (begin!=end && *begin!=x)
        ++begin;
    return begin;
}


//alternative implementation of find
template <class In, class X> In find(In begin, In end, const X&x)
{
    if (begin==end||*begin==x)
        return begin;
    begin++;
    return find(begin,end,x);
}

//CONCLUSION - an iterator that offers sequential read-only access to elements of a sequence
//should support ++ (both prefix and postfix), ==, !=, and unary *
//There is one operator that such an iterator ought to support and that is ->, (e.g. iter->member equals (*iter).member)
//if a type supports all these operations, it is called an INPUT ITERATOR

//*******************************************************************************************************
//8.2.3 - Sequential write-only access
//Use iterators to write elements of a sequence - Example (copy function)
//PROGRAM STARTS HERE

template<class In, class Out>
Out copy(In begin, In end, Out dest)
{
    while (begin!=end)
        *dest++ = *begin++; //corresponds to *dest = *begin; ++dest; ++begin;
    return dest;
}

//the function takes three iterators, the first two denote the sequence from which to copy
//and the third denotes the beginning of the destination sequence.
//The function operates by advancing being through the container until it reaches end, copying each
//element into dest as it goes

//Must be able to evaluate *dest=value and dest++. Also, if it is an iterator, then


*it=x;
++it;
++it;
*it=y;

//This is problematic because there is a space in the output sequence and if we wish to use an iterator exculsively for output,
//then there is an implicit requirement that we not execute ++it more than once between assignments
//If a function uses a type in a way that meets these requirements, we call it an OUTPUT ITERATOR


//*******************************************************************************************************
//8.2.4 - Sequential read-write access
//Suppose we want to be able to read and write the elements of a sequence, but only sequentially
//Example of a library function that does so is replace, from the <algorithm> header
//within range beg to end, replace all instances of x with y

template <class For,class X>
void replace(For beg, For end, const X& x, const X& y)
{
    while (beg!=end)
    {
        if (*beg==x)
            *beg=y;
        ++beg;
    }
}

//FORWARD ITERATOR - and it must support
//*it(for both reading and writing)
//++it and it++ (but not --it or it--)
//it==j and it!=j (where j has the same type as it)
//it->member (as a synonym for (*it).member)


//*******************************************************************************************************
//8.2.5 - Reversible Access
//Some functions need to get at a container's elements in reverse order. The most straightforward
//example of such a function is reverse, which the standard library defines in the <algorithm> header

template <class Bi> void reverse (Bi begin, Bi end)
{
    while (begin!=end)
    {
        --end;
        if (begin!=end)
            swap(*begin++,*end); //equivalent to swap(*begin,*end); *begin++
    }
}

//in this algortihm we march (end), backward from the end of the vector and (beg) forward from the beginning
//exchanging elements as we go
//If a type meets all the requirements of a forward iterator AND it supports --, then it is a BIDIRECTIONAL ITERATOR

//*******************************************************************************************************
//8.2.6 - Random Access
// some functions need to be able to jump around in a container, such as the Binary search algortihm


template <class Ran, class X>
bool binary_search(Ran begin, Ran end, const&X x)
{
    while (begin<end)
    {
        //find the midpoint of the range
        Ran mid = begin + (end-begin)/2;
        //see which part of the range contains x; keep looking only in that part
        if (x<*mid)
            end = mid;
        else if (*mid < x)
            begin = mid+1;
        else
            return true; //this means *mid ==x
        
        
    }
    return false;
}

/*this function relies on ability to do arithmetic on iterators
If p and q are such iterators and n is an integer  then the list of requirements, beyond bidirectional iterators are shown below

p+n,p-n,n+p
p-q
p[n](equivalent to *(p+n))
p<q,p>q,p<=q,p>=q

Then it is a RANDOM ACCESS ITERATOR
//E.g. The sort function needs Random access iterators. The vector and string iterators are random-access iterators

*/

//*******************************************************************************************************
//8.2.7 - Iterator Ranges and off-the-end values
//The convention that algorithms take two arguments to specify ranges is universal
//first refers to the first element. second refers to one PAST the last element
//by doing this, we need only compare iterators for equality/inequaliy and do not need the notion
//of what it means for an iterator to be less than another.
//It also lets us indicate "out of range" and have loops of hte form


while (begin!=end)
{
//do something with the element to whcih begin refers
++begin;
}

//EVERY container type is required to support an off-the-end value for its iterators

//*******************************************************************************************************

//8.3- - Input and Output iterators
//input and output iterators are separate categories from forward iterators as not all iterators are
//associated with containers. For example, if c is a container that supports push_back, then
//back_inserter(c) is an output iterator that meets no other iterator requirements

//The standard library provides iterators that can be bound to input and output streams. (e.g. istream and ostream)
//For input streams, * will yield the value at the current position in the input
//and for output streams, * will let us write to the corresponding ostream

//the input stream iterator is an input-iterator type named istream_iterator
//PROGRAM STARTS HERE

vector<int> v;

//reads ints from the standard input and appends them to v
//second argument creates a default(empty) istream_iterator<int> which is not bound to any file
//any argument that reaches the eof or is in an error state will appear to be equal to the default value
copy(istream_iterator<int>(cin), istream_iterator<int>(),back_inserter(v));

// ** When we read from a stream, we always say the type of value that we expect to read

//for writing, we use the ostream_iterator
copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));


//*******************************************************************************************************
//8.4 - Using Iterators for flexibility
//can improve the split function by generalizing and not specifying input as vector<string>
//can also specfiy split to take an output iterator instead of returning a value.


template <class Out>
void split(const string& str, Out os)
{
    typedef string::const_iterator iter;
    iter i = str.begin();
    
    while (i!=str.end())
    {
        //ignore the leading blanks
        i = find_if(i,str.end(), not_space);
        
        //find the end of next word
        iter j = find_if(i,str.end(),space);
        
        //copy the characters in [i,j)
        if (i!= str.end())
            *os++ = string(i,j); //writes the word we just found and increments os
        
        i=j;
    }
}


//*******************************************************************************************************
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



//*******************************************************************************************************
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


//*******************************************************************************************************
//9.4 - The Student_info class

class Student_info{
public:
    std::string name() const {return n;}
    bool valid() const {return !homework.empty();}
    
    std::istream& read(std::istream&);
    double grade() const;

private:
    std::string n;
    double midterm, final;
    std::vector<double> homework;
};
            
bool compare(const Student_info&, const Student_info&);

istream& Student_info::read(istream& in)
{
    in>>name>>midterm>>final;
    read_hw(in,homework);
    return in;
}

double Student_info::grade() const
{
    return ::grade(midterm,final, homework);
}

//*******************************************************************************************************
//9.5 - Constructors

//Constructors are special member functions that define how objects are initialized
//will be synthesized by compile automatically if we do not define any. Constructors have the SAME NAME as the class itself

//1.If an object is of a class type that defines one or more constructors,
//then the appropriate constructor completely controls initialization of objects of that class
//2. If and object is of built-in type, then value-initializing it sets to zero and default initializing it gives it an undefined value
//3. Otherwise, the object can be only of a class type that does NOT define any constructors
//In that case, value- or default- initializing the object value or default initializes each of its data members. This initialization
//process will be recursive if any of the data members is of a class type with its own contructor

//So if we define a local Student_info variable, then the n and homework members will be automatically initialized to the empty string
//and vector respectively. as they are class objects with constructors

//We create two constructors: one that takes no arguments(creates empty Student_info object) and one that initializes it with a record stream


Student_info s;
Student_info s2(cin);

class Student_info {
public:
    Student_info();
    Student_info(std::istream&);
}

//DEFAULT CONSTRUCTOR - its' job is to ensure that its object's data members are properly initialized
//between the : and { are constructor initializers which tell the compiler to initialize the given members with the values in parentheses
//n and homework are implictly initialized
Student_info::Student_info(): midterm(0), final(0){}

//When we create a new class object
//1. The implementation allocates memory to hold the object
//2. It initializes the object using initial values as specified in the initializer list (and also those NOT specified in list)
//3. It executes the constructor body

//constructors exist to ensure that objects are created with their data members in a sensible state.

//constructor with arguments (has no explicit initializer so homework and n are initialized by the default constructor)
Student_info::Student_info(istream& is) {read(is);}


//*******************************************************************************************************
//9.6 - Using the Student_info class


int main()
{
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen=0;

    //read and store data
    while (record.read(cin))
    {
        maxlen = max(maxlen, record.name().size());
        students.push_back(record);
    }

    //alphabetize the student records
    sort(students.begin(), students.end(), compare);

    //write the names and grades
    for (vector<Student_info>::size_type i=0;
         i!=students.size(); ++i)
    {
        cout <<students[i].name() //this and the next line changed
        <<string(maxlen+1-students[i].name().size(),' ');
        
        try
        {
            double final_grade = students[i].grade();
            streamsize prec = cout.precision();
            cout << setprecision(3) <<final_grade;
            << setprecision(prec) <<end;
        }
        
        catch (domain_error e)
        {
            cout <<e.what() <<endl;
        }
        
        
    }
    return 0;
}
            
//*******************************************************************************************************
//CHAPTER 10
//*******************************************************************************************************

//10.1 - Pointers & Arrays
//an array is a kind of container, but less powerful than a vector
            
//10.1.2 - Pointers to Functions
//important to note that functions are not objects and there is no way to copy or assign them or to pass them
//as arguments directly.
//the only thing a program can do with a function is call it or take its address
            
//but we can still call a function  with another function as an argument but what happens is the compiler
//quietly translates such calls so as to use POINTERS TO FUNCTIONS instead of using functions directly

int *p;         // this declares that *p has type int and p is a pointer to an int
int (*fp)(int); //says that if we dereference fp and call it with an int argument, the result has type int
                //fp is a pointer to a function that takes an int argument and returns an int result

//create function whose type matches fp
int next(int n)
{
    return n+1;
}

//can now make fp point to next by using either of the following two statements
fp=&next;
fp=next;

//now define a new int variable called i  and use fp to call next and thereby increment i
            
int i=0;
i=(*fp)(i);
i=fp(i);
            
//note that if we write a function that looks like it takes another function as a parameter, the compiler translates
//parameter to a function instead.
//so the parameter written as double analysis(const vector<Student_info>&)
//is equivalently double (*analysis)(const vector<Student_info>&)


//this automatic translation does not apply to return values from functions.
//in the case that you want to write a function that returned a function pointer of the same type as the parameter to
//write_analysis, you must explicitly state the function returns a pointer.
//one method is to define a typedef to define analysis_fp as the name of the type of appropriate pointer
            
//typedef double (*analysis_fp)(const vector<Student_info>&);
            
    
            
            
            
            
            
            
            
            
            
            
            
